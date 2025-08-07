#include <bits/stdc++.h>
using namespace std;

void gen(int t)
{
    freopen(("SpeedQuiz/WordFrequency/testcases/" + to_string(t) + ".in").c_str(), "w", stdout);

    int words = rand()%1000 + 1;
    for(int i=0; i<words; i++)
    {
        cout << (char)(rand()%5 + 'a') << (char)(rand()%5 + 'a');
        if(i < words-1)  cout << " ";
    }
}

int main()
{
    for(int i=1; i<=10; i++) gen(i);
}