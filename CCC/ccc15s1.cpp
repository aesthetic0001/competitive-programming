#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
stack<int> st;

int main() {
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int k; scanf("%d", &k);
        if (k == 0) st.pop();
        else st.push(k);
    }
    
    while (!st.empty()) {
        ans += st.top(); st.pop();
    }
    
    printf("%d", ans);
    return 0;
}
