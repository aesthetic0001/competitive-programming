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

/**
 * There are two types of longest paths in such a problem:
 * You can either go through the parent node. In such a case, you can take its longest path which does not pass through the current node
 * You can also pass through the longest child node
**/

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

vector<int> tree[7]={{},{2,3,4},{1,5,6},{1},{1},{2},{2}};
bool vis[7];
int uses_branch[7];
int maxlen_1[7];
int maxlen_2[7];

void visit(int node) {
  for(const auto adj:tree[node]){
    if(vis[adj])continue;
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

void dp(int node){
  printf("vis %d\n",node);
  for(const auto adj:tree[node]){
    if(vis[adj])continue;
    vis[adj]=true;
    int highest_p;
    // cannot use maxlen_1 as its parent
    if(uses_branch[node]==adj){
      highest_p=maxlen_2[node]+1;
    }else{
      highest_p=maxlen_1[node]+1;
    }

    // if its equal, we would want to overwrite it to guarantee a high len.
    if(highest_p>=maxlen_1[adj]){
      // will not affect any children nodes, so we can just replace the parent directly. we do not have to worry about an invalid maxlen_2 overriding this value
      maxlen_1[adj]=highest_p;
      uses_branch[adj]=node;
    }else if(highest_p>maxlen_2[adj]){
      // same reasoning as above, we would want to replace it
      maxlen_2[adj]=highest_p;
    }
    dp(adj);
  }
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  vis[1]=true;
  uses_branch[1]=1;
  visit(1);
  for(int i=0;i<=6;i++){
    vis[i]=false;
  }
  dp(1);
  for(int i=1;i<=6;i++){
    printf("%d: %d\n",i,maxlen_1[i]);
  }
  return 0;
}

