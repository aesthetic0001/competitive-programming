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

#define HALF (1<<3)
struct Node {int MIN;int GCD;int CNT;};

Node seg[2*HALF+1];
int n,m;

#define l(idx) seg[2*idx]
#define r(idx) seg[2*idx+1]

inline void _comp(int idx){
  /*printf("comp: %d\n",idx);*/
  Node &left=l(idx), &right=r(idx), &cur=seg[idx];
  /*printf("%d\n",seg[idx].MIN);*/
  cur.MIN=min(left.MIN,right.MIN);
  cur.GCD=gcd(left.GCD,right.GCD);
  cur.CNT=0;
  if(cur.GCD==left.GCD){
    cur.CNT+=left.CNT;
  }
  if(cur.GCD==right.GCD){
    cur.CNT+=right.CNT;
  }
  /*printf("%d\n",seg[idx].MIN);*/
}

inline void update(int idx,int v){
  /*printf("upd: %d %d\n",idx,v);*/
  idx+=HALF;
  seg[idx].MIN=v;
  seg[idx].GCD=v;
  seg[idx].CNT=1;
  while(idx>>=1){
    _comp(idx);
  }
}

inline int M(int l,int r){
  l+=HALF;r+=HALF;
  int ans=seg[l].MIN;
  while(r>l){
    if((l&1)==1){
      ans=min(ans,seg[l].MIN);
      l=(l>>1)+1;
    }else l>>=1;
    if((r&1)==0){
      ans=min(ans,seg[r].MIN);
      r=(r>>1)-1;
    }else r>>=1;
  }
  return ans;
}

inline int G(int l,int r){
  l+=HALF;r+=HALF;
  int ans=gcd(seg[l].GCD,seg[r].GCD);
  while(r>l){
    if((l&1)==1){
      ans=gcd(ans,seg[l].GCD);
      l=(l>>1)+1;
    }else l>>=1;
    if((r&1)==0){
      ans=gcd(ans,seg[r].GCD);
      r=(r>>1)-1;
    }else r>>=1;
  }
  return ans;
}

inline int Q(int l,int r){
  int g=G(l,r);
  l+=HALF;r+=HALF;
  int ans=0;
  while(r>l){
    if((l&1)==1){
      if(seg[l].GCD==g){
        ans+=seg[l].CNT;
      }
      l=(l>>1)+1;
    }else l>>=1;
    if((r&1)==0){
      if(seg[r].GCD==g){
        ans+=seg[r].CNT;
      }
      r=(r>>1)-1;
    }else r>>=1;
  }
  return ans;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++){
    int v;scanf("%d",&v);
    seg[i+HALF]={v,v,1};
  }
  /*for(int i=0;i<=2*HALF;i++){*/
  /*  printf("%d ",i);*/
  /*}*/
  /*printf("\n");*/
  /*for(int i=0;i<=2*HALF;i++){*/
  /*  printf("%d ",seg[i].MIN);*/
  /*}*/
  /*printf("\n");*/
  for(int i=(HALF+n)/2;i>=1;i--){
    _comp(i);
  }
  /*for(int i=0;i<=2*HALF;i++){*/
  /*  printf("%d ",i);*/
  /*}*/
  /*printf("\n");*/
  /*for(int i=0;i<=2*HALF;i++){*/
  /*  printf("%d ",seg[i].GCD);*/
  /*}*/
  /*printf("\n");*/
  while(m--){
    char c; scanf(" %c ",&c);
    int a,b;scanf("%d %d",&a,&b);
    if(c=='C'){
      update(a,b);
  /*for(int i=0;i<=2*HALF;i++){*/
  /*  printf("%d ",seg[i].GCD);*/
  /*}*/
    }else{
      if(c=='M'){
        printf("%d\n",M(a,b));
      }else if(c=='G'){
        printf("%d\n",G(a,b));
      }else{
        printf("%d\n",Q(a,b));
      }
    }
  }
  return 0;
}

