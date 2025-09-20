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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    int n;scanf("%d",&n);queue<int>q;bool flag=false;
    for(int i=0,k;i<n;i++){
        scanf("%d",&k);
        q.emplace(k);
    }
    int ct=0;int ans=0;
    while(!q.empty()){
        const auto top=q.front();q.pop();
        if(top-1==ct){flag=true;}
        else{
            ans+=1;
            ct-=1;
        }
        ct+=1;
    }
    if(flag){
        printf("%d",ans);
    }else{
        printf("-1");
    }
    return 0;
}
