#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    freopen(("SpeedQuiz/AlmostPrime/testcases/" + to_string(t) + ".in").c_str(), "r", stdin);
    freopen(("SpeedQuiz/AlmostPrime/testcases/" + to_string(t) + ".ans").c_str(), "w", stdout);

    long long l,r;
    cin >> l >> r;

    int l2 = ceil(sqrt(l)), r2 = sqrt(r);
    vector<bool> p(r2+1, true);
    p[0] = p[1] = false;
    for(int i=2; i<=sqrt(r2); i++) if(p[i]) for(int j=i*i; j<=r2; j+=i) p[j] = false;

    cout << accumulate(p.begin()+l2, p.end(), 0) << endl;

    fclose(stdin);
    fclose(stdout);
}

int main()
{
    for(int i=5; i<=5; i++) solve(i);
    return 0;
}