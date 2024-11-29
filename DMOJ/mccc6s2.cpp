#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;
int N,K,result[1000001];
signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    scanf("%d %d",&N,&K);
    int ct=2*((N-K)/2);
    bool back=true;
    for(int i=N;i>=1;i--){
      if(ct){
        if(back){
          result[i-1]=i;
        }else{
          result[i+1]=i;
        }
        back=!back;
        ct--;
      }else{
        result[i]=i;
      }
    }
    if(K%2!=N%2){
      result[2]=1;
      result[1]=2;
    }

    for(int i=1;i<=N;i++){
      printf("%d ",result[i]);
    }
    return 0;
}

