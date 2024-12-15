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
bool broken[100001];
int N,S,vs[100001],type[100001],ans=0;
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&N,&S);
  for(int i=1;i<=N;i++){
    int a,b;scanf("%d %d",&a,&b);
    type[i]=a;
    vs[i]=b;
  }
  // cI: idx before jump
  int cP=1,cI=S,ct=0,max=10000000,dir=1;
  while(cI>=1&&cI<=N&&ct<max){
    int v=vs[cI],tp=type[cI];
    /*printf("arrived at %d|power %d\n",cI,cP);*/
    if(tp==0){
      cP+=v;
      dir*=-1;
    }else{
      /*printf("target:%d\n",v);*/
      if(cP>=v&&!broken[cI]){
        broken[cI]=true;
        ans++;
      }
    }
    cI+=cP*dir;
    ct++;
  }
  printf("%d",ans);
  return 0;
}

