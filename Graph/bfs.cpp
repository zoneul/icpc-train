#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }

    vector<bool> vi(n, false);
    queue<int> s; s.push(0);
    while(!s.empty())
    {
        int u = s.front(); s.pop();
        if(vi[u]) continue;
        vi[u] = true;
        for(auto& [v,w]: g[u])
        {
            // ทำไรก้ทำตามบาย
            if(!vi[v]) s.push(v);
        }
    }
}