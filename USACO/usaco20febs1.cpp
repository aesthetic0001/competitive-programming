#include <bits/stdc++.h>
using namespace std;

int N, M, K, initial[100001], to[100001], ans[100001];
// disjoint set for cycle size counting
int p[100001], setsz[100001];
unordered_set<int> graphs;

void mk(int a) {
    // printf("made set %d\n", a);
    p[a] = a;
    setsz[a] = 1;
    graphs.emplace(a);
}

int qu(int a) {
    if (p[a] == a) return a;
    p[a] = qu(p[a]);
    return p[a];
}

void jn(int a, int b) {
    // printf("join %d %d\n", a, b);
    // for (int i = 1; i <= N; i++) {
    //     printf("v at %d: %d\n", i, p[i]);
    // }
    int pA = qu(a), pB = qu(b);

    if (pA == pB) {
        // printf("tried to join same parent sets: %d %d\n", a, b);
        return;
    }

    if (setsz[pB] > setsz[pA]) {
        swap(pA, pB);
    }

    // printf("values: %d %d\n", pA, pB);
    graphs.erase(pB);
    p[pB] = pA;
    setsz[pA] += setsz[pB];
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= N; i++) {
        initial[i] = i;
        mk(i);
    }


    for (int i = 0; i < M; i++) {
        int L, R;
        scanf("%d %d", &L, &R);

        // printf("iter #%d\n", i + 1);

        for (int j = L; j < L + floor((double)(R - L + 1) / (double)2); j++) {
            int newLeft = initial[R - (j - L)];
            int newRight = initial[j];

            // printf("swapping %d with %d\n", j, R - (j - L));

            initial[j] = newLeft;
            initial[R - (j - L)] = newRight;

            jn(j, R - (j - L));
        }
    }

    for (int i = 1; i <= N; i++) {
        // printf("%d goes to %d\n", initial[i], i);
        to[initial[i]] = i;
    }

    // this only goes through every single node once
    // maximum O(N + K MOD(200))
    for (const auto &p : graphs) {
        int offset = K % setsz[p];
        int startNode = p;

        for (int i = 0; i < offset; i++) {
            startNode = to[startNode];
        }

        // int temp = p;

        // for (int i = 0; i < setsz[p]; i++) {
        //     printf("%d ", temp);
        //     temp = to[temp];
        // }

        // printf("\n");

        // printf("%d: setsz %d | offset %d | start at %d\n", p, setsz[p], offset, startNode);

        int curNode = startNode;
        int ref = p;

        for (int i = 0; i < setsz[p]; i++) {
            ans[curNode] = ref;
            curNode = to[curNode];
            ref = to[ref];
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
