#include <bits/stdc++.h>

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

using namespace std;
int T;

int get1s(int ct){
  int res = 0;
  for(int i=0;i<=ct;i++){
    res += pow(10, i);
  }
  return res;
}

int calc2(int num,int hp){
  int cp = 1;
  int ans=0;
  while (hp>=cp){
    int rnd=(get1s(hp)-get1s(cp-1))*4+pow(10,cp-1)*5;
    int rnu=rnd+pow(10,cp-1)*5-1;
    if(rnd>num){
      /*printf("%d>%d\n",rnd,num);*/
      break;
    }
    /*printf("%d %d %d\n",num,rnd,rnu);*/
    ans+=min(num-rnd+1,rnu-rnd+1);
    cp++;
  }
  return ans;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld",&T);
  // printf("%d",calc2(4567,1,1));
  for(int i=0;i<T;i++){
    int N;scanf("%lld",&N);
    int highest = floor(log10(N));
    int ans = 0;
    for(int i=1;i<=highest;i++){
      ans+=calc2(N,i);
    }
    printf("%lld\n",ans);
  }
  return 0;
}

