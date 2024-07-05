#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

string longer, shorter;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> longer >> shorter;

    if (longer == shorter) {
        cout << "Yes";
        return 0;
    }

    if (shorter.size() > longer.size() || longer.size() - shorter.size() > 1) {
        cout << "No";
        return 0;
    }

    int ct = 0; bool flag = false;

    for (const auto &c : longer) {
        if (shorter[ct] != c) {
            if (flag) {
                cout << "No";
                return 0;
            }
            flag = true;
        } else {
            ct++;
        }
    }

    cout << "Yes";

    return 0;
}
