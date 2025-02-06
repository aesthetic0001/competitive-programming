#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clr(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

int n,q;
int arr[500001];
int maxl[500002],maxr[500002];
int freql[500002],freqr[500002];

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&q);
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  for(int i=1;i<=n;i++){
    maxl[i]=max(maxl[i-1],arr[i]);
    if(maxl[i]!=maxl[i-1]){
      freql[i]=1;
    }else{
      freql[i]=freql[i-1];
      if(maxl[i]==arr[i]){
        freql[i]++;
      }
    }
  }
  for(int i=n;i>=1;i--){
    maxr[i]=max(maxr[i+1],arr[i]);
    if(maxr[i]!=maxr[i+1]){
      freqr[i]=1;
    }else{
      freqr[i]=freqr[i+1];
      if(maxr[i]==arr[i]){
        freqr[i]++;
      }
    }
  }

  /*for(int i=1;i<=n;i++){*/
  /*  printf("%d ", freql[i]);*/
  /*}*/
  /*printf("\n");*/
  /*for(int i=1;i<=n;i++){*/
  /*  printf("%d ", freqr[i]);*/
  /*}*/
  /*printf("\n");*/
  /**/
  while(q--){
    int l,r;scanf("%d %d",&l,&r);
    int ct;
    if(maxl[l-1]==maxr[r+1]){
      ct=freql[l-1]+freqr[r+1];
    }else if(maxl[l-1]>maxr[r+1]){
      ct=freql[l-1];
    }else{
      ct=freqr[r+1];
    }
    printf("%d %d\n",max(maxl[l-1],maxr[r+1]),ct);
  }
  return 0;
}

