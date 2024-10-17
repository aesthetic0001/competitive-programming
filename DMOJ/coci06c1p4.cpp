#include <bits/stdc++.h>
#include <cstdio>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;
int R, C, traverseTime[52][52], floodTime[52][52];
PII target;
bool grid[52][52];
queue<PII> floodLocations, visLocations;
vector<PII> offsets = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    
    for (int i = 0; i <= 51; i++) {
      for (int j = 0; j <= 51; j++) {
        traverseTime[i][j] = INT32_MAX;
        floodTime[i][j] = INT32_MAX;
      }
    }

    scanf("%d %d", &R, &C);

    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        char c;
        scanf(" %c", &c);
        // printf("%d %d %c\n", i, j, c);
        switch (c) {
          case 'D': {
            target.first = i;
            target.second = j;
            grid[i][j] = true;
            break;
          }
          case '.': {
            grid[i][j] = true;
            break;
          }
          case '*': {
            floodTime[i][j] = 0;
            floodLocations.emplace(make_pair(i, j));
            break;
          }
          case 'S': {
            traverseTime[i][j] = 0;
            visLocations.emplace(make_pair(i, j));
            break;
          }
        }
      }
    }

    // do the floodlocations fill first
    while (!floodLocations.empty()) {
      const auto [x, y] = floodLocations.front(); floodLocations.pop();
      /*printf("floodloc %d %d: %d\n", x, y, floodTime[x][y]);*/
      for (const auto &[dx, dy] : offsets) {
        if (!(x + dx == target.first && y + dy == target.second) && grid[x + dx][y + dy] && floodTime[x + dx][y + dy] > floodTime[x][y] + 1) {
          floodLocations.emplace(make_pair(x + dx, y + dy));
          floodTime[x + dx][y + dy] = floodTime[x][y] + 1;
        }
      }
    }

    while (!visLocations.empty()) {
      const auto [x, y] = visLocations.front(); visLocations.pop();

      /*printf("visloc: %d %d: %d\n", x, y, traverseTime[x][y]);*/

      for (const auto &[dx, dy] : offsets) {
        if (grid[x + dx][y + dy] && floodTime[x + dx][y + dy] > traverseTime[x][y] + 1 && traverseTime[x + dx][y + dy] > traverseTime[x][y] + 1) {
          visLocations.emplace(make_pair(x + dx, y + dy));
          traverseTime[x + dx][y + dy] = traverseTime[x][y] + 1;
        }
      }
    }

    if (traverseTime[target.first][target.second] == 2147483647) {
      printf("KAKTUS");
      return 0;
    }
    printf("%d", traverseTime[target.first][target.second]);

    return 0;
}

