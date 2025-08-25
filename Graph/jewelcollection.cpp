#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<bool> cy;
int fin(int x) { return x==par[x] ? x : par[x]=fin(par[x]); }
bool uni(int x, int y)
{
    int px=fin(x), py=fin(y);
    if(cy[px] && cy[py]) return false;

    bool b = cy[px] || cy[py] || (px==py);
    cy[px]=b, cy[py]=b;
    par[px] = py;

    return true;
}

vector<vector<pair<int,int>>> g;
vector<int> ans;
void dfs(int v, int p)
{
    if(g[v].empty()) return;

    auto e = g[v].back();
    g[v].pop_back();

    auto it = find(g[e.first].begin(), g[e.first].end(), make_pair(v, e.second));
    if(it != g[e.first].end()) g[e.first].erase(it);

    ans[v] = e.second;
    dfs(e.first, v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<tuple<int,int,int,int>> E; // value, n, c1, c2
    for(int i=1;i<=n;i++)
    {
        int t,c1,c2,v;
        cin >> t;
        if(t==1) cin >> c1 >> v, c2=c1;
        else if(t==2) cin >> c1 >> c2 >> v;
        E.push_back({-v, i, c1, c2});
    }
    sort(E.begin(), E.end());

    par.resize(c+1);
    iota(par.begin(), par.end(), 0);
    cy.resize(c+1, false);
    ans.resize(c+1, 0);
    g.resize(c+1);

    long long sum = 0;
    for(auto [nv, i, c1, c2] : E) 
    {
        if(uni(c1, c2)) 
        {
            sum += -nv;
            g[c1].emplace_back(c2, i);
            g[c2].emplace_back(c1, i);
        }
    }  

    // Cut tail
    for(int i=1;i<=c;i++) 
    {
        if(ans[i]==0 && g[i].size()==1) 
        {
            int curr = i;
            while(g[curr].size()==1)
            {
                auto e = g[curr].back();
                g[curr].pop_back();

                auto it = find(g[e.first].begin(), g[e.first].end(), make_pair(curr, e.second));
                if(it != g[e.first].end()) g[e.first].erase(it);

                ans[curr] = e.second;
                curr = e.first;
            }
        }
    }

    // Full Cycle
    for(int i=1;i<=c;i++) if(ans[i]==0) dfs(i, -1);

    bool check = true;
    for(int i=1;i<=c;i++) if(ans[i]==0) check = false;
    if(check)
    {
        cout << sum << endl;
        for(int i=1;i<=c;i++) cout << ans[i] << " ";
    }
    else cout << -1;
}

/*
7 4
2 1 3 2
2 2 4 4
2 2 4 5
2 2 3 1
2 1 3 5
1 2 6
1 4 3

4 4
1 2 1
1 3 1
1 1 1
1 4 1

2 2
1 2 1
2 1 2 1

3 3
1 1 10
1 2 20
2 1 3 30

2 2
2 2 1 2
2 2 1 2

3 3
2 1 2 4
2 1 3 4
1 1 5

// 10
4 4 
2 1 2 1
2 2 3 1
2 3 4 1
2 2 3 1

*/