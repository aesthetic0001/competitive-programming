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

  active[idx] = true;

  for (int i = 0; i < 6; i++) {
    perm += blocks[idx][i];
    flag = (perm == target) || flag;
    for (int other = 0; other < 4; other++) {
      if (active[other]) {
        continue;
      }
      /*printf("vis %d from %d\n", other, idx);*/
      flag = recurse(target, other) || flag;
      if (flag) {
        break;
      }
    }
    perm.erase(perm.length() - 1);
    if (flag) {
      break;
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
      bool flag = false;
      for (int j = 0; j < 4; j++) {
        flag = recurse(s, j) || flag;
        if (flag) {
          break;
        }
      }
      if (flag) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }

    return 0;
}

