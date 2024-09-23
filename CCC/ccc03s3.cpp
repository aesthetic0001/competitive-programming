#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, X, Y;
bool grid[27][27];
queue<PII> q;
priority_queue<int, vector<int>, less<int>> ans;
vector<PII> off = {{1, 0},{-1, 0},{0, 1},{0, -1}};

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);
    scanf("%d", &X);
    scanf("%d", &Y);

    for (int i = 0; i < X; i++) {
      string s; cin >> s;
      for (int j = 0; j < Y; j++) {
        grid[i + 1][j + 1] = (s[j] == '.');
      }
    }

    for (int i = 1; i <= X; i++) {
      for (int j = 1; j <= Y; j++) {
        if (grid[i][j]) {
          int ct = 0;
          q.emplace(make_pair(i, j));
          grid[i][j] = false;
          while (!q.empty()) {
            const auto [x, y] = q.front(); q.pop();
            ct += 1;
            for (const auto &[dx, dy] : off) {
              if (grid[x + dx][y + dy]) {
                grid[x + dx][y + dy] = false;
                q.emplace(x + dx, y + dy);
              }
            }
          }
          ans.emplace(ct);
        }
      }
    }

    
    int ct = 0;

    while (!ans.empty()) {
      const int top = ans.top(); ans.pop();
      if (N >= top) {
        N -= top;
      } else {
        break;
      }
      ct += 1;
    }

    if (ct == 1) {
      printf("1 room, %d square metre(s) left over", N);
    } else {
      printf("%d rooms, %d square metre(s) left over", ct, N);
    }

    return 0;
}

