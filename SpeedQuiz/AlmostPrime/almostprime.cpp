#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long l,r;
    cin >> l >> r;

    int l2 = ceil(sqrt(l)), r2 = sqrt(r);
    vector<bool> p(r2+1, true);
    p[0] = p[1] = false;
    for(int i=2; i<=sqrt(r2); i++) if(p[i]) for(int j=i*i; j<=r2; j+=i) p[j] = false;

    cout << accumulate(p.begin()+l2, p.end(), 0) << endl;
}