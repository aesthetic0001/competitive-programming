#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
int out[200001],c[200001];
bool solved[200001];
vector<int>in[200001];
vector<int> vis;

pair<int, int> recurse(int node, int root) {
    // cout << "solving for subtree " << node << "\n";
    // solved[node]=true;
    vis.emplace_back(node);
    pair<int,int> node_res = {0, c[node]};
    for(const auto &child : in[node]) {
        if (child==root) continue;
        pair<int, int> child_res = recurse(child, root);
        // we will treat the current node as the root node
        // thus, if we want to not turn the current node into a idempotent node, we need to ensure that the child is idempotent
        // as a root node, we can guarantee that the current node has an idempotent parent because it is expected to point to itself
        // recursive guarantee: the children will all be able to point to themselves if we don't want to point to ourself
        node_res.first+=child_res.second;
        node_res.second+=min(child_res.first, child_res.second);
    }
    return node_res;
}

int solve(int node1, int node2){
    // either node or parent. max size of 2
    vis = {};
    int minans = min(recurse(node1, node1).second, recurse(node2, node2).second);
    for(auto &v:vis){
        solved[v]=true;
    }
    return minans;
}

signed main() {
    // try solving with tree dp
    // optimal standing occurs when a node points to itself
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>out[i];
        in[out[i]].emplace_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if (out[i]==i){
            // no need to change this at all - it is in the optimal standing
            c[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(solved[i])continue;
        // proceed by solving the subtree
        int root = i;int chaser=out[root];
        // it will eventually lead to the root node, since the value pointed to is >= value, at some point
        // it must point to itself
        while (root!=chaser) {
            root = out[root];
            chaser = out[out[chaser]];
        }
        int res = solve(root, out[root]);
        // cout << "root " << root << " " << res << "\n";
        ans += res;
    }
    cout << ans;
    return 0;
}
