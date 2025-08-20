#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,n;
    cin >> x >> y >> n;

    int tx = __builtin_ctz(x);
    int ty = __builtin_ctz(y);
    int mi = min(tx, ty);
    x >>= mi;
    y >>= mi;
    
    cout << n*mi + __builtin_ctz(x-y) + (n%2? 0 : __builtin_ctz(x+y) + __builtin_ctz(n) - 1) << endl;
}

/*
000100 -> 4
010100 -> 20

100100100100 -> 2340
000100100100 -> 292
*/