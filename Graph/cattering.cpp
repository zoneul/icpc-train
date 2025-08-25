#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(auto& i:a) for(auto& j:i) cin >> j;

    int l=0, r=1e9;
    while(l<r)
    {
        int mid=(l+r)/2;

        vector<vector<int>> g(m+n+2);
        for(int i=1;i<=n;i++) 
        {
            for(int j=1;j<=m;j++) 
            {
                if(a[i][j]>=mid) 
                {
                    g[0].push_back(i);
                    g[i].push_back(n+j);
                    g[n+j].push_back(m+n+1);
                }
            }
        }

        while(true)
        {
            //BFS
            vector<bool> vi(n+m+2, false);
            vector<int> par(n+m+2, -1);
            queue<int> q;
            par[0]=0;
            q.push(0);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                if(u==n+1) break;
                for(auto& v:g[u])
                {
                    if(!vi[v])
                    {
                        par[v]=u;
                        vi[v]=true;
                        q.push(v);
                    }
                }
            }
        }
        if(/**/) r=mid;
        else l=mid+1;
    }
}