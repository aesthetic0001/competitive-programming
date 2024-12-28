#include <bits/stdc++.h>

using namespace std;
int T, N, cakes[500001], psa[500001];

int main() {
    #ifdef LOCAL
    freopen("sample.in", "r", stdin);
    #endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &cakes[i]);
            psa[i] = cakes[i];
        }

        // Compute prefix sums for quick range sum calculations
        for (int i = 1; i <= N; i++) {
            psa[i] = psa[i - 1] + psa[i];
        }

        int l = 1, r = N, e = 0; // l = left pointer, r = right pointer, e = Elsie's stash
        while (r - l + 1 > 2) {
            int ub = (l + r) / 2;    // midpoint
            int lb = ub + 1;

            int sumL = psa[ub] - psa[l - 1]; // Sum of left half
            int sumR = psa[r] - psa[lb - 1]; // Sum of right half
            int midLeft = cakes[ub];        // Cake at middle-left
            int midRight = cakes[lb];       // Cake at middle-right
                                            //
            // Bessie's turn: She stacks optimally
            if (sumL >= sumR) {
                // Merge left-mid to right-mid to balance
                sumL -= midLeft;
                midRight += midLeft; // New merged cake
                ub--; // Move left boundary inward
            } else {
                // Merge right-mid to left-mid
                sumR -= midRight;
                midLeft += midRight; // New merged cake
                lb++; // Move right boundary inward
            }

            // Elsie's turn: She picks the maximum end cake
            if (cakes[l] >= cakes[r]) {
                e += cakes[l];
                l++; // Move left pointer inward
            } else {
                e += cakes[r];
                r--; // Move right pointer inward
            }
        }

        printf("%d %d\n", psa[N] - e, e); // Output Bessie's and Elsie's scores
    }

    return 0;
}
