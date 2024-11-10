#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Function to check if a certain day count k satisfies the conditions
bool canSatisfyConditions(int k, const vector<int>& h, const vector<int>& a, const vector<int>& t) {
    int N = h.size();
    vector<pair<long long, int>> heights(N);

    // Calculate heights after k days
    for (int i = 0; i < N; ++i) {
        heights[i] = {h[i] + static_cast<long long>(a[i]) * k, i};
    }

    // Sort heights in ascending order
    sort(heights.begin(), heights.end());

    // Check if each plant i has exactly t[i] plants taller than it
    for (int i = 0; i < N; ++i) {
        if (t[heights[i].second] != N - 1 - i) {
            return false;
        }
    }
    return true;
}

int minDaysToSatisfyConditions(int N, const vector<int>& h, const vector<int>& a, const vector<int>& t) {
    long long left = 0, right = 1e9;
    int result = -1;

    // Binary search over days
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canSatisfyConditions(mid, h, a, t)) {
            result = mid;
            right = mid - 1; // Try to find a smaller k
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> h(N), a(N), t(N);

        for (int i = 0; i < N; ++i) cin >> h[i];
        for (int i = 0; i < N; ++i) cin >> a[i];
        for (int i = 0; i < N; ++i) cin >> t[i];

        int result = minDaysToSatisfyConditions(N, h, a, t);
        cout << result << endl;
    }

    return 0;
}

