#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    freopen(("SpeedQuiz/SecondaryPrime/testcases/" + to_string(t) + ".in").c_str(), "r", stdin);
    freopen(("SpeedQuiz/SecondaryPrime/testcases/" + to_string(t) + ".ans").c_str(), "w", stdout);

    int l,r;
    cin >> l >> r;

    vector<int> p(r+1, 0);
    for(int i=1; i<=r; i++) for(int j=i; j<=r; j+=i) p[j]++;

    int ans = 0;
    for(int i=l; i<=r; i++) if(p[p[i]] == 2) ans++;
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
}

int main()
{
    solve(5);
}