#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int cnt[N][26],ans[N];
bitset<N> vis;
struct node
{
	int p,t;
	bool operator < (const node &o)const
	{
		if(!t&&!o.t)
		{
			for(int i=0;i<=25;i++)
				if(cnt[p][i]!=cnt[o.p][i])
					return cnt[p][i]>cnt[o.p][i];
			return false;
		}
		else if(t&&o.t)
		{
			for(int i=25;i>=0;i--)
				if(cnt[p][i]!=cnt[o.p][i])
					return cnt[p][i]<cnt[o.p][i];
			return false;
		}
		else if(!t&&o.t)
		{
			int k1=-1,k2=-1;
			for(int i=0;i<=25&&k1==-1;i++)if(cnt[p][i])k1=i;
			for(int i=25;i>=0&&k2==-1;i--)if(cnt[o.p][i])k2=i;
			return k1<k2;
		}
		else
		{
			int k1=-1,k2=-1;
			for(int i=25;i>=0&&k1==-1;i--)if(cnt[p][i])k1=i;
			for(int i=0;i<=25&&k2==-1;i++)if(cnt[o.p][i])k2=i;
			return k1<=k2;
		}
	}
}x[N<<1];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int n,m,t=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++)cnt[i][s[j]-'a']++;
		x[++t]=(node){i,0},x[++t]=(node){i,1};
	}
	sort(x+1,x+t+1);
	for(int i=t;i>=1;i--)
	{
		if(x[i].t)c++,vis[x[i].p]=true;
		else if(c==n||(c==n-1&&!vis[x[i].p]))ans[x[i].p]=1;
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
	return 0;
}