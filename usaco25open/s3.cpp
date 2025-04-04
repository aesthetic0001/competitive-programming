#include <bits/stdc++.h>
#include <cassert>
#include <tuple>

#define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clear(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

int highest[100001][11];int enjoy[100001];
multiset<int>running; int running_2;
// other, difficulty, enjoyment
vector<tuple<int,int,int>>g[100001];

void dfs(int node){
  enjoy[node]=running_2;
  auto iterator=running.rbegin();
  int it_counter = 0;
  for(int i=0;i<=10;i++){
    // check if iterator is actually valid
    // if not, then set the highest to 0
    if(iterator!=running.rend()) {
        int value = *iterator;
        highest[node][i]=value;
        if (it_counter == 0) {
            iterator++;
            it_counter = running.count(value);
        }
        it_counter--;
    } else {
        highest[node][i]=0;
    }
  }
  for(const auto &[a,b,c]:g[node]){
    running.emplace(b);
    running_2+=c;
    dfs(a);
    running_2-=c;
    running.extract(b);
  }
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
int n;cin>>n;
  for(int i=2;i<=n;i++){
    int a,b,c;cin>>a>>b>>c;
    g[a].emplace_back(forward_as_tuple(i,b,c));
  }
  dfs(1);
  // for (int i = 1; i <= n; i++) {
  //   cout << enjoy[i] << '\n';
  //   cout << highest[i][0] << '\n';
  // }

  // // maintain the (high, enjoyment) pair to find the maximum enjoyment for high at cj
  // set<PII>query[11];
  map<int,int> maxenjoy[11];
  for (int j = 0; j <= 10; j++) {
    for (int i = 1; i <= n; i++) {
        // printf("for %d at %d: highest is %d, enjoy is %d\n", i, j, highest[i][j], enjoy[i]);
      maxenjoy[j][highest[i][j]] = max(maxenjoy[j][highest[i][j]],enjoy[i]);
    }
    int highest = 0;
    for (const auto &[k,v]:maxenjoy[j]) {
        highest=max(v,highest);
        maxenjoy[j][k]=highest;
    }
  }



  // for (int i = 0; i <= 1; i++) {
  //   for (const auto &[a,b]:query[i]) {
  //     cout << a << ' ' << b << '\n';
  //   }
  // }

  int m;cin>>m;
  for(int i=0;i<m;i++){
      int skill,c; cin >> skill >> c;
    // auto it = query[c].upper_bound(mp(skill+1,INT64_MAX));
    auto it = maxenjoy[c].upper_bound(skill);
    it--;
    cout << it->second << '\n';
  }
  return 0;
}
