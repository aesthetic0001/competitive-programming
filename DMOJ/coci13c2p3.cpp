#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int X; string s; deque<string> precomp;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> X; cin >> s;

    precomp.emplace_front(s);

    string cur = s;
    int max = (s.size() % 2 == 0 ? s.size() / 2 : (s.size() - 1) / 2);

    while (true) {
        string temp = "";

        for (int i = s.size() - 1; i >= max; i--) {
            temp += cur[s.size() - 1 - i];
            if (s.size() - 1 - i != i) temp += cur[i];
        }

        cur = temp;

        if (cur == s) {
            break;
        }

        precomp.emplace_front(temp);
    }

    cout << precomp[(X - 1) % precomp.size()];

    return 0;
}
