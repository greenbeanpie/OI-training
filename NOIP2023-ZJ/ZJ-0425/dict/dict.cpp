#include<bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define LL long long
#define mod 998244353
inline LL read()
{
	LL x=0, y=1;
	char ch=getchar();
	for (; ch<'0' || ch>'9'; ch=getchar())
		if (ch=='-') y=-1;
	for (; ch<='9' && ch>='0'; ch=getchar())
		x=(x<<3)+(x<<1)+(ch&15);
	return x*y;
}

#define N 3010
int n, m;
int s[N][27];
vector<pair<int, int> > g[N];

inline bool less_than(int x, int y) // O(1)
{
	// y : reverse
	for (uint i=0, j=g[y].size(); i<g[x].size() && j>=1; i++, j--) // up to 2 times running here
	{
		pair<int, int> xi=g[x][i], yi=g[y][j-1];
		int charxi=xi.first, charyi=yi.first;
		int numxi=xi.second, numyi=yi.second;
		
		if (charxi < charyi) return 1;
		else if (charxi > charyi) return 0;
		else if (numxi != numyi) return 0;
	}
	return 0;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n=read(), m=read();
	char ch=getchar();
	for (int i=1; i<=n; i++)
	{
		while (ch<'a' || ch>'z') ch=getchar();
		for (int j=1; j<=m; j++, ch=getchar()) s[i][ch-'a']++;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=25; j++)
		{
			if (s[i][j]) g[i].push_back(make_pair(j, s[i][j]));
		}
	}
//	for (int i=1; i<=n; i++)
//	{
//		for (auto j : g[i])
//		{
//			cout<<j.first<<':'<<j.second<<' ';
//		}
//		cout<<endl;
//	}
	for (int i=1; i<=n; i++)
	{
		bool jud=1;
		for (int j=1; j<=n; j++)
		{
			if (j==i) continue;
			jud &= less_than(i, j);
		}
		jud ? putchar('1') : putchar('0');
	}
	return 0;
}
/*
5 1
r
t
w
g
j

*/
