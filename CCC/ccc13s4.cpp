#include <bits/stdc++.h>
#include <cstdio>

// if segfaults, try using cstdio (scanf and print) because the buffered input may be tweaking

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif
#define INPUT_SIZE (4<<20)
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

int N, M, temp1, temp2;
vector<int> adj[100001];
bool vis1[100001], vis2[100001];
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    // fread(_i,1,INPUT_SIZE,stdin);

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &temp1, &temp2);
        adj[temp2].eb(temp1);
    }

    scanf("%d %d", &temp1, &temp2);

    vis1[temp1] = true;
    vis2[temp2] = true;

    q.em(temp1);

    while (!q.empty()) {
        const int top = q.front(); q.pop();

        for (const auto &other : adj[top]) {
            if (!vis1[other]) {
                vis1[other] = true;
                q.em(other);
            }
        }
    }

    if (vis1[temp2]) {
        printf("no");
        return 0;
    }

    q.em(temp2);

    while (!q.empty()) {
        const int top = q.front(); q.pop();

        for (const auto &other : adj[top]) {
            if (!vis2[other]) {
                vis2[other] = true;
                q.em(other);
            }
        }
    }

    if (vis2[temp1]) {
        printf("yes");
        return 0;
    }

    printf("unknown");

    return 0;
}
