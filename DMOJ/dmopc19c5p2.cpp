#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define em emplace
#define pb push_back
#define lsb(i) i & -i
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  int n,h;cin>>n>>h;
  vector<pair<bool,int>>v(n*2+2);
  v[0]=mp(true,0);
  v[0]=mp(false,0);
  for(int i=0;i<n;i++){
    string a;int b;cin>>a>>b;
    v[2*i+1]=mp(a=="A",b);
  }
  for(int i=1;i<=n;i++){
    string a;int b;cin>>a>>b;
    v[2*i]=mp(a=="A",b);
  }
  int curH=h,nextH=h;
  for(int i=1;i<=n*2+1;i++){
      const auto[pA,pM]=v[i-1];
      const auto[cA,cM]=v[i];
      cout<<curH<<" "<<nextH<<'\n';
      if(cA&&pA){
          nextH-=cM;
      }else if(!cA&&!pA){
          nextH-=pM;
      }
      if(curH==0||nextH==0){
          cout << curH << " " << nextH;
          return 0;
      }
      swap(curH,nextH);
  }
  cout<<"TIE";
  return 0;
}
