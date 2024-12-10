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
int a[500001],compress[500001],N,Q;
vector<int>compressed;
/*unordered_map<int,set<int>>found;*/

// try bruteforce
// can coord compress
// idea: if any zeros found, then we can always make them EQ,
// if any complements which form zero are found, then we can make them EQ,
// otherwise if it is not already EQ, we will not be able to make them EQ.
// consider this: if we add any number, then there will be a difference of that number now; even if the rest is equal, it doesn't matter since the one used to add will not increment. even if you increment the current number as well, it doesn't matter because if it is eq that would imply that all of the numbers are the same anyways so it would have been covered by the initial EQ check;
// now consider multiplication: the same principle applies. even if they are a multiple ie. 2, 2, 3, that one number which is the multiplier is also within the range, so it will not end up being EQ and will fail.
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&N,&Q);
  for(int i=1;i<=N;i++){
    scanf("%d",&a[i]);
    /*if(compressed.empty()||compressed[compressed.size()-1]!=a[i]){*/
    /*  compressed.eb(a[i]);*/
    /*}*/
    /*compress[i]=compressed.size()-1;*/
  }
  for(int i=0;i<Q;i++){
    unordered_set<int>complement;
    int l,r;scanf("%d %d",&l,&r);
    bool isEQ=true;
    bool zeroFound=false;
    for(int j=l;j<=r;j++){
      if(j>l){
        if(a[j]!=a[j-1])isEQ=false;
      }
      if(a[j]==0||complement.find(a[j])!=complement.end()){
        zeroFound=true;
        break;
      }
      complement.emplace(-a[j]);
    }
    if(isEQ||zeroFound){
      printf("YES\n");
      continue;
    }
    printf("NO\n");
  }
  return 0;
}

