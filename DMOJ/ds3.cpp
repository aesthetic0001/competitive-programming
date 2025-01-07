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
int pwr = 18;
int half=1<<17;
// 2^18

// min, gcd, count
struct Vertex {
  int minimum;
  int greatest_cd;
  int gcd_ct;
  Vertex(int a,int b,int c) {
    minimum=a;greatest_cd=b;gcd_ct=c;
  };
  Vertex() = default;
};

Vertex st[(1<<18)+1];
int N,M;

// gcd of parent node will be subset of gcd of children nodes
// this implies there will only ever be 

void merge(int idx){
  Vertex &l = st[2*idx];
  Vertex &r = st[2*idx+1];
  st[idx].minimum=min(l.minimum,r.minimum);
  st[idx].greatest_cd=gcd(l.greatest_cd,r.greatest_cd);
  st[idx].gcd_ct=0;
  if(l.greatest_cd == r.greatest_cd){
    // gcd in this range is equal
    st[idx].gcd_ct=l.gcd_ct+r.gcd_ct;
  }else{
    if(st[idx].greatest_cd==l.greatest_cd){
      /*printf("swapped cd: left (%d)\n",l.gcd_ct);*/
      st[idx].gcd_ct=l.gcd_ct;
    }
    if(st[idx].greatest_cd==r.greatest_cd){
      /*printf("swapped cd: right (%d)\n",r.gcd_ct);*/
      st[idx].gcd_ct=r.gcd_ct;
    }
  }
}

Vertex query(int original_l,int original_r) {
  int l=original_l+half;
  int r=original_r+half;
  Vertex res(INT32_MAX,st[l].greatest_cd,0);
  while(r>=l){
    if(l%2==1){
      res.minimum=min(st[l].minimum,res.minimum);
      res.greatest_cd=gcd(st[l].greatest_cd,res.greatest_cd);
      l++;
    }
    if(r%2==0){
      res.minimum=min(st[r].minimum,res.minimum);
      res.greatest_cd=gcd(st[r].greatest_cd,res.greatest_cd);
      r--;
    }
    l/=2;
    r/=2;
  }
  l=original_l+half;
  r=original_r+half;
  while(r>=l){
    if(l%2==1){
      if(res.greatest_cd==st[l].greatest_cd){
        res.gcd_ct+=st[l].gcd_ct;
      }
      l++;
    }
    if(r%2==0){
       if(res.greatest_cd==st[r].greatest_cd){
        res.gcd_ct+=st[r].gcd_ct;
      }
      r--;
    }
    l/=2;
    r/=2;
  }
  return res;
}

void update(int i,int v){
  i+=half;
  st[i].minimum=v;
  st[i].greatest_cd=v;
  i/=2;
  while(i>0){
    merge(i);
    i/=2;
  }
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&N,&M);
  for(int i=0;i<=half;i++){
    int idx = half+i;
    /*printf("%d\n",idx);*/
    if(i>=N){
      st[idx].minimum=INT32_MAX;
      st[idx].greatest_cd=st[half+1-N].greatest_cd;
      st[idx].gcd_ct=0;
      continue;
    }
    int a;scanf("%d",&a);
    st[idx].minimum=a;
    st[idx].greatest_cd=a;
    st[idx].gcd_ct=1;
  }

  for(int l=2;l<=(1<<(pwr-1));l*=2){
    for(int i=(1<<(pwr-1))/l;i<(1<<pwr)/l;i++){
      merge(i);
    }
  }

  while(M--){
    char c; scanf(" %c ",&c);
    int a,b;scanf("%d %d",&a,&b);
    if(c=='C'){
      update(a-1,b);
    }else{
      Vertex ans = query(a-1,b-1);
      if(c=='M'){
        printf("%d\n",ans.minimum);
      }else if(c=='G'){
        printf("%d\n",ans.greatest_cd);
      }else{
        printf("%d\n",ans.gcd_ct);
      }
    }
  }
  return 0;
}
