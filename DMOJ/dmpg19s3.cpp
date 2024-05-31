#include <stack>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

#define int long long
#define MOD 1000000007
#define MAX 1000001

int diff[MAX];

using namespace std;

// try using non-recursive modular exponentiation
inline int modPow(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int res = 1;

    while (b > 1) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        b = floor(b / 2);
    }

    res = (res * a) % MOD;

    return res;
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    int N; int ctr = 0;
    cin >> N;

    // up to index n
    for (int i = 0; i <= N; i++) {
        diff[i] = 1;
    }

    // given ( A 1 ( B 1 ) 2 ) 3
    // n would be 5
    // diff array would look like:
    // [1, 1, 1, 1, 1, 1]
    // [1, 3, 2, 1, 1/2, 1/3]
    // computes to [1, 3, 6, 1, 3, 1]

    // pair of idx, element
    vector<pair<int, pair<string, int> > > elements;
    stack<int> start;
    map<string, int> ans;

    while (ctr < N) {
        string in;
        cin >> in;

        if (in == "(") {
            start.push(ctr);
        } else if (in == ")") {
            int mult;
            cin >> mult;
            mult = mult % MOD;

            const int l = start.top();
            start.pop();

            diff[l] = (diff[l] * mult) % MOD;
            diff[ctr + 1] = (diff[ctr + 1] * modPow(mult, MOD - 2)) % MOD;
        } else {
            int ct;
            cin >> ct;
            elements.emplace_back(ctr, make_pair(in, ct % MOD));
        }
        ++ctr;
    }

    // compute difference array
    for (int i = 1; i < N; i++) {
        diff[i] = (diff[i] * diff[i - 1]) % MOD;
    }

    for (const auto &[idx, element] : elements) {
        ans[element.first] += (element.second * diff[idx]) % MOD;
        ans[element.first] = ans[element.first] % MOD;
    }

    for (const auto &[elName, ct] : ans) {
        cout << elName << " " << ct << "\n";
    }

    return 0;
}
