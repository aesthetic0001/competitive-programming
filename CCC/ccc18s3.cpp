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
int N,M,dis[100][100];
char oG[100][100],g[100][100];
vector<PII>cameras;
queue<PII>q;
vector<PII>offsets={{0,1},{0,-1},{1,0},{-1,0}};
unordered_map<char,PII>conveyors = {{'U',{-1,0}},{'D',{1,0}},{'L',{0,-1}},{'R',{0,1}}};
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  cin>>N>>M;
  for(int i=0;i<N;i++){
    string s;cin>>s;
    for(int j=0;j<M;j++){
      oG[i][j]=s[j];
      g[i][j]=s[j];
      dis[i][j]=INT32_MAX;
      if(s[j]=='C'){
        cameras.eb(mp(i,j));
      }
    }
  }
  for(const auto[cY,cX]:cameras){
    for(const auto[oY,oX]:offsets){
      int COY=oY,COX=oX;
      while(true){
        int nY=cY+COY,nX=cX+COX;
        if(nY<0||nY>N||nX<0||nX>M)break;
        char nC=g[nY][nX];
        if(nC=='W'||nC=='C')break;
        if(!conveyors.count(g[nY][nX]))g[nY][nX]='W';
        COY+=oY;
        COX+=oX;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(g[i][j]=='S'){
        q.emplace(mp(i,j));
        dis[i][j]=0;
      }
    }
  }
  while(!q.empty()){
    const auto[sY,sX]=q.front();q.pop();
    int cd=dis[sY][sX];
    if(conveyors.count(g[sY][sX])){
      PII &offset=conveyors[g[sY][sX]];
      int nY=sY+offset.first,nX=sX+offset.second;
      if(nY<0||nY>N||nX<0||nX>M)continue;
      char nC=g[nY][nX];
      if(nC=='W'||nC=='C')continue;
      if(dis[nY][nX]>cd){
        q.emplace(mp(nY,nX));
        dis[nY][nX]=cd;
      }
      continue;
    }
    for(const auto[oY,oX]:offsets){
      int nY=sY+oY,nX=sX+oX;
      if(nY<0||nY>N||nX<0||nX>M)continue;
      char ct=g[nY][nX];
      if(ct=='W'||ct=='C')continue;
      if(dis[nY][nX]>cd+1){
        q.emplace(mp(nY,nX));
        dis[nY][nX]=cd+1;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(oG[i][j]=='.'){
        if(dis[i][j]==INT32_MAX)printf("-1\n");
        else printf("%d\n",dis[i][j]);
      }
    }
  }
  return 0;
}

