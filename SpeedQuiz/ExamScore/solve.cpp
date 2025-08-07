#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    freopen(("SpeedQuiz/ExamScore/testcases/" + to_string(t) + ".in").c_str(), "r", stdin);
    freopen(("SpeedQuiz/ExamScore/testcases/" + to_string(t) + ".ans").c_str(), "w", stdout);

    int n;
    cin >> n;
    vector<pair<double, int>> v(n);
    
    for(auto& i: v) cin >> i.first >> i.second, i.first = -i.first;;
    sort(v.begin(), v.end());
    
    for(auto& i: v) cout << -i.first << " " << i.second << endl;
}

int main()
{
    for(int i = 1; i <= 10; i++) solve(i);
}   