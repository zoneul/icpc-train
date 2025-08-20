#include <bits/stdc++.h>
using namespace std;

// TAG: Greedy, BS
int main()
{
    int n,m,h,q;
    cin >> n >> m >> h >> q;
 
    vector<pair<int,int>> v(n);
    set<int> net;
    
    for(auto& i:v) cin >> i.first >> i.second;
    for(int i=0;i<m;i++) 
    {
        int x;
        cin >> x;
        net.insert(x);
    }
    
    vector<int> ans;
    for(auto i:v)
    {
        auto it = net.lower_bound(abs(i.second-h));
        if(it != net.end())
        {
            ans.push_back(i.first);
            net.erase(it);
        }
    }
    
    while(q--)
    {
        int x;
        cin >> x;
        cout << (x>ans.size()? -1:ans[x-1]) << endl;
    }
}