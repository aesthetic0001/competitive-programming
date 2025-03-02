#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & -i
#define clr(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

// sum fenwick
using namespace std;

int source_arr[5]={1,2,3,4,5};
int fenwick_arr[6];

int query(int i) {
  int ans=0;
  while(i>=1){
    ans+=fenwick_arr[i];
    i-=lsb(i);
  }
  return ans;
}

int query_range_inclusive(int l,int r){
  return query(r) - query(l-1);
}

void update(int i,int v){
  // update parents
  while(i<=5){
    fenwick_arr[i]+=v;
    i+=lsb(i);
  }
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  for(int i=0;i<5;i++){
    update(i+1,source_arr[i]);
  }
  printf("%d\n",query_range_inclusive(1, 5));
  return 0;
}

