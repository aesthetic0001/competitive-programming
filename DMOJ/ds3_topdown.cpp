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

#define HALF (1<<17)
struct Node {int MIN;int GCD;int CNT;Node(int a,int b,int c){MIN=a;GCD=b;CNT=c;}Node()=default;};

Node seg[2*HALF+1];
int n,m;

#define l(idx) seg[(idx<<1)]
#define r(idx) seg[(idx<<1)+1]

inline void _comp(int idx){
  Node &left=l(idx), &right=r(idx), &cur=seg[idx];
  cur.MIN=min(left.MIN,right.MIN);
  cur.GCD=gcd(left.GCD,right.GCD);
  cur.CNT=0;
  if(cur.GCD==left.GCD){
    cur.CNT+=left.CNT;
  }
  if(cur.GCD==right.GCD){
    cur.CNT+=right.CNT;
  }
}

inline void update(int idx,int v){
  idx+=HALF;
  seg[idx].MIN=v;
  seg[idx].GCD=v;
  seg[idx].CNT=1;
  while(idx>>=1 >=1){
    _comp(idx);
  }
}

inline int M(int l,int r){
  l+=HALF;r+=HALF;
  int ans=seg[l].MIN;
  while(r>l){
    if((l&1)==1){
      ans=min(ans,seg[l].MIN);
      l++;
    }
    if((r&1)==0){
      ans=min(ans,seg[r].MIN);
      r--;
    }
    l>>=1;r>>=1;
  }
  return ans;
}

inline int G(int l,int r){
  l+=HALF;r+=HALF;
  int ans=seg[l].GCD;
  while(r>l){
    if((l&1)==1){
      ans=gcd(ans,seg[l].GCD);
      l++;
    }
    if((r&1)==0){
      ans=min(ans,seg[r].GCD);
      r--;
    }
    l>>=1;r>>=1;
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
      l++;
    }
    if((r&1)==0){
      if(seg[r].GCD==g){
        ans+=seg[r].CNT;
      }
      r--;
    }
    l>>=1;r>>=1;
  }
  return ans;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    int v;scanf("%d",&v);
    seg[i+HALF]=Node(v,v,1);
  }
  seg[HALF+n]=Node(INT32_MAX,seg[HALF+n-1].GCD,0);
  for(int i=(HALF+n-1)>>1;i>=1;i--){
    _comp(i);
  }
  while(m--){
    char c; scanf(" %c ",&c);
    int a,b;scanf("%d %d",&a,&b);
    if(c=='C'){
      update(a-1,b);
    }else{
      if(c=='M'){
        printf("%d\n",M(a-1,b-1));
      }else if(c=='G'){
        printf("%d\n",G(a-1,b-1));
      }else{
        printf("%d\n",Q(a-1,b-1));
      }
    }
  }
  return 0;
}

