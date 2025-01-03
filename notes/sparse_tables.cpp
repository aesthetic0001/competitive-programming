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

// (start index, exponent on 2)
int sparse_table[8][3];
int arr[8] = {1,3,4,8,6,1,4,2};

int pow_2(int to){
  return (1 << to);
}

int log_2_floor(unsigned long long x) {
  return x == 0 ? -1 : __builtin_clzll(1) - __builtin_clzll(x);
}

// comparator function
int fn(int a, int b){
  return min(a,b);
}

// for relations in which overlap does not matter, as it's about some one property across the whole range, such as min and max
int query_transitive(int l, int r){
  int dist = log_2_floor(r - l + 1);
  printf("%d %d\n",r - l + 1,dist);
  /*return 1;*/
  return fn(sparse_table[l][dist],sparse_table[r-pow_2(dist)+1][dist]);
}

// for relations in which each value needs to be accounted for, in which case we use a fenwick-like query
int query_intransitive(int l, int r){
  // todo!
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif

  // it is important that we iterate exponent first, then the indices
  // this guarantees that we can use a dp bottoms-up like approach to compute larger exponents
  for(int i=0;i<8;i++){
    sparse_table[i][0]=arr[i];
  }
  for(int exponent=1;exponent<3;exponent++){
     for(int start=0;start+pow_2(exponent) - 1<8;start++){
       // split into two equal-sized intervals
       sparse_table[start][exponent]=fn(sparse_table[start][exponent-1],
           sparse_table[start+pow_2(exponent-1)][exponent-1]);
     }
  }
  printf("%d\n",query_transitive(6,7));
  return 0;
}

