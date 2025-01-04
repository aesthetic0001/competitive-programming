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

// if length is not power of 2, pad it to the closest power of 2
int arr[8]={5,8,6,3,2,7,2,6};
int segtree[16];

// 0 indexed
int query_sum(int l, int r){
  l+=8;r+=8;
  int ans=0;
  while(r>=l){
    // left should want to move toward to the right (in)
    if(l%2==1)ans+=segtree[l++];
    // right wants to move toward the left (also in)
    if(r%2==0)ans+=segtree[r--];
    l/=2;r/=2;
  }
  return ans;
}

void update_sum(int index, int val) {
  index+=8;
  int delta = val-segtree[index];
  while(index>1){
    segtree[index]+=delta;
    index/=2;
  }
  // alternatively, could just modify the base value and update all values while going up in an iterative manner using the definition of segtree, like in initialization
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif

  for(int i=0;i<8;i++){
    segtree[i+8]=arr[i];
  }

  for(int l=2;l<=8;l*=2){
    for(int i=8/l;i<=15/l;i+=1){
      segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
  }

  printf("%d\n",query_sum(2,7));
  update_sum(2,100);
  printf("%d\n",query_sum(2,7));
  return 0;
}

