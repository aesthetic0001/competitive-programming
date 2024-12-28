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
int T,N,cakes[500001],psa[500001];
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d",&T);
  while(T--){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;i++){
      scanf("%d",&cakes[i]);
      psa[i]=cakes[i];
    }
    for(int i=1;i<=N;i++){
      psa[i]=psa[i-1]+psa[i];
    }
    int l=1,r=N,e=0;
    int ub=(l+r)/2,lb=ub+1;
    int sumL=psa[ub]-psa[l-1],sumR=psa[r]-psa[lb-1];
    int midLeft=cakes[ub],midRight=cakes[lb];
    while(true){
      int cakeL=cakes[l],cakeR=cakes[r];
      printf("sL:%d,sR:%d\n",sumL,sumR);

      if(sumL-midLeft==sumR-midRight){
        sumL-=midLeft;
        sumR-=midRight;
        int mp=midLeft+midRight;
        // pick right side arbritrarily
        e+=cakeR;
        sumR+=mp;
        ub--;
        midLeft=cakes[ub];
        midRight=mp;
        r--;
      }else if(sumL>=sumR){
        // merge to right to keep it
        sumL-=midLeft;
        if(sumL>=sumR){
            // elsie will take the right side

        }else{
            // elsie will take the left side

        }
      }else{
        // merge to left
        sumR-=midRight;
      }

      if(r-l+1==2)break;
    }
    printf("%d %d\n",psa[N]-e,e);
  }
  return 0;
}
