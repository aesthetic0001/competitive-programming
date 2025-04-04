#include <bits/stdc++.h>

#define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clear(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>
#define IDMAX = 1000000001

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

int n,a,b,ans;
unordered_map<int, int> out,amount;
unordered_map<int, bool> vis,donate;
unordered_map<int, unordered_set<int>>g;
unordered_set<int>ids;
queue<int>q;
vector<PII>in;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
scanf("%lld %lld %lld",&n,&a,&b);
for(int i=0;i<n;i++){
    int ct,id;scanf("%lld %lld",&ct,&id);
    amount[id]=ct;
    in.emplace_back(mp(ct,id));
    ids.emplace(id);
  }
  for (const auto&[ct,id]:in){
    // prevent duplicates, dont need to explicitly double edge
    if(ids.count(a-id)){
      out[id]++;
      g[id].emplace(a-id);
    }
    if(a!=b && ids.count(b-id)){
      out[id]++;
      g[id].emplace(b-id);
    }
  }
  for(const auto&id:ids){
    if(out[id]==1){
      vis[id]=true;
      q.emplace(id);
    }
  }
  while(!q.empty()){
    int top=q.front();q.pop();
    if(g[top].empty()){
      continue;
    }
    int parent=*g[top].begin();
    int max_donate=min(amount[top],amount[parent]);
    if(parent==top){
      max_donate=max_donate/2;
    }
    /*cout << "donate " << max_donate << " from " << top << " to " << parent << "\n";*/
    ans+=max_donate;
    amount[parent]-=max_donate;
    amount[top]-=max_donate * (parent==top ? 2 : 1);
    if(!vis[parent]){
      vis[parent]=true;
      q.emplace(parent);
    }
    g[parent].erase(top);
  }
  printf("%lld",ans);
  return 0;
}
