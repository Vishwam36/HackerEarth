// By Vishwam Shriram Mundada
// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
// Easy

/*
Problem
Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round, Bishu's power will be varied.
With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the previous 
round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that 
he can kill in each round and the total sum of their powers.

INPUT:
The first line of the input contains N, the number of soldiers.
The second line contains an array of N numbers denoting the power of each soldier
This third line contains Q, which denotes the number of rounds.
Q lines follow, each line having one number denoting the power of Bishu.

OUTPUT:
For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number 
denotes the cumulative strength of all the soldiers that Bishu can beat.

CONSTRAINTS:
1<=N<=10000
1<=power of each soldier<=100
1<=Q<=10000
1<=power of bishu<=100

Sample Input
7
1 2 3 4 5 6 7
3
3
10
2

Sample Output
3 6
7 28
2 3
*/

#include<bits/stdc++.h>
using namespace std;

int count(int p[], int n, int m)
{
	int l = 0, r = n-1, mid;
	while(r-l > 1)
	{
		mid = (l+r)/2;

		if(p[mid] <= m)
			l = mid;
		else
			r = mid-1;
	}
	if(p[r] <= m)
		return r+1;
	if(p[l] <= m)
		return l+1;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int p[n];
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	
	sort(p, p+n);
	int pre[n]; // presum
	pre[0] = p[0];
	for(int i = 1; i < n; ++i)
		pre[i] = p[i] + pre[i-1];

	int q;
	cin >> q;

	while(q--)
	{
		int m;
		cin >> m;

		int cnt = count(p, n, m);
		int sum = cnt > 0 ? pre[cnt-1] : 0;

		cout << cnt << " " << sum << endl;
	}
}
