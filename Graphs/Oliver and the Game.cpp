// By Vishwam Shriram Mundada
// https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
// Good question

/*
Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. The people of Byteland live happily along with
the King.
The city has a unique architecture with total N houses. The King's Mansion is a very big and beautiful bungalow having address = 1. Rest of the houses in 
Byteland have some unique address, (say A), are connected by roads and there is always a unique path between any two houses in the city. Note that the 
King's Mansion is also included in these houses.

Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and 
Bob is supposed to find him.
Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards 
the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.

Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, then he surely finds Oliver.

Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.

The queries can be of the following two types:
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion

INPUT :
The first line of the input contains a single integer N, total number of houses in the city. Next N-1 lines contain two space separated integers A and B 
denoting a road between the houses at address A and B.
Next line contains a single integer Q denoting the number of queries.
Following Q lines contain three space separated integers representing each query as explained above.

OUTPUT :
Print "YES" or "NO" for each query depending on the answer to that query.

CONSTRAINTS :
1 ≤ N ≤ 10^5
1 ≤ A,B ≤ N
1 ≤ Q ≤ 5*10^5
1 ≤ X,Y ≤ N

NOTE :
Large Input size. Use printf scanf or other fast I/O methods.

Sample Input
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1

Sample Output
YES
NO
NO
NO
YES

Explanation
Query 1 Bob goes from 8 towards 1 meeting 2 in the path. 
Query 2 Bob goes from 8 away from 1 and never meets 2. 
Query 3 Bob goes from 5 away from 1 and never meets 6. 
Query 4 Bob goes from 5 towards 1 and never meets 6. 
Query 5 Bob goes from 1 away from 1 and meets finds Oliver at 9. 
he can take the following two paths 1 -> 2 -> 6 -> 9 OR 1 -> 2 -> 7 -> 8 9 appears in atleast one of them
*/


// Concept of Euler Tour
// REF : https://www.youtube.com/watch?v=5h1JYjin_4o

// IMP : use scanf() and printf() for fast I/O

#include<bits/stdc++.h>
using namespace std;

int t = 1;
int in[100001];
int out[100001];
bool vis[100001];

void dfs(int src, int parent, vector<int> adj[])
{
    vis[src] = 1;
    in[src] = t++;

    for(int i = 0; i < adj[src].size(); ++i)
    {
        int child = adj[src][i];
        if(!vis[child] && child != parent)
        {
            dfs(child, src, adj);
        }
    }
    out[src] = t++;
}

int main()
{
	int n;
    scanf("%d", &n);

    memset(vis, false, sizeof(vis));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    vector<int> adj[n+1];

    for(int i = 0; i < n-1; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj);

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);

        if(a == 0) // y -> x -> mansion
        {
            if(in[y] > in[x] && out[y] < out[x])
                printf("YES\n");
            else
                printf("NO\n");
        }
        else // y -> x -> end
        {
            if(in[x] > in[y] && out[x] < out[y])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
