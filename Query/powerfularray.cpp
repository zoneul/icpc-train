#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
//86D
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto& i:v) cin >> i;

    vector<tuple<int,int,int>> Q(q);
    for(int i=0;i<q;i++)
    {
        auto& [l,r,ind] = Q[i];
        cin >> l >> r;
        l--, r--, ind = i;
    }

    int d = sqrt(n);
    sort(Q.begin(), Q.end(), [&](const auto& a, const auto& b) {
        int na = get<0>(a)/d;
        int nb = get<0>(b)/d;
        if(na != nb) return na < nb;
        return get<1>(a) < get<1>(b);
    });

    int cl=0, cr=0;
    ull cans=0;
    vector<ull> ans(q);
    vector<int> co(1e6+1, 0);
    auto add = [&](int x) { cans += (ull)(2*(co[x]++)+1)*x; };
    auto remove = [&](int x) { cans -= (ull)(2*(co[x]--)-1)*x; };
    for(auto& [l,r,i]:Q) 
    {
        while(cr <= r) add(v[cr++]);
        while(cr > r+1) remove(v[--cr]);

        while(cl > l) add(v[--cl]);
        while(cl < l) remove(v[cl++]);

        ans[i] = cans;
    }
    for(auto& i:ans) cout << i << endl;
}