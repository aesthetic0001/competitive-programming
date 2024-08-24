#include <bits/stdc++.h>
#ifdef fread_unlocked
#define fread fread_unlocked
#endif
#define INPUT_SIZE (4<<20)
int _i0=0;
char _i[INPUT_SIZE+5];
#define su(x) do{while((_=_i[_i0++])<48);for(x=_-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si(x) do{while((_n=_i[_i0++])<45);if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
#define su2(x) do{for(x=_i[_i0++]-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si2(x) do{_n=_i[_i0++];if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
char _,_n;

using namespace std;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    fread(_i,1,INPUT_SIZE,stdin);

    return 0;
}
