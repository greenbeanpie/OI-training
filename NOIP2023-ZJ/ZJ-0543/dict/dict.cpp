#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3005],s1[3005],s2[3005];
struct ch{
	char w;
	int id;
}t[3005];
int maxn[30];
int cnt[30];
inline void sort1()
{
	memset(cnt,0,sizeof(cnt));
	memset(maxn,0,sizeof(maxn));
	for(register int i=0;i<m;i++) 
	{
		int pos=int(t[i].w-'a');
		++cnt[pos];
		maxn[pos]=max(maxn[pos],t[i].id);
	}
	int res=0;
	for(register int i=0;i<=25;i++)
	for(register int j=1;j<=cnt[i];j++)
		t[res].w=char(i+97),t[res].id=maxn[i],res++;
	
}
inline void sort2()
{
	memset(cnt,0,sizeof(cnt));
	memset(maxn,0,sizeof(maxn));
	for(register int i=0;i<m;i++) 
	{
		int pos=int(t[i].w-'a');
		++cnt[pos];
		maxn[pos]=max(maxn[pos],t[i].id);
	}
	int res=0;
	for(register int i=25;i>=0;i--)
	for(register int j=1;j<=cnt[i];j++)
		t[res].w=char(i+97),t[res].id=maxn[i],res++;
	
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(register int i=1;i<=n;i++)  cin>>s[i];
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<m;j++)
		t[j].w=s[i][j],t[j].id=j;
		sort1();
		int pmin=0;
		while(pmin<m&&s[i][pmin]==t[pmin].w) pmin++;
		if(pmin==m) s1[i]=s[i];
		else s1[i]=s[i],swap(s1[i][pmin],s1[i][t[pmin].id]);
		//cout<<s1[i]<<endl;
	}
	//cout<<"\n======\n";
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<m;j++)
		t[j].w=s[i][j],t[j].id=j;
		sort2();
		int pmax=0;
		while(pmax<m&&s[i][pmax]==t[pmax].w) pmax++;
		if(pmax==m) s2[i]=s[i];
		else s2[i]=s[i],swap(s2[i][pmax],s2[i][t[pmax].id]);
		//cout<<s2[i]<<endl;
	}
	for(register int i=1;i<=n;i++)
	{
		bool flg=0;
		for(register int j=1;j<=n;j++)
		if(i!=j&&s2[j]<=s1[i]) 
		{
			flg=1;
			break;
		}
		if(flg) cout<<0;
		else cout<<1;
	}
	return 0;
}
