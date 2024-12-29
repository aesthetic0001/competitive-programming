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

int arr[8] = {1,4,5,6,7,9,9,10};
int target = 12;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif

  int l = 0, r=7;

  for(int i=0;i<8;i++){
    int third = arr[i];
    while(r>l){
      if(r==i){
        r--;
        continue;
      }
      if(l==i){
        l++;
        continue;
      }
      if(arr[r]+arr[l]==target-third){
        break;
      }
      if(arr[r]+arr[l]<target-third){
        l++;
      }else{
        r--;
      }
    }
    if(r!=l)printf("%d + %d + %d = %d\n",third,arr[l],arr[r],target);
  }

  return 0;
}


