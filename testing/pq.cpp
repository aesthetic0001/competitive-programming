#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> sigma = {1, 3, 5, 2};
    priority_queue<int, vector<int>, less<int>> pq;
    for (const auto &v : sigma) pq.push(v);

    while (!pq.empty()) {
        cout << pq.top(); pq.pop();
    }

    cout << "\n";

    sort(sigma.begin(), sigma.end(), greater<int>());

    for (const auto &v : sigma) cout << v;
}
