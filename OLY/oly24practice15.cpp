#include <bits/stdc++.h>

#define int long long

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, a[1000001];
int a1 = 0, a2 = INT32_MAX;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    // logic: the max would be just the largest number. the binary & cannot produce a larger number, only less than or equal to highest number
    // for min, just keep doing bitwise and

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a1 = max(a1, a[i]);
        a2 = a2 & a[i];
    }

    cout << a1 << " " << a2;

    return 0;
}
