#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N;
vector<int> tree[500001];
int disA[500001], disB[500001], dis[500001];
queue<int> q;

inline int findFurthest(int node, int* disref) {
    for (int i = 1; i <= N; i++) {
        disref[i] = INT32_MAX;
    }

    int ans = node;
    disref[node] = 1;
    q.em(node);

    while (!q.empty()) {
        const int top = q.front(); q.pop();
        ans = top;
        for (const auto &v : tree[top]) {
            if (disref[top] + 1 < disref[v]) {
                disref[v] = disref[top] + 1;
                q.em(v);
            }
        }
    }

    return ans;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        tree[a].eb(b);
        tree[b].eb(a);
    }

    int ptA = findFurthest(1, dis);
    int ptB = findFurthest(ptA, disA);
    findFurthest(ptB, disB);

    for (int i = 1; i <= N; i++) {
        printf("%d\n", max(disA[i], disB[i]));
    }

    return 0;
}
