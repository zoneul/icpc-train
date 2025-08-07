#include <bits/stdc++.h>
using namespace std;

void gen(int t)
{
    freopen(("SpeedQuiz/Exam/testcases/" + to_string(t) + ".in").c_str(), "w", stdout);

    int n = rand() % 200 + 1;

    cout << n << endl;
    for (int i = 0; i < n; ++i) 
    {
        double a = (double)(rand() % 21) / 2.0;
        int b = rand() % 5 + 1;
        cout << fixed << setprecision(1) << a << " " << b << endl;
    }
}

int main()
{
    for (int i = 1; i <= 10; i++) gen(i);
}