#include <bits/stdc++.h>
using namespace std;

void solve(istream &in, ostream &out)
{
    long long n;
    string s;
    in >> n >> s;

    long long sum = 0, co = 0;
    for(int i=1;i<=n;i++) if(s[i-1] == 'H') sum += i, co++;

    long long ans = 2*sum - co*co;
    out << ans;

    long long cmp = n*(n+1);
    if(4*ans < cmp) out << " <";
    else if(4*ans > cmp) out << " >";
    else out << " =";
}

int main() {
    for (int tc = 1; tc <= 10; ++tc) 
    {
        string inFile = "BasicTechnique/Gssspotted/testcases/"+to_string(tc)+".in";
        string outFile = "BasicTechnique/Gssspotted/testcases/"+to_string(tc)+".ans";
        ifstream fin(inFile);
        ofstream fout(outFile);
        solve(fin, fout);
    }
}