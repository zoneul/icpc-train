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

    vector<int> dis(n,1e9);
    priority_queue<pair<int,int>> pq;
    dis[0] = 0; pq.push({-0,0});
    while(!pq.empty())
    {
        auto [d,u] = pq.top(); pq.pop();
        if(-d > dis[u]) continue;
        for(auto& [v,w]: g[u])
        {
            if(dis[v] > -d+w)
            {
                dis[v] = -d+w;
                pq.push({-dis[v], v});
            }
        }
    }
}