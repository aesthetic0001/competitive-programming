#include <bits/stdc++.h>
#include <cstdlib>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int grid[9][9], dis[9][9];
int Sx, Sy, Ex, Ey;
queue<pair<int, int>> q;

vector<int> off1 = {-2, 2};
vector<int> off2 = {-1, 1};

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      dis[i][j] = INT32_MAX;
    }
  }

scanf("%d %d", &Sx, &Sy);
  scanf("%d %d", &Ex, &Ey);

  q.emplace(make_pair(Sx, Sy));
  dis[Sx][Sy] = 0;
  
  while (!q.empty()) {
    // left right moves
    const auto [x, y] = q.front(); q.pop();

    for (const int dx : off1) {
      for (const int dy : off2) {
        int newX = dx + x, newY = dy + y;
        if (newX <= 8 && newX >= 1 && newY <= 8 && newY >= 1 && dis[newX][newY] > dis[x][y] + 1) {
          q.emplace(make_pair(newX, newY));
          dis[newX][newY] = dis[x][y] + 1;
        }
      }
    }

    for (const int dy : off1) {
      for (const int dx : off2) {
        int newX = dx + x, newY = dy + y;
        if (newX <= 8 && newX >= 1 && newY <= 8 && newY >= 1 && dis[newX][newY] > dis[x][y] + 1) {
          q.emplace(make_pair(newX, newY));
          dis[newX][newY] = dis[x][y] + 1;
        }
      }
    }

  }

  printf("%d", dis[Ex][Ey]);



    return 0;
}

