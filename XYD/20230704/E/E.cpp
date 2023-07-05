#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y,dis;
};
bool operator<(node a,node b){
	return a.dis<b.dis;
}
int mp[105][105];
void Dijkstra(int n){
	priority_queue<node,vector<node>,greater<node> >pq;
}
signed main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> mp[i][j];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				mp[j][i] += mp[n + 1 - i][n + 1 - j];
			}
		}
		
	}
}