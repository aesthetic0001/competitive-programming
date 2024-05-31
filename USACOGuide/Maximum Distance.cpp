#include <iostream>
#include <cmath>
#define ll long long

const int MAX = 5e3;

using namespace std;

pair<ll, ll> coords[MAX];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);

    int N; cin >> N; ll ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> coords[i].first;
    }

    for (int i = 0; i < N; i++) {
        cin >> coords[i].second;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            ans = max(ans, static_cast<ll>(pow(coords[i].first - coords[j].first, 2)) + static_cast<ll>(pow(coords[i].second - coords[j].second, 2)));
        }
    }

    cout << ans;

    return 0;
}
