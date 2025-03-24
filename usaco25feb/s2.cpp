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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

int dag[1000001],indeg[1000001],n;
// length of ith word (distance from 0)
int len[1000001];
vector<int>dag_rev[1000001];

queue<int>q;

// if we reach 0 and no children, then it's just 0
int query(int leaf){
    int parent=dag[leaf];
    int traversed=1;
    while(true){
        if(parent==0&&indeg[0]==1) {
            return 0;
        }
        // remove as child because it is already seen
        indeg[parent]--;
        // more than one child, we found our first fork
        if(indeg[parent]>=1){
            // have to traverse one more to get to unique
            return len[leaf]-traversed+1;
        }
        traversed++;
        parent=dag[parent];
    }
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int v;scanf("%d",&v);
        dag[i]=v;
        dag_rev[v].push_back(i);
        indeg[v]++;
    }
    int leaves=0;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            leaves++;
        }
    }
    q.push(0);
    while(!q.empty()){
        int top=q.front();q.pop();
        for (const auto &child:dag_rev[top]){
            if (len[top] + 1 > len[child]) {
                len[child] = len[top] + 1;
                q.push(child);
            }
        }
    }

    for (int i=0,leaf;i<leaves;i++){
        scanf("%d",&leaf);
        printf("%d\n",query(leaf));
    }

    // printf("%d %d\n",leaves,len[5]);
    return 0;
}
