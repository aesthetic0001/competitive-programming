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
    cin.tie(0);cin.sync_with_stdio(0);
    string in;cin>>in;
    int ans=in.length();
    bool prev=false;
    for(const auto &c:in){
        if (c=='0'){
            if (prev) {ans-=1;prev=false;}
            else prev=true;
        }else{
            prev=false;
        }
    }
    cout<<ans;
    return 0;
}
