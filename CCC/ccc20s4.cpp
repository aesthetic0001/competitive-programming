#include <bits/stdc++.h>

using namespace std;

string N;
int ans = INT32_MAX;

struct occurences {
    int a = 0, b = 0, c = 0;
    void increment(const char &ch) {
        switch (ch) {
            case 'A': {
                a++;
                break;
            }
            case 'B': {
                b++;
                break;
            }
            case 'C': {
                c++;
                break;
            }
            default: {
                cout << "NOT OK " << ch;
                exit(1);
            }
        }
    }
    void decrease(const char &ch) {
        switch (ch) {
            case 'A': {
                a--;
                break;
            }
            case 'B': {
                b--;
                break;
            }
            case 'C': {
                c--;
                break;
            }
            default: {
                cout << "NOT OK " << ch;
                exit(1);
            }
        }
    }
    void clear() {
        a = 0;
        b = 0;
        c = 0;
    }
};

// logic:
// all A in B must be moved to A eventually
// all A in C must be moved to A eventually
// this now guarantees that A is complete, and now only B and C need to be arranged
// now, there is a congruent amount of B in C and C in B, thus only 1 swap is needed for each misplaced
// number of misplaced would be max of initial B in C and initial C in B because the smaller one for some character X would have been "filled up" as A's swapped with the non-X due to the non-optimal swaps
// until it is equal to the larger one
inline void computeAns(occurences A, occurences B, occurences C) {
    ans = min(ans, B.a + C.a + max(B.c, C.b));
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    occurences A, B, C, total;

    for (const char &c : N) {
        total.increment(c);
    }
    // there are two unique permutations out of the 6 that we need to consider due to the symmetry
    // we will fix A, thus making us check for ABC and ACB

    // ABC
    for (int i = 0; i < N.size(); i++) {
        const auto &ch = N[i];
        if (i < total.a) {
            A.increment(ch);
        } else if (i < total.a + total.b) {
            B.increment(ch);
        } else {
            C.increment(ch);
        }
    }

    // do the computations for all N shifts (starting from all positions i for 0 <= i <= N - 1)
    computeAns(A, B, C);

    // shifting by the i + 1th element clockwise by discarding the ith element. Goes up to N-1 index, which is N.size - 2 discard
    for (int i = 0; i < N.size() - 1; i++) {
        const int startA = i, startB = (total.a + i) % N.size(), startC = (total.a + total.b + i) % N.size();

        A.decrease(N[startA]);
        A.increment(N[startB]);
        B.decrease(N[startB]);
        B.increment(N[startC]);
        C.decrease(N[startC]);
        C.increment(N[startA]);

        computeAns(A, B, C);
    }

    A.clear();
    B.clear();
    C.clear();

    // ACB
    for (int i = 0; i < N.size(); i++) {
        const auto &ch = N[i];
        if (i < total.a) {
            A.increment(ch);
        } else if (i < total.a + total.c) {
            C.increment(ch);
        } else {
            B.increment(ch);
        }
    }

    for (int i = 0; i < N.size() - 1; i++) {
        const int startA = i, startC = (total.a + i) % N.size(), startB = (total.a + total.c + i) % N.size();

        A.decrease(N[startA]);
        A.increment(N[startC]);
        C.decrease(N[startC]);
        C.increment(N[startB]);
        B.decrease(N[startB]);
        B.increment(N[startA]);

        computeAns(A, B, C);
    }

    cout << ans;

    return 0;
}
