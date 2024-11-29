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
int n,maxd;
vector<PII>tasks;

bool ok(int mp){
  queue<PII>q;
  for(const auto &t:tasks){
    q.emplace(t);
  }
  for(int d=1;d<=maxd;d++){
    int ct=mp;
    while(ct>0){
      const auto[due,t]=q.front();
      if(q.empty())return true;
      if(d>due){
        // printf("Impossible to finish task: %d\n",due);
        return false;
      }
      if(ct>=t){
        // printf("Finish task: %d | %d\n",due,t);
        ct-=t;
        q.pop();
      }else{
        // printf("Work on task: %d %d\n",due,t);
        q.front().second-=ct;
        ct=0;
      }
    }
    if(q.empty())return true;
  }
  return true;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int t,d;scanf("%d %d",&t,&d);
    maxd=max(maxd,d);
    tasks.eb(mp(d,t));
  }
  sort(tasks.begin(),tasks.end());
  int l=0,r=1440;
  while(r>l){
    int mp=(l+r+1)/2;
    if(ok(mp)){
      r=mp;
    }else{
      l=mp+1;
    }
  }
  printf("%d",r);
  return 0;
}

