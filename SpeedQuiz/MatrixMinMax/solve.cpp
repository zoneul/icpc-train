#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    freopen(("SpeedQuiz/MatrixMinMax/testcases/" + to_string(t) + ".in").c_str(), "r", stdin);
    freopen(("SpeedQuiz/MatrixMinMax/testcases/" + to_string(t) + ".ans").c_str(), "w", stdout);

    int m, n;
    cin >> m >> n;
    vector<tuple<int, int, int>> v;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int val;
            cin >> val;
            v.push_back({val, i, j});
        }
    }
    sort(v.begin(), v.end());
    
    int val, row, col;
    tie(val, row, col) = v.front();
    cout << val << " (" << row << ", " << col << ")" << endl;
    tie(val, row, col) = v.back();
    cout << val << " (" << row << ", " << col << ")" << endl;
}

int main()
{
    for(int i = 1; i <= 10; i++) solve(i);
}