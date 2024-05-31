#include <iostream>
#include <cmath>

using namespace std;

int bessie[100];
int roads[100];

int main() {
    freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

    int N, M; cin >> N >> M;

    int ctr = 0;

    for (int i = 0; i < N; i++) {
        int d, s; cin >> d >> s;
        for (int j = 0; j < d; j++) {
            roads[ctr + j] = s;
        }
        ctr += d;
    }

    ctr = 0;

    for (int i = 0; i < M; i++) {
        int d, s; cin >> d >> s;
        for (int j = 0; j < d; j++) {
            bessie[ctr + j] = s;
        }
        ctr += d;
    }

    int ans = 0;

    for (int i = 0; i < 100; i++) {
        ans = max(ans, bessie[i] - roads[i]);
    }

    cout << ans;

    return 0;
}
