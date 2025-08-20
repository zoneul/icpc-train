#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i:v) cin >> i;

    int l=0, r=*max_element(v.begin(),v.end());
    while(l<r)
    {
        int m = (l+r)/2;

        int la = -1;
        bool c = true;
        for(auto& i: v)
        {
            if(i<=m) continue;
            else if(la == -1) la = i;
            else if(i != la)
            {
                c = false;
                break;
            }
            else la = -1;
        }
        c? r=m : l=m+1;
    }
    cout << l;
}

// 4 5 6 1 2 2 1 3 3 6 5 4