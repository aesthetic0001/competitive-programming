#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fast modular exponentiation: computes (base^exp) % mod in O(log exp)
ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    vector<ll> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    // Precompute W[i][j] = (a[i]^a[j] + a[j]^a[i]) % M for i<j and mirror
    vector<vector<ll>> W(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            ll pij = modpow(a[i], a[j], M);
            ll pji = modpow(a[j], a[i], M);
            W[i][j] = W[j][i] = (pij + pji) % M;
        }
    }

    // Prim's algorithm for maximum spanning tree
    vector<bool> inMST(N, false);
    vector<ll> best(N, LLONG_MIN);
    best[0] = 0;         // start from node 0
    ll total = 0;

    for(int it = 0; it < N; it++){
        // pick the outside node u with maximum best[u]
        int u = -1;
        for(int i = 0; i < N; i++){
            if (!inMST[i] && (u == -1 || best[i] > best[u])) {
                u = i;
            }
        }
        inMST[u] = true;
        total += best[u];  // best[0]=0 for the first pick

        // update neighbors
        for(int v = 0; v < N; v++){
            if (!inMST[v]) {
                best[v] = max(best[v], W[u][v]);
            }
        }
    }

    cout << total << "\n";
    return 0;
}
