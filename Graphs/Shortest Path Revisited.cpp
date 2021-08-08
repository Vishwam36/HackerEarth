// By Vishwam Shriram Mundada
// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/
// Good question

/*
In the country of HackerEarth, there are N cities and M bi - directional roads. We need to transport essential items from City 1  to all other cities. 
(There exists a path always)

But every road has some positive amount of Toll Charge associated with it say C (it is not same for all roads). We need to find the minimum amount of charge that it 
required to deliver essential items for each city.

Fortunately, to our rescue we have K special offers, which means while travelling from City 1 to any other city we can select at-most K roads and we will not be charged 
for using those roads. 

Can you now find the minimum charge that we have to pay to deliver essential items for each city.

(Remember we require to provide answers for each destination city separately i.e. we have K offers for every city and not as a whole)

Input :
1. First line contain three integers N M K.
2. Next M lines contain three integers U V W, denoting a road between city U and city v with Toll Charge W.

Output :
Print N space separated integers , denoting the minimum charge we require to pay for each city , where first integer represent cost for City 1, second for City 2 and so on.

Sample Input
5 6 1
1 2 2
1 3 6
2 4 6
2 5 8
3 5 4
4 5 1

Sample Output
0 0 0 2 2

Explanation
For City 1 , we are already there charge is 0.
For City 2 , we can reach with charge 0, by using 1 special offer for road 1 - 2.
For City 3 , we can reach with charge 0, by using 1 special offer for road 1 - 3.
For City 4 , we can reach with charge 2, by using path 1 - 2 - 4 , and using 1 offer for road 2 - 4.
For City 5 , we can readh with charge 2, by using path 1 - 2 - 5 , and using 1 offer for road 2 - 5.
*/

// REF : https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-revisited-9e1091ea/discussion/approach-and-code-1ee91232/

#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, pair<int, int> >

void dijkstra(vector<pair<int, int> > adj[], int n, int k)
{
	// dp[i][j] represents minimum cost to reach i using j coupons
    vector<vector<int> > dp(n+1, vector<int>(k+1, INT_MAX));
    dp[0][0] = 0;

    priority_queue<pp, vector<pp>, greater<pp> > pq;
    pq.push({0, {0, 0}}); // {cost, {node, coupons}}

    while(!pq.empty())
    {
        pp p = pq.top(); pq.pop();
        int d = p.first;
        int u = p.second.first;
        int j = p.second.second;

        for(auto next : adj[u])
        {
            int v = next.first;
            int w = next.second;

            if(dp[v][j] > d+w) // coupon not used
            {
                pq.push({d+w, {v, j}});
                dp[v][j] = d+w;
            }

            if(j < k && dp[v][j+1] > d) // coupon used
            {
                dp[v][j+1] = d;
                pq.push({d, {v, j+1}});
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        cout << *min_element(dp[i].begin(), dp[i].end()) << " ";
    }
}

int main()
{
	int n, m, k, a, b, w;
    cin >> n >> m >> k;
    vector<pair<int, int> > adj[n+1];

    while(m--)
    {
        cin >> a >> b >> w;
        adj[a-1].push_back({b-1, w});
        adj[b-1].push_back({a-1, w});
    }

    dijkstra(adj, n, k);
}
