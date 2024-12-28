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

  while(r>l){
    if(arr[r]+arr[l]==target){
      break;
    }
    if(arr[r]+arr[l]<target){
      l++;
    }else{
      r--;
    }
  }

  printf("%d + %d = %d\n",arr[l],arr[r],target);

  return 0;
}

