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
int uses_branch[7];
int maxlen_1[7];
int maxlen_2[7];
int parent[7];

void visit(int node) {
  printf("vis %d\n",node);
  for(const auto adj:tree[node]){
    if(vis[adj])continue;
    parent[adj]=node;
    vis[adj]=true;
    visit(adj);
    // can use maxlen_1 as its parent
    if(maxlen_1[adj]+1>maxlen_1[node]){
      uses_branch[node]=adj;
      maxlen_2[node]=maxlen_1[node];
      maxlen_1[node]=maxlen_1[adj]+1;
    }else if(maxlen_1[adj]+1==maxlen_1[node]||maxlen_1[adj]+1>maxlen_2[node]){
      maxlen_2[node]=maxlen_1[adj]+1;
    }
  }
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
vis[1]=true;
uses_branch[1]=1;
parent[1]=0;
visit(1);
  for(int i=1;i<=6;i++){
    int max_dist = maxlen_1[i];
    // there are two types of paths: path through parent, and path through longest child
    if (uses_branch[parent[i]]!=i){
        // parent does not use this node as part of maxlen, so we can use
        max_dist=max(max_dist,maxlen_1[parent[i]]+1);
    }
    // if parent shortest path (maxlen_1) goes through us: pick the alternative path (maxlen_2)
    max_dist=max(max_dist,maxlen_2[parent[i]]+1);
    printf("%d: %d\n",i,max_dist);
  }
  return 0;
}

