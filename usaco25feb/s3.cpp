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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;
int t,a,b,c,d;

int recurse(int x, int y, int cur) {
    if (x == a && y == b) return cur;
    if (x < a || y < b) return -1;
    int res;
    // atp, only one of the conditions will be fulfilled: x > y or x < y
    // if x == y and they are not already equal to a,b, then it will only form 0
    if (x > y) {
        int ops = (x-a)/y;
        // assert(ops > 0);
        if (ops == 0) {
            return -1;
        }
        res = recurse(x - ops * y, y, cur + ops);
    } else if (y > x) {
        int ops = (y-b)/x;
        if (ops == 0) {
            return -1;
        }
        res = recurse(x, y - ops * x, cur + ops);
    } else {
        return -1;
    }
    return res;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        cout << recurse(c, d, 0) << "\n";
    }
    return 0;
}
