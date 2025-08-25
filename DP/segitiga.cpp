#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int t=1;t<=20;t++)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(3, false)));

        for(int i=0;i<n;i++) dp[i][i][s[i]-'0']=true;
        for(int l=1;l<n;l++)
        {
            for(int i=0;i+l<n;i++)
            {
                int j=i+l;
                for(int x=i; x<j; x++)
                {
                    // 0: 02
                    dp[i][j][0] = dp[i][j][0] || (dp[i][x][0] && dp[x+1][j][2]);
                    // 1: 01 11 12 20 22
                    dp[i][j][1] = dp[i][j][1] || (dp[i][x][0] && dp[x+1][j][1]);
                    dp[i][j][1] = dp[i][j][1] || (dp[i][x][1] && dp[x+1][j][1]);
                    dp[i][j][1] = dp[i][j][1] || (dp[i][x][1] && dp[x+1][j][2]);
                    dp[i][j][1] = dp[i][j][1] || (dp[i][x][2] && dp[x+1][j][0]);
                    dp[i][j][1] = dp[i][j][1] || (dp[i][x][2] && dp[x+1][j][2]);
                    // 2: 00 10 21
                    dp[i][j][2] = dp[i][j][2] || (dp[i][x][0] && dp[x+1][j][0]);
                    dp[i][j][2] = dp[i][j][2] || (dp[i][x][1] && dp[x+1][j][0]);
                    dp[i][j][2] = dp[i][j][2] || (dp[i][x][2] && dp[x+1][j][1]);
                }
            }
        }
        cout << (dp[0][n-1][0] ? "yes" : "no") << endl;
    }
}