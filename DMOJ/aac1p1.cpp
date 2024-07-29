#include <bits/stdc++.h>

using namespace std;

double S, R;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> S >> R;

    cout << (pow(S, 2) > 3.14 * pow(R, 2) ? "SQUARE" : "CIRCLE");

    return 0;
}
