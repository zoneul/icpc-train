#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
    freopen(("SpeedQuiz/WordFrequency/testcases/" + to_string(t) + ".in").c_str(), "r", stdin);
    freopen(("SpeedQuiz/WordFrequency/testcases/" + to_string(t) + ".ans").c_str(), "w", stdout);

    string s;
    getline(cin, s);
    stringstream ss(s);
    map<string, int> m;
    string word;
    while(ss >> word) m[word]++;

    for(auto i:m) cout << i.first << " " << i.second << endl;

    fclose(stdin);
    fclose(stdout);
}

int main()
{
    for(int i = 10; i <= 10; i++) solve(i);
}