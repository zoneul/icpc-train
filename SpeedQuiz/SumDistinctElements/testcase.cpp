#include <bits/stdc++.h>
using namespace std;

void gen(int t)
{
    freopen(("SpeedQuiz/SumDistinctElements/testcases/" + to_string(t) + ".in").c_str(), "w", stdout);
    int n = rand() % 500 + 1;

    cout << n << endl;
    for(int i=0; i<n; i++) cout << rand() % 101 << " ";
}

int main()
{
    for(int i=1; i<=10; i++) gen(i);
}