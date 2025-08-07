#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    freopen(("SpeedQuiz/DotProduct/testcases/" + to_string(t) + ".in").c_str(), "r", stdin);
    freopen(("SpeedQuiz/DotProduct/testcases/" + to_string(t) + ".ans").c_str(), "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto& i: a) cin >> i;
    for(auto& i: b) cin >> i;
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans += a[i] * b[i];
    cout << ans << endl;
}

int main()
{
    for(int i=1; i<=10; i++) solve(i);
}