#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<bool> p(2000001, true);
    for(int i=2; i<=sqrt(2000000); i++) if(p[i]) for(int j=i*i; j<=2000000; j+=i) p[j]=false;
    vector<int> primes;
    for(int i=2; i<=2000000; i++) if(p[i]) primes.push_back(i);

    int x,k;
    while(cin >> x >> k)
    {
        if(x==0 && k==0) break;

        if(k*log10(x) > 100)
        {
            cout << "Input too big" << endl;
            continue;
        }

        int ma = floor(pow(x, k/16.0));
        if(ma < 2) cout << "Impossible" << endl;
        else 
        {
            int p = *(--upper_bound(primes.begin(), primes.end(), ma));

            long long res = 1;
            for(int i=0; i<16; i++) res = (res*p) % 10000007;
            cout << res << endl;
        }
    }
}