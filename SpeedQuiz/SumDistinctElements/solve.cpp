#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    freopen(("SpeedQuiz/SumDistinctElements/testcases/" + to_string(t) + ".in").c_str(), "r", stdin);
    freopen(("SpeedQuiz/SumDistinctElements/testcases/" + to_string(t) + ".ans").c_str(), "w", stdout);

    int n;
    cin >> n;
    set<int> s;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    int sum = 0;
    for(auto x: s) sum += x;
    cout << sum << endl;
}

int main()
{
    for(int i=1; i<=10; i++) solve(i);
}