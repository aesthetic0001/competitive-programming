#include <bits/stdc++.h>
#ifdef fread_unlocked
#define fread fread_unlocked
#endif
#define INPUT_SIZE (4<<20)
int _i0=0;
char _i[INPUT_SIZE+5];
#define su(x) do{while((_=_i[_i0++])<48);for(x=_-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si(x) do{while((_n=_i[_i0++])<45);if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
#define su2(x) do{for(x=_i[_i0++]-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si2(x) do{_n=_i[_i0++];if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
char _,_n;

using namespace std;
int N, M, temp1;
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    fread(_i,1,INPUT_SIZE,stdin);

    su2(N);

    int dp[N + 1];
    vector<int> adj[N + 1];

    for (int i = 1; i <= N; i++) {
        dp[i] = INT32_MAX;
    }

    for (int i = 1; i <= N; i++) {
        su(M);
        for (int j = 0; j < M; j++) {
            su(temp1);
            adj[i].emplace_back(temp1);
        }
    }

    dp[1] = 1;

    q.emplace(1);

    int ans = INT32_MAX;

    while (!q.empty()) {
        const int top = q.front(); q.pop();

        if (adj[top].size() == 0) {
            ans = min(dp[top], ans);
        }

        for (const auto &neighbor : adj[top]) {
            if (dp[top] + 1 < dp[neighbor]) {
                dp[neighbor] = dp[top] + 1;
                q.emplace(neighbor);
            }
        }
    }


    bool possib = true;

    for (int i = 1; i <= N; i++) {
        if (dp[i] == INT32_MAX) {
            possib = false;
            break;
        }
    }

    cout << (possib ? 'Y' : 'N') << '\n';
    cout << ans;

    return 0;
}
