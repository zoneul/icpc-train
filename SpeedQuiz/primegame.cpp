#include <bits/stdc++.h>
using namespace std;

int main()
{
    int np = 1e6;
    int sqnp = sqrt(np);
    vector<bool> p(np+1, true);
    p[0] = p[1] = false;
    for(int i=2; i<=sqnp; i++) if(p[i]) for(int j=i*i; j<=np; j+=i) p[j] = false;

    int n;
    cin >> n;
    
    map<string,tuple<int,int,int,bool>> m; // max-prime, point, time, ded
    vector<string> v;
    for(int i=0; i<n; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        
        auto& [ma, pt, t, c] = m[s];

        if(c) continue;
        else if(p[x])
        {
            if(ma > x) continue;
            pt++;
            ma = x;
            t = i;
        }
        else
        {
            c = true;
            v.push_back(s);
        }
    }

    vector<tuple<int,int,int,string>> ans;
    for(auto i: m)
    {
        auto& [ma, pt, t, c] = i.second;
        if(c) continue;
        ans.push_back({-ma, -pt, t, i.first});
    }
    sort(ans.begin(), ans.end());

    if(ans.empty()) cout << "NONE" << endl;
    else
    {
        auto [max_prime, point, time, name] = ans.front();
        cout << name << " " << -max_prime << endl;
    }

    if(v.empty()) cout << "NONE" << endl;
    else
    {
        string name = v.back();
        int max_prime = get<0>(m[name]);
        cout << v.back() << " " << ((max_prime)? to_string(max_prime):"-") << endl;
    }
}