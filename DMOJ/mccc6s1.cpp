#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;
int N,K,ans=0;
vector<int>pos,dis;
string s;
signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    cin>>N>>K>>s;
    s+="0";
    bool fl=false;
    for(int i=0;i<=N;i++){
      const char&c=s[i];
      if(c=='1'){
        fl=true;
      }else if(fl){
        ans+=1;
        pos.emplace_back(i-1);
        fl=false;
      }
    }
    if(K==0){
      cout<<ans;
      return 0;
    }
    if(pos.size()==1){
      cout<<1;
      return 0;
    }
    if(pos.size()==0){
      cout<<1;
      return 0;
    }
    for(int i=0;i<pos.size();i++){
      if(i!=0){
        dis.emplace_back(pos[i]-pos[i-1]-1);
      }
     }
    sort(dis.begin(),dis.end(),less<int>());
    for(int i=0;i<dis.size();i++){
      if(dis[i]>K){
        break;
      }
      K-=dis[i];
      ans-=1;
    }
    cout<<ans;
    return 0;
}

