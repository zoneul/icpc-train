#include <bits/stdc++.h>
using namespace std;

void gen(int t)
{
    int m = rand() % 50 + 1;
    int n = rand() % 50 + 1;

    freopen(("SpeedQuiz/MatrixMinMax/testcases/" + to_string(t) + ".in").c_str(), "w", stdout);
    cout << m << " " << n << endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++) cout << rand() % 201 - 100 << " ";
        cout << endl;
    }
}

int main()
{
    for(int i=1; i<=10; i++) gen(i);
}