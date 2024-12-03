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
  int taskct=0;
  int carryover=0;
  for(int d=1;d<=maxd&&taskct<tasks.size();d++){
    int ct=mp;
    while(ct>0&&taskct<tasks.size()){
      const auto[due,t]=tasks[taskct];
      if(d>due){
        // printf("Impossible to finish task: %d\n",due);
        return false;
      }
      if(ct+carryover>=t){
        // printf("Finish task: %d | %d\n",due,t);
        ct-=((ct+carryover)-t);
        taskct++;
        carryover=0;
      }else{
        // printf("Work on task: %d %d\n",due,t);
        carryover=ct+carryover;
        ct=0;
      }
    }
  }
  return taskct==tasks.size();
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
  int l=0,r=1441;
  while(r>l){
    int mp=(l+r)/2;
    if(ok(mp)){
      r=mp;
    }else{
      l=mp+1;
    }
  }
  if(l==1441){
    printf("gg go next");
    return 0;
  }
  printf("%d",r);
  return 0;
}

