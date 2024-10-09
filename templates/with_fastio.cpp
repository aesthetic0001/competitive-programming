#include <bits/stdc++.h>

// if segfaults, try using cstdio (scanf and print) because the buffered input may be tweaking

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define gc _buf[_ii++]
#define pc(x) _buf[_oi++] = x
#define readBuf() fread(_buf, 1, IO_SZ, stdin)
#define writeBuf() fwrite(_buf, 1, _oi, stdout)

const int IO_SZ = 8 << 20;
char _buf[IO_SZ], _tmp[20];
int _ii, _oi;
char _;
template <typename T> inline void scan(T &x){x=gc-'0'; while((_=gc)>='0') x=x*10+_-'0';}
template <typename T> inline void print(T x){_=0; do{_tmp[_++]=x%10;} while(x/=10); while(_) pc(_tmp[--_]+'0');}

template <typename T, typename... Args>
void scan(T &t, Args &...args){
    scan(t);
    scan(args...);
}

using namespace std;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    return 0;
}
