#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, l = 1, r = 0;
vector<int> seats;

// we want to find the first true value
bool bs(int mdist) {
  int people = M, seatidx = 0, prevseat = -1000000001;
  while (people > 0 && seatidx < seats.size()) {
    const auto &seat = seats[seatidx];
    // printf("%d %d\n", seat, seat - prevseat);
    if (seat - prevseat >= mdist) {
      // printf("putting person in seat %d\n", seat);
      people -= 1;
      prevseat = seat;
    }
    seatidx++;
  }
  // printf("result for %d: %d\n", mdist, people);
  return people == 0;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
      int temp; scanf("%d", &temp);
      seats.emplace_back(temp);
      r = max(r, temp);
    }

    sort(seats.begin(), seats.end());

    // printf("%d %d\n", l, r);

    while (r > l) {
      int mp = ceil(double(l + r)/2);
      if (bs(mp)) {
        l = mp;
      } else {
        r = mp - 1;
      }
    }

    printf("%d", l);

    return 0;
}

