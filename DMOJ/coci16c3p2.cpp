#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#define PII pair<int, int>

using namespace std;

int n,m;
char grid[2000][2000];
bool vis[2000][2000];
PII offsets[2]={{0,1},{1,0}};
queue<vector<PII>>q;
string ans;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char c;scanf(" %c ",&c);
      grid[i][j]=c;
    }
  }
  vector<PII>a={{0,0}};
  q.emplace(a);
  ans+=grid[0][0];
  while(!q.empty()){
    auto v=q.front();q.pop();
    vector<PII>matched;
    int MIN=(int)'z'+1;
    for(auto &[x,y]:v){
      for(auto &[dx,dy]:offsets){
        int nx=x+dx,ny=y+dy;
        if(nx>=0&&nx<=n-1 && ny>=0&&ny<=m-1){
          if(MIN>(int)grid[nx][ny]){
            MIN=(int)grid[nx][ny];
          }
        }
      }
    }
    for(auto &[x,y]:v){
      for(auto &[dx,dy]:offsets){
        int nx=x+dx,ny=y+dy;
        if((int)grid[nx][ny]==MIN){
          if(vis[nx][ny])continue;
          vis[nx][ny]=true;
          matched.emplace_back(make_pair(nx,ny));
        }
      }
    }
    if(!matched.empty()){
      ans+=(char)MIN;
      q.emplace(matched);
    }
  }
  printf("%s",ans.c_str());
  return 0;
}
