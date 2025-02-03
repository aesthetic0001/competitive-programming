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

// double sided vertex
vector<int> t[8] = {{},{2,3,4},{1,5,6},{1},{1,4,7},{2},{6},{4}};
bool vis[8];
int diameter;

int traverse(int node) {
  printf("vis %d\n",node);
  int first=0,second=0;
  for(const auto &adj : t[node]){
    if(vis[adj])continue;
    vis[adj]=true;
    int res = traverse(adj) + 1;
    if(res>first){
      second=first;
      first=res;
    }else if(res==first||res>second){
      second=res;
    }
  }
  diameter=max(diameter,first+second);
  return first;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
traverse(3);
  printf("%d\n",diameter);
  return 0;
}

