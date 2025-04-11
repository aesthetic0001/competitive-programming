#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <unordered_map>

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

string itos[10001];
unordered_map<string, int>mx;
unordered_map<string, int>cur;
vector<pair<string, int>>ps;
int ans = 0;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  cin.tie(0);cin.sync_with_stdio(0);
  int a,b;cin>>a>>b;
  for(int i=0;i<b;i++) {
      cin>>itos[i];
  }
  for(int i=0;i<b;i++){
      cin>>mx[itos[i]];
  }
  for (int i=0;i<a;i++){
      string s;int a;cin>>s>>a;
      ps.eb(mp(s,a));
  }
  int l=0,r=0;
  while(l<ps.size()){
      const auto &[sl,ctl]=ps[l];
      // cannot expand
      if(ctl>mx[sl]){
          l++;
          l=r;
          continue;
      }
      cout << "expand from " << l << " to " << r << "\n";
      ans=max(ans, 1);
      cur[sl]+=ctl;
      if(r<ps.size() - 1){
          r+=1;
          const auto &[sr,ctr]=ps[r];
          if(ctr > mx[sr]) {
              r++;
              l=r;
              continue;
          }
          if (sr == sl && cur[sr] + ctr > mx[sr]) {
              // chose which one to keep
              if(ctl>=ctr){
                  // keep ctr
                  cur[sl]-=ctl;
                  l++;
              } else {
                  cur[sr]-=ctr;
                  r++;
              }
          } else {
              cur[sr] += ctr;
              r++;
          }
      }else {
          break;
      }
      ans=max(ans,r-l+1);
      cur[sl]-=ctl;
  }
  cout << ans;
  return 0;
}
