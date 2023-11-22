#include<bits/stdc++.h>
#define maxn 1010
using namespace std;
int trie[maxn*maxn][30];
int cnt[maxn];
//bool h[maxn*maxn][maxn];
int idx=1;
int a[maxn][maxn];
int b[maxn][maxn];
int n,m;
void insert(int id)
{
	int p=1;
	for(int i=1;i<=m;i++)
	{
		if(!trie[p][b[id][i]])
			trie[p][b[id][i]]=++idx;//cout<<p<<"\n";
		p=trie[p][b[id][i]];
//		h[p][id]=true;
		cnt[p]++;
	}
}
bool check(int id)
{
	int p=1;
	bool sam=true;
	for(int i=1;i<=m;i++)
	{
		int nxt=0;
		for(int j=0;j<26;j++)
		{
			if(!trie[p][j])
				continue;
//			if(j==b[id][i])
			if(j==b[id][i]&&sam)
			{
				if(cnt[trie[p][j]]>1)
				{
					if(j>a[id][i])
						return true;
					if(j<a[id][i])
						return false;
					nxt=j;
					break;
				}
				else continue;
			}
			else
			{
				if(j>a[id][i])
					return true;
				if(j<a[id][i])
					return false;
				nxt=j;
				break;
			}
		}
		if(nxt!=b[id][i])
			sam=false;
		p=trie[p][nxt];
	}
	return false;
}
string str;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		for(int j=1;j<=m;j++)
			a[i][j]=str[j-1]-'a';
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i][j]=a[i][j];
	for(int i=1;i<=n;i++)
		sort(a[i]+1,a[i]+1+m),
		sort(b[i]+1,b[i]+1+m,[](int x,int y){
			return x>y;
		});
	for(int i=1;i<=n;i++)
		insert(i);
	for(int i=1;i<=n;i++)
		cout<<check(i);
	return 0;
}