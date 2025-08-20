#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    // freopen("BasicTechnique/Gssspotted/testcases/input.txt", "r", stdin);
    int n,t;
    cin >> t >> n;
    freopen(("BasicTechnique/DivisorsofNumber/testcases/"+to_string(t)+".in").c_str(), "w", stdout);
    cout << n << endl;
    for(int i=1;i<=n;i++)
    {
        // 40000 41204 85357...100000
        if(i==40000 || i==41204 || (i>=85357 && i<=100000))
            cout << 'H';
        else
            cout << 'T';
    }
}