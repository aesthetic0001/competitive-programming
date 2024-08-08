#include <algorithm>
#include <bits/stdc++.h>
#include <functional>

using namespace std;

int A, B, N;

int possib[7001];
bool explored[7001];
vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int explore(int idx) {
    if (explored[idx]) return possib[idx];
    const int curDist = motels[idx];
    if (curDist == 7000) return 1;
    int curIdx = idx + 1;
    while (curIdx < motels.size() && motels[curIdx] - curDist <= B) {
        if (motels[curIdx] - curDist >= A) {
            possib[motels[curIdx]] = explore(curIdx);
            possib[idx] += possib[motels[curIdx]];
        }
        curIdx++;
    }
    explored[idx] = true;
    return possib[idx];
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> A >> B >> N;

    int m;

    for (int i = 0; i < N; i++) {
        cin >> m; motels.emplace_back(m);
    }

    sort(motels.begin(), motels.end(), less<int>());

    explore(0);

    cout << possib[0] << '\n';

    // for (const auto &v : motels) {
    //     cout << v << ": " << possib[v] << "\n";
    // }

    return 0;
}
