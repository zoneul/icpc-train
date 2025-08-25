#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
 
    int N,M,K;
    cin >> N >> M >> K;
 
    vector<int> dp(1<<K, 1e9); dp[0]=0;
    while(N--)
    {
        int n,c,t,x=0;
        cin >> n >> c;
        while(n--) cin >> t, x |= (1<<(t-1));

        dp[x] = min(dp[x], c);
    }
    
    // Propagate down
    for(int i=(1<<K)-1; i>=0; i--)
        for(int j=0; j<K; j++)
            if(i&(1<<j)) dp[i^(1<<j)] = min(dp[i^(1<<j)], dp[i]);

    // Propagate back up
    for(int i=0; i<(1<<K); i++)
        for(int j=i; j; j=(j-1)&i)
            dp[i] = min(dp[i], dp[i^j] + dp[j]);

    while(M--)
    {
        int m,t,x=0;
        cin >> m;
        while(m--) cin >> t, x |= (1<<(t-1));
        cout << ((dp[x]>=1e9)? -1:dp[x]) << endl;
    }
}