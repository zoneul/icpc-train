#include <bits/stdc++.h>
using namespace std;
// 13E
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int n,m,d;
    cin >> n >> m;
    vector<int> a(n);
    for(auto& i: a) cin >> i;

    d=sqrt(n);
    vector<int> next(n);
    vector<int> co_next(n);
    vector<int> last(n);
    auto bucket = [&](int i) { return i>=n? (n-1)/d+1: i/d; };
    auto update = [&](vector<int>& a, int b) {
        for(int i=min(n, (b+1)*d)-1; i>=b*d; i--)
        {
            if(bucket(i) == bucket(i+a[i])) // Same block
            {
                next[i] = next[i+a[i]];
                co_next[i] = co_next[i+a[i]] + 1;
                last[i] = last[i+a[i]];
            }
            else // Different block
            {
                next[i] = i+a[i];
                co_next[i] = 1;
                last[i] = i;
            }
        }
    };
    for(int i=(n-1)/d;i>=0;i--) update(a, i);

    for(int i=0;i<m;i++)
    {
        int op, x, y;
        cin >> op;
        if(op==1)
        {
            cin >> x; x--;
            int ans=0;
            while(next[x] < n)
            {
                ans += co_next[x];
                x = next[x];
            }
            cout << last[x]+1 << " " << ans+co_next[x] << endl;
        }
        else if(op==0)
        {
            cin >> x >> y;
            a[--x] = y;
            update(a, x/d);
        }
    }
}   