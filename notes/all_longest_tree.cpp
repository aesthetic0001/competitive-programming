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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

vector<int> tree[7]={{},{2,3,4},{1,5,6},{1},{1},{2},{2}};
bool vis[7];
// maximum length
int maxlen_1[7];
int maxlen_2[7];

void visit(int node) {
  printf("vis %d\n",node);
  for(const auto adj:tree[node]){
    if(vis[adj])continue;
    vis[adj]=true;
    visit(adj);
    if()
    maxlen[node]=max(maxlen[node],maxlen[adj]+1);
  }
}

void get_lengths(int node) {

}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
vis[1]=true;
visit(1);
  for(int i=0;i<=6;i++){
    printf("%d: %d\n",i,maxlen[i]);
  }
  return 0;
}

