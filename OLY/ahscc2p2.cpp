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

int a,b;string s;
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  cin.tie(0);cin.sync_with_stdio(0);
  cin>>a>>b>>s;
  int window=0,ans=0;
  bool flag=false;
  for(int i=0;i<a;i++){
    if(s[i]=='S'){
      flag=false;
      ans+=1;
      window+=1;
      if(window > b){
        cout << "NO";
        return 0;
      }
    } else if (s[i]=='P') {
      ans+=2;
      window+=1;
      if(window > b || flag) {
        cout << "NO";
        return 0;
      }
      flag=true;
    }else{
      flag=false;
      window =0;
    }
  }
  cout << "YES\n" << ans;
  return 0;
}
