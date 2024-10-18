#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    stack<int> st;

    for (int i = 0; i < 5; i++) {
      st.push(i);
    }

    while (!st.empty()) {
      printf("%d\n", st.top());
      st.pop();
    }

    return 0;
}

