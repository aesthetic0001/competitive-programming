#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

// find the first true value
bool monotonic(int x, int n) {
  return pow(x, 2) >= n;
}

int bsearchSqrt(int n) {
  int idx = n;
  // this works, because the total area that needs to be covered is at most 2 jumps (the jump size is equal to half of the total search area)
  for (int jumpsz = n / 2; jumpsz >= 1; jumpsz /= 2) {
    printf("jumpsz: %d at %d\n", jumpsz, idx);
    while (idx - jumpsz <= n && monotonic(idx - jumpsz, n)) {
      idx -= jumpsz;
      printf("jumping to %d\n", idx);
    }
  }

  return idx;
}

signed main() {
    int k;

    scanf("%d", &k);

    printf("sqrt of %d is %d\n", k, bsearchSqrt(k));

    return 0;
}


