#include <bits/stdc++.h>
#define int long long

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int MAXW, MAXH; vector<vector<int>> v;

inline int euclidean(vector<int> &a, vector<int> &b) {
    int ans = 0;

}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> MAXW >> MAXH;

    // max of N choose 3, so 10586800

    for (int i = 0; i < MAXW - 2; i++) {
        for (int j = i + 1; j < MAXW; j++) {
            for (int k = j + 1; k < MAXW; k++) {
                cout << i << j << k << "\n";
            }
        }
    }

    return 0;
}
