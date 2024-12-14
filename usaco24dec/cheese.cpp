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

int N,Q;
int rX[1000][1000],rY[1000][1000],rZ[1000][1000];
int active=0;

void update(int x,int y,int z){
  rX[y][z]++;
  if(rX[y][z]==N)active++;
  rY[x][z]++;
  if(rY[x][z]==N)active++;
  rZ[x][y]++;
  if(rZ[x][y]==N)active++;
}

void dis(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("%d %d: %d\n",i,j,rY[i][j]);
    }
  }
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&N,&Q);
  while(Q--){
    int x,y,z;scanf("%d %d %d",&x,&y,&z);
    update(x,y,z);
    printf("%d\n",active);
    /*dis();*/
  }
  return 0;
}

