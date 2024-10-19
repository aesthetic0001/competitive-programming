#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N;
bool active[4];
string blocks[4];
string perm = "";

bool recurse(string &target, int idx) {
  bool flag = false;

  for (int i = 0; i < 6; i++) 

  active[idx] = true;
  perm += ""

  for (int i = 0; i < 4; i++) {
    if (!active[i]) {
      flag = recurse(target, i) || flag;
    }
  }

  active[idx] = false;
  return flag;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin >> N;

    for (int i = 0; i < 4; i++) {
      string block; cin >> block;
      blocks[i] = block;
    }

    for (int i = 0; i < N; i++) {
      string s; cin >> s;
      for (int)
    }

    return 0;
}

