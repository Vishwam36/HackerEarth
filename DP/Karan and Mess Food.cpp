// By Vishwam Shriram Mundada
// https://www.hackerearth.com/problem/algorithm/salads/
// Good

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll myp(ll a, ll p)
{
	if(p == 0)
		return 1;
	
	ll ans;
	if(p % 2 == 0)
	{
		ans = myp(a, p/2);
		ans = ans * ans;
	}
	else
	{
		ans = myp(a, p/2);
		ans = ((ans * ans) % mod) * a;
	}
	return ans % mod;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n, k;
		cin >> n >> k;

		ll ans = 0;
		vector<ll> v(n+1);
		for(int i = n; i >= 2; --i)
			v[i] = myp(n/i, k);
		
		for(int i = n; i >= 2; --i)
		{
			for(int j = i*2; j <= n; j+=i)
				v[i] = (v[i] - v[j] + mod) % mod;
			
			ans = (ans + v[i]) % mod;
		}

		cout << ans << '\n';
	}
}
