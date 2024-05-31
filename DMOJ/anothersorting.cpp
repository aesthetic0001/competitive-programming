#include <iostream>
#include <algorithm>

using namespace std;

inline bool comp(int a, int b) {
    return (a % 10) == (b % 10) ? a > b : a % 10 < b % 10;
}

int main() {
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v[i] = a;
	}

	sort(v.begin(), v.end(), comp);

	for (const auto &i : v) {
	   cout << i << " ";
	}

	return 0;
}
