#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int n,diffR[1000002],diffB[1000002],ans=0;
vector<int>g;
string s;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin>>n>>s;
    for(int i=0;i<n;i++){
      if(s[i]=='G'){
        g.emplace_back(i + 1);
      } else if(s[i]=='B'){
        diffB[i + 1]+=1;
        diffB[n + 1]-=1;
      }else if(s[i]=='R'){
        diffR[0]+=1;
        diffR[i+2]-=1;
      }
    }

    for(int i=1;i<=n;i++){
      diffR[i]+=diffR[i-1];
      diffB[i]+=diffB[i-1];
    }

    for(int i=0;i<g.size();i++){
      int lb=0,ub=n,cur=g[i];
      if(i!=0){
        lb=g[i-1];
      }
      if(i!=g.size()-1){
        ub=g[i+1];
      }
      ans+=(diffR[lb] - diffR[cur])*(diffB[ub]-diffB[cur]);
    }

    printf("%lld",ans);

    return 0;
}

