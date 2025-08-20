#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    long long n;
    string s;
    cin >> n >> s;

    set<int> v;
    for(int i=1;i<=n;i++) if(s[i-1] == 'H') v.insert(i);

    long long ans = 0;
    while(!v.empty())
    {
        int x = v.size();
        int y = *v.lower_bound(x);

        ans += 2*(y-x) + 1;
        v.erase(y);
    }
    cout << ans;

    long long cmp = n*(n+1);
    if(4*ans < cmp) cout << " <";
    else if(4*ans > cmp) cout << " >";
    else cout << " =";
}