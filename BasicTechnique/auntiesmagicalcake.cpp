#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

// TAG: Greedy

int main()
{
    ull n;
    cin >> n;
    ull k = (n-1)/2;
    ull ans = k + (k*n*(n+1) - (2*n+1)*k*(k+1) + 4*(k*(k+1)*(2*k+1)/6))/2;
    cout << ans;
}