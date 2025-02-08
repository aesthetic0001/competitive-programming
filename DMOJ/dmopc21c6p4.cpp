#include <bits/stdc++.h>
#include <cassert>
#include <tuple>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clr(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

int n,m,a,b,c,d;
// bounded by vertex number
vector<PII> houses[200001];
int dis[200001][4];
tuple<int,int,int> previous[200001][4];

// bounded by index
bool reserved[200000];
bool color[200000];

queue<PII>q;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&m);

  for(int i=0;i<m;i++){
    int u,v;scanf("%d %d",&u,&v);
    houses[u].eb(mp(v,i));
    houses[v].eb(mp(u,i));
  }

  for(int i=0;i<200001;i++){
    for(int j=0;j<4;j++){
      dis[i][j]=INT32_MAX;
    }
  }

  scanf("%d %d %d %d",&a,&b,&c,&d);

  q.emplace(mp(a,0));
  dis[a][0]=0;

  while(!q.empty()){
    const auto [top,state]=q.front();q.pop();
    for(const auto &[adj,idx]:houses[top]){
      int k=state;
      if(state==1&&adj==c)continue;
      if(state==2&&adj==d)continue;
      if(state==3&&(adj==c||adj==d))continue;
      if(adj==c){
        k+=1;
      }
      if(adj==d){
        k+=2;
      }
      if(state>=4)continue;
      if(dis[adj][k]>dis[top][state]+1){
        dis[adj][k]=dis[top][state]+1;
        previous[adj][k]=forward_as_tuple(top,state,idx);
        q.emplace(mp(adj,k));
      }
    }
  }

  int ans=INT32_MAX;
  int state=-1;

  for(int i=0;i<=2;i++){
    if(ans>dis[b][i]){
      ans=dis[b][i];
      state=i;
    }
  }

  if(state==-1){
    printf("-1\n");
    return 0;
  }

  for(const auto &[adj,idx]:houses[c]){
    if(adj==d){
      printf("-1\n");
      return 0;
    }
  }

  printf("2\n");

  vector<int> pathEdges;
  int curTop = b, curState = state;

  while (curTop != a) {
      const auto &[top, prevState, idx] = previous[curTop][curState];
      pathEdges.eb(idx);
      curTop = top;
      curState = prevState;
  }

  reverse(pathEdges.begin(), pathEdges.end());

  for (int idx : pathEdges) {
      reserved[idx] = true;
  }

  assert(pathEdges.size()==ans);

  // go through adj of both c and d. there is guaranteed to be one on either side which is available for coloring
  bool c_ok=true;
  for (const auto &[adj,idx]:houses[c]){
    if(reserved[idx])c_ok=false;
  }

  if(c_ok){
    for (const auto &[adj,idx]:houses[c]){
      color[idx]=true;
    }
  }else{
    for (const auto &[adj,idx]:houses[d]){
      color[idx]=true;
    }
  }

  for(int i=0;i<m;i++){
    printf("%d\n",color[i]?2:1);
  }
  return 0;
}

