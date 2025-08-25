#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const ll p = 1e9+7;
 
// ll powmod(ll n, ll k)
// {
//     if(k==0) return 1;
 
//     ll tmp = powmod(n,k/2);
//     tmp = (tmp*tmp)%p;
//     if(k%2) tmp = (tmp*n)%p;
 
//     return tmp%p;
// }
ll powmod(ll n, ll k)
{
    ll ans = 1;
    while(k--) ans = (ans * n)%p;
    return ans;
}
 
int main()
{
    ll n,k;
    cin >> n >> k;
    ll t = n/3;
 
    ll ans;
    if(n%3 == 0) ans = (k*powmod(k-1,t-1))%p;
    else if(n%3 == 1) 
    {
        ll a1 = ((t+1)*k)%p, a2 = powmod(k-1,t)%p;
        ans = (a1*a2)%p;
    }
    else
    {
        ll a1 = ((t+1)*k)%p, a2 = powmod(k-1,t)%p;
        ll a = (a1*a2)%p;
 
        ll b1 = powmod(k-1,t+1)%p, b2=k, b3=((t+1)*(t+2)/2)%p;
        ll b = ((b1*b2)%p * b3)%p;
        ans = (a+b)%p;
    }
 
    cout << ans;
}