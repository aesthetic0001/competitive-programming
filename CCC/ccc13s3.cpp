#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;
namespace std {
  template <> struct hash<PII> {
	size_t operator()(const PII &p) const { return p.first ^ hash<int>()(p.second); }
};
}
int cs[5],T,G,ans=0;
unordered_set<PII>games = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};

void ch(){
  for(int i=1;i<=4;i++){
    if(i==T)continue;
    if(cs[i]>=cs[T]){
      /*printf("LOSE\n");*/
      /*for(int i=1;i<=4;i++){*/
      /*  printf("%d %d\n",i,cs[i]);*/
      /*}*/
      return;
    }
  }
  /*printf("WIN\n");*/
  /*for(int i=1;i<=4;i++){*/
  /*  printf("%d %d\n",i,cs[i]);*/
  /*}*/
  ans++;
}

void rc(PII node){
auto [a, b] = node;
games.erase(node);
/*printf("play %d %d\n",a,b);*/
bool fl=games.empty();
// win/lose
cs[a]+=3;
if(fl)ch();
else {
  rc(*games.begin());
};
cs[a]-=3;

cs[b]+=3;
if(fl)ch();
else {
  rc(*games.begin());
}; 
cs[b]-=3;

// tie
cs[a]+=1;
cs[b]+=1;
if(fl)ch();
else {
  rc(*games.begin());
};
cs[a]-=1;
cs[b]-=1;
/*printf("done with %d %d\n",a,b);*/
games.emplace(node);
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d\n%d",&T,&G);
    for(int i=0;i<G;i++){
      int a,b,sa,sb;
      scanf("%d %d %d %d",&a,&b,&sa,&sb);
      if(a>b){
        swap(a,b);swap(sa,sb);
      }
      if (sa==sb){
        cs[a]+=1;
        cs[b]+=1;
      }else if(sa>sb){
        cs[a]+=3;
      }else{
        cs[b]+=3;
      }
      games.erase(make_pair(a,b));
    }

    /*for(int i=1;i<=4;i++){*/
    /*  printf("%d: %d\n",i,cs[i]);*/
    /*}*/
    /**/
    rc(*games.begin());
    printf("%d\n",ans);

    return 0;
}

