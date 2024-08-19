#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    int totalEdges = 0;
    int temp;

    for (int i = 0; i < 4; i++) {
        int vertexEdges = 0;
        for (int j = 0; j < 4; j++) {
            cin >> temp;
            if (temp) vertexEdges++;
        }
        // assuming fully connected mst, all 4 vertices must have an
        if (!vertexEdges) {
            cout << "No";
            return 0;
        }
        totalEdges += vertexEdges;
    }

    totalEdges /= 2;

    if (totalEdges != 3) {
        cout << "No";
        return 0;
    }

    cout << "Yes";

    return 0;
}
