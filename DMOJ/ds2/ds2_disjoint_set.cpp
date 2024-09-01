#include <bits/stdc++.h>
#include <cassert>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif
#define INPUT_SIZE (16<<20)
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

vector<int> ans;
int parent[100001], setSz[100001];

inline void mk(int v) {
    if (parent[v] != 0) return;
    parent[v] = v;
    setSz[v] = 1;
}

inline int qu(int v) {
    if (parent[v] == v) return v;
    parent[v] = qu(parent[v]);
    return parent[v];
}

// return can join (aka need to add to mst y/n)
inline bool jn(int a, int b) {
    int pA = qu(a); int pB = qu(b);

    if (pA == pB) return false;

    if (setSz[pA] > setSz[pB]) {
        swap(pA, pB);
    }

    parent[pA] = pB;
    setSz[pA] += setSz[pB];

    return true;
}

int N, M;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    fread(_i,1,INPUT_SIZE,stdin);

    su(N); su(M);

    for (int i = 1; i <= M; i++) {
      int u, v; su(u); su(v);
      mk(u); mk(v);
      if (jn(u, v)) {
          ans.eb(i);
      }
    }

    if (ans.size() != N - 1) {
        printf("Disconnected Graph");
        return 0;
    }

    for (const auto &v : ans) {
      printf("%d\n", v);
    }

    return 0;
}
