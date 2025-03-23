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

int t,arr[200000];

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
scanf("%d",&t);
  while(t--){
    int operated_on=-1;
    multiset<int>v;
    clear(arr,0);
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        v.insert(arr[i]);
    }
    bool last=false;
    for (int i=0;i<n;i++){
        if (i == operated_on) {
          // do nothing
          continue;
        }
        if (arr[i] != *v.rbegin() && operated_on == -1) {
            auto first_greater=v.upper_bound(arr[i]);
            auto second_greater=v.upper_bound(*first_greater);
            // the second value existing implies the first value exists
            // we want the number of values in front off arr[i] to be at most 1
            // ie. we want the second greater value to not exist, and have only one value greater than arr[i]
            if (second_greater == v.end() && v.count(*first_greater) == 1) {
                // find the first greater value and set it to operated_on
                for (int j=i+1;j<n;j++){
                    if (arr[j]==*first_greater){
                        operated_on=j;
                        break;
                    }
                }
                if (last) printf(" ");
                printf("%d", *first_greater);
                last = true;
                v.extract(*first_greater);
            }
        }
        if (arr[i]==*v.rbegin()){
            if (last) printf(" ");
            printf("%d",arr[i]);
            last = true;
        }
        v.extract(arr[i]);
    }
    printf("\n");
  }
  return 0;
}
