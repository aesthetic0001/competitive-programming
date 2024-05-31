#include <cstdio>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <tuple>

#define MAX 300000

using namespace std;

int A[MAX], B[MAX];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N; cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) cin >> B[i];

    // the problem reduces to whether or not the compressed array from B can be achieved from the initial array A
    // in this case, compression refers to grouping adjacents together
    //
    // value, start, end (inclusive)
    vector<tuple<int, int, int>> compressed;

    int start = 0;

    while (start < N) {
        int r = start;
        while (r <= N - 1 && B[start] == B[r]) ++r;
        compressed.emplace_back(B[start], start, r - 1);
        start = r;
    };

    int i = 0, j = 0;

    vector<pair<int, int>> left;
    vector<pair<int, int>> right;

    while (i < N && j < compressed.size()) {
        const auto [val, start, end] = compressed[j];
        if (A[i] == val) {
            if (i > start) {
                left.emplace_back(start, i);
            }
            if (i < end) {
                right.emplace_back(i, end);
            }
            ++j;
        }
        ++i;
    }

    // formed all of the compressed elements
    if (j == compressed.size()) {
        cout << "YES\n";

        cout << right.size() + left.size() << "\n";

        for (int i = right.size() - 1; i >= 0; i--) {
            cout << "R " << right[i].first << " " << right[i].second << "\n";
        }

        for (int i = 0; i < left.size(); i++) {
            cout << "L " << left[i].first << " " << left[i].second << "\n";
        }

    } else {
        cout << "NO\n";
    }

    return 0;
}
