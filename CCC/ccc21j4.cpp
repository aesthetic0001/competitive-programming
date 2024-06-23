#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int numL = 0, numM = 0, numS = 0;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    string s; cin >> s;

    for (const auto &c : s) {
        switch (c) {
            case 'L': {
                numL++;
                break;
            }
            case 'M': {
                numM++;
                break;
            }
            case 'S': {
                numS++;
                break;
            }
        }
    }

    // total misplaced ones in L. they all need to be moved out, guaranteeing that all the Ls will get moved to the front
    int M_in_L = 0, S_in_L = 0, misplacedS = 0, misplacedM = 0;
    for (int i = 0; i < numL; i++) {
        switch (s[i]) {
            case 'M': {
                M_in_L++;
                break;
            }
            case 'S': {
                S_in_L++;
                break;
            }
        }
    }

    // total other misplaced S
    for (int i = numL; i < numL + numM; i++) {
        if (s[i] == 'S') misplacedS++;
    }

    // total other misplaced M
    for (int i = numL + numM; i < s.size(); i++) {
        if (s[i] == 'M') misplacedM++;
    }

    cout << (M_in_L + S_in_L + max(misplacedS, misplacedM));

    return 0;
}
