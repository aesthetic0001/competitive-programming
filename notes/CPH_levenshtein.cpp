#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clear(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

string source = "LOVE", target = "MOVIE";
// min edits to make substrings of the two strings equal
int dist[5][6];

inline int check(int i, int j){
  if(source[i-1] != target[j-1]){
    return 1;
  }
  return 0;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif

  for(int i=0;i<=source.size();i++){
    for(int j=0;j<=target.size();j++){
      dist[i][j]=INT32_MAX;
    }
  }

  dist[0][0]=0;

  for (int i=0;i<=source.size();i++){
    for (int j=0;j<=target.size();j++){
      if(i != 0) {
        // we can make it equal by adding the needed character
        dist[i][j]=min(dist[i-1][j]+1,dist[i][j]);
      }
      if(j != 0) {
        // we can make it equal by disregarding the current character at target[j-2]
        dist[i][j]=min(dist[i][j-1]+1,dist[i][j]);
      }
      if(i != 0 && j != 0) {
        // in the case that they are the same value, we can disregard the above operations and try to perform a modify operation
        dist[i][j]=min(dist[i-1][j-1]+check(i,j),dist[i][j]);
      }
      printf("%d ",dist[i][j]);
    }
    printf("\n");
  }

  return 0;
}

