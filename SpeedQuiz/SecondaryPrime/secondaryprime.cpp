#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,r;
    cin >> l >> r;

    vector<unsigned char> p(r+1, 0);
    for(int i=1; i<=r; i++) for(int j=i; j<=r; j+=i) p[j]++;

    int ans = 0;
    for(int i=l; i<=r; i++) if(p[p[i]] == 2) ans++;
    cout << ans << endl;
}