#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, K;
    cin >> N >> K;

    int cows[N];
    int ans[K];

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        cows[i] = t;
    }

    // pair of time, farmer
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;

    for (int i = 0; i < K; i++) {
        pq.push(make_pair(cows[i], i));
        ans[i] = 0;
    }

    int curCow = K;

    // problem was here: i did not keep track of **all** events, hence although the time was correct, the possibilities
    // were not fully fledged-out answers because some combinations were not accounted for
    // key statement in the problem: the next cow may choose to be interviewed by any of the available farmers, according to her preference
    vector<vector<int> > concurrentFinishes;

    while (curCow < N) {
        const auto &[minTime, _] = pq.top();
        vector<int> poppedFarmers;

        while (pq.top().first == minTime) {
            const auto &[time, farmer] = pq.top();
            pq.pop();
            poppedFarmers.emplace_back(farmer);
            pq.push(make_pair(time + cows[curCow], farmer));
            ++curCow;
        }

        concurrentFinishes.emplace_back(poppedFarmers);
    }

    cout << pq.top().first << "\n";
    ans[pq.top().second] = 1;

    for (int i = concurrentFinishes.size() - 1; i >= 0; i--) {
        bool intersect = false;
        for (const int &j : concurrentFinishes[i]) {
            if (ans[j]) {
                intersect = true;
                break;
            }
        }
        if (intersect) {
            for (const int &j : concurrentFinishes[i]) {
                ans[j] = 1;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        cout << ans[i];
    }

    return 0;
}
