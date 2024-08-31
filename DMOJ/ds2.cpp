#include <bits/stdc++.h>

// if segfaults, try using cstdio (scanf and print) because the buffered input may be tweaking

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif
#define INPUT_SIZE (4<<24)
int _i0=0;
char _i[INPUT_SIZE+5];
#define su(x) do{for(x=_i[_i0++]-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si(x) do{_n=_i[_i0++];if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
#define ss(x) do{int i=0; while((_=_i[_i0++])<=32); for(; _>32; _= _i[_i0++]) x[i++]=_; x[i]='\0';}while(0)
char _,_n;

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

// weight/edge#, to
vector<PII> graph[100001];
vector<int> ans;
priority_queue<PII, vector<PII>, greater<PII>> pq;
bool vis[100001];

int N, M;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    fread(_i,1,INPUT_SIZE,stdin);

    su(N); su(M);

    for (int i = 1; i <= M; i++) {
      int u, v; su(u); su(v);

      graph[u].emplace_back(i, v);
      graph[v].emplace_back(i, u);
    }

    pq.emplace(0, 1);

    while (!pq.empty() && ans.size() != N) {
      const auto [weight, top] = pq.top(); pq.pop();

      if (vis[top]) continue;

      vis[top] = true;

      ans.eb(weight);

      for (const auto &[weight, to] : graph[top]) {
        if (!vis[to]) {
          pq.emplace(weight, to);
        }
      }
    }

    if (ans.size() != N) {
        printf("Disconnected Graph");
        return 0;
    }

    for (const auto &v : ans) {
      if (v == 0) continue;
      printf("%d\n", v);
    }

    return 0;
}
