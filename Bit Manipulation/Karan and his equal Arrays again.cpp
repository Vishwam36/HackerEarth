// By Vishwam Shriram Mundada
// https://www.hackerearth.com/problem/algorithm/karan-and-array/
// Decent

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), l(n), r(n);

		for(int i = 0; i < n; ++i)
			cin >> a[i];

		if(n == 1)
		{
			cout << "NO\n";
			continue;
		}

		string ans = "NO\n";
		
		l[0] = a[0];
		r[n-1] = a[n-1];

		for(int i = 1; i < n; ++i)
			l[i] = l[i-1] & a[i];
		for(int i = n-2; i >= 0; --i)
			r[i] = r[i+1] & a[i];
		
		for(int i = 0; i < n-1; ++i)
			if(l[i] == r[i+1])
				ans = "YES\n";

		cout << ans;
	}
}
