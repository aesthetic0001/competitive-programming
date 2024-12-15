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

int previous[100001],T;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d",&T);
  while(T--){
    set<int>ans;
    int N;scanf("%d",&N);
    for(int i=1;i<=N;i++){
      previous[i]=0;
    }
    for(int i=1;i<=N;i++){
      int d;scanf("%d",&d);
      if(previous[d] && i-previous[d]<=2){
        ans.emplace(d);
      }
      previous[d]=i;
    }
    if(!ans.empty()){
      for(const auto &a:ans){
        printf("%d ",a);
      }
    }else{
      printf("-1");
    }
    printf("\n");
  }
  return 0;
}

