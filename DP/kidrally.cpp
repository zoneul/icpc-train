#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> s(n, vector<int>(m));
    for(auto& i:s) for(auto& j:i) cin >> j;

    // Compute maximum element for each row (from right to left)
    vector<vector<int>> ma(s);
    for(auto& i:ma) for(int j=m-2;j>=0;j--) i[j] = max(i[j], i[j+1]);

    // Compute sum of maximum element from each row (from bottom to top), denote to max points one can get from row i
    vector<int> res(n);
    res.back() = ma.back().front();
    for(int i=n-2;i>=0;i--) res[i] = res[i+1] + ma[i].front();

    // DP array: dp[i] = max points bob can get if alice gets exactly i points
    // dp[i] = -1 means alice can't get exactly i points
    vector<int> dp(10*n+1, -1);
    dp[s.front().front()] = s.front().back(); // Base case: starting point

    int ans = 0;
    for(int i=1;i<n;i++)
    {
        // Alice finished: update final answer by looping over dp, assign all remaining point(res[i]) to Bob
        for(int j=0;j<dp.size();j++) if(dp[j]!=-1) ans = max(ans, j * (dp[j]+res[i])); 

        // Bob finished: update final answer by looping over dp, assign all remaining points(res[i]) to Alice
        for(int j=0;j<dp.size();j++) if(dp[j]!=-1) ans = max(ans, (j+res[i]) * dp[j]); 

        // Both continue: if there are duplicates of points, Alice should take leftmost. Calculate leftmost position for each point
        // ps. Alice won't step on rightmost, it's mean bob finished
        vector<int> first(10, 1e9);
        for(int j=m-2;j>=0;j--) first[s[i][j]] = j; // Both continue: Alice won't step on rightmost, it's mean bob finished

        // Update dp, use tmp to store intermediate results to avoid overwriting
        // ps. Also loop backward to avoid duplicate 
        vector<int> tmp(dp);
        for(int j=0;j<10;j++)
        {
            if(first[j]==1e9) continue; // If point j doesn't exist in the row
            
            // Update dp for point j
            for(int k=dp.size()-1;k>=j;k--)
            {
                if(dp[k-j] == -1) continue; 
                tmp[k] = max(tmp[k], dp[k-j] + ma[i][first[j]+1]);
            }
            // Update tmp dp for alice gaining j points, bob gaining points = max of the rest in row(ma[i][first[j]+1])
            for(int k=dp.size()-j-1; k>=0; k--) 
            {
                if (dp[k] == -1) continue; // Not exist
                tmp[k + j] = max(tmp[k + j], dp[k] + ma[i][first[j]+1]); // alice+j <-> bob+ma[i][first[j]+1]
            }
        }
        for(int i=0;i<10*n+1;i++) dp[i] = max(dp[i], tmp[i]); // Update tmp to dp
    }

    for(int i=0;i<dp.size();i++) ans = max(ans, i*dp[i]); // Calculate final answer
    cout << ans;
}

/*
Edge cases:
3 3
9 0 1
8 0 0
1 1 1

2 2
0 9
0 9
*/