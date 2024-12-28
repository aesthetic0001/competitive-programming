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
    int sL=psa[ub]-psa[l-1],sR=psa[r]-psa[lb-1];
    int cUB=cakes[ub],cLB=cakes[lb];
    while(true){
      int cL=cakes[l],cR=cakes[r];
      int sum=cUB+cLB;
      printf("sL:%d,sR:%d\n",sL,sR);
      if(sL-cUB>=sR-cLB){
        // elsie will take from the left then, we want to balance to the right
        printf("sl>sr: elsie will take left\n");
        e+=cL;
        sL-=cL;
        sL+=cLB;
        sR-=cLB;
        cLB=sum;

        ub--;
        cUB=cakes[ub];
        l++;
        printf("took %d | cLB: %d, cUB: %d, sL: %d, sR:%d\n",cL,cLB,cUB,sL,sR);
        // printf("took %d, now cUB points to %d\n",cL,ub);
     }else{
        printf("sr>sl: elsie will take right\n");
        e+=cR;
        sR-=cR+cUB;
        cLB=sum;
        sL+=cUB;

        lb++;
        cLB=cakes[lb];
        r--;
        printf("took %d | cLB: %d, cUB: %d, sL: %d, sR:%d\n",cL,cLB,cUB,sL,sR);
        // printf("took %d, now cLB points to %d\n",cL,lb);
     }
      if(r-l+1==2)break;
    }
    printf("%d %d\n",psa[N]-e,e);
  }
  return 0;
}

