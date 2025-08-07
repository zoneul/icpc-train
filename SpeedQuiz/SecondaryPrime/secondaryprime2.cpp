#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,r;
    cin >> l >> r;

    vector<unsigned char> d(r+1, 0);
    for(int i=1; i<=r; i++) for(int j=i; j<=r; j+=i) d[j]++;

    vector<bool> p(r+1, true);
    p[1] = p[0] = false;
    for(int i=2; i<=sqrt(r); i++) if(p[i]) for(int j=i*i; j<=r; j+=i) p[j] = false;

    int ans = 0;
    for(int i=l; i<=r; i++) if(p[d[i]]) ans++;
    cout << ans << endl;
}