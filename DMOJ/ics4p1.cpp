#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

string s, cur;
set<char>st;
unordered_set<char>active;
void recurse(char c) {
  cur+=c;
  if(cur.size()==s.size()){
    cout<<cur<<'\n';
    cur=cur.substr(0,cur.size()-1);
    return;
  }
  active.emplace(c);
  for(const auto&other:st){
    if(active.find(other)!=active.end())continue;
    recurse(other);
  }
  cur=cur.substr(0,cur.size()-1);
  active.erase(c);
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    cin>>s;
    for(const auto&c:s){
      st.emplace(c);
    }
    for(const auto&c:st){
      recurse(c);
    }
    return 0;
}

