#include <bits/stdc++.h>
using namespace std;

void gen(int t)
{
    int n = rand() % 100 + 1;
    vector<int> a(n), b(n);
    for(auto& i: a) i = rand() % 101 - 50;
    for(auto& i: b) i = rand() % 101 - 50;

    freopen(("SpeedQuiz/DotProduct/testcases/" + to_string(t) + ".in").c_str(), "w", stdout);
    cout << n << endl;
    for(auto i: a) cout << i << " ";
    cout << endl;
    for(auto i: b) cout << i << " ";
}

int main()
{
    for(int i=1; i<=10; i++) gen(i);
}