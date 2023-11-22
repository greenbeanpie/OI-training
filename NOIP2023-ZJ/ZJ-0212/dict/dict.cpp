#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[3005][27],id[3005];
bool cmp(int x,int y)
{
	for(int i=25;i>=0;i--)
	{
		if(cnt[x][i]!=cnt[y][i]) return cnt[x][i]<cnt[y][i];
	}
	return 0;
}
bool check(int x,int y)
{
	int i=0,j=25;
	while(cnt[x][i]==0) i++;
	while(cnt[y][j]==0) j--;
	if(i!=j) return i<j;
	else return 0;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(auto c:s)
		{
			cnt[i][c-'a']++;
		}
		id[i]=i;
		// if(i==255) cerr<<s<<"\n";
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		bool f=1;
		for(int j=1;j<=3;j++)
		{
			if(id[j]!=i) f&=check(i,id[j]);
		}
		cout<<f;
	}
}