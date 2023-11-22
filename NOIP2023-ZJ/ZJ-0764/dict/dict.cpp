#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
string s[N],mins[N],maxs[N];
//map<string,int> mp;
struct node{
	int val,id;
	friend bool operator > (const node &a,const node &b)
	{
		if(a.val==b.val) return a.id<b.id;
		return a.val>b.val;
	}
	friend bool operator < (const node &a,const node &b)
	{
		if(a.val==b.val) return a.id<b.id;
		return a.val<b.val;
	}
}fz[N];
bool cmp(node a,node b)
{
	return a>b;
}
string doit(string sm,int md)
{
	for(int i=0;i<sm.size();i++)
	{
		fz[i].val=sm[i]-'a';
		fz[i].id=i;
	}
	if(md) sort(fz,fz+sm.size(),cmp);
	else sort(fz,fz+sm.size());
	for(int i=0;i<sm.size();i++)
	{
		if(i!=fz[i].id)
		{
			int righti=i;
			while(fz[i+1].val==fz[i].val) i++;
			char now=sm[righti];
			sm[righti]=sm[fz[i].id];
			sm[fz[i].id]=now;
			break;
		}
	}
	return sm;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	iostream::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		mins[i]=doit(s[i],0);
		//cout<<mins[i]<<"\n";
		maxs[i]=doit(s[i],1);
		//cout<<maxs[i]<<"\n";
		//return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(mins[i]>=maxs[j])
			{
				flag=0;
				break;
			}
		}
		cout<<flag;
		/*mp.clear();
		//mp[mins[i]]=i;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			mp[maxs[j]]=j;
		}
		for(auto j:mp)
		{
			if(j.second==i) cout<<1;
			else cout<<0;
			break;
		}*/
	}
	/*
	for(int i=1;i<=n;i++)
	{
		mp.erase(s[i]);
		doit(s[i],0);
		mp[s[i]]=i;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			else
			{
				mp.erase(s[j]);
				doit(s[j],1);
				mp[s[j]]=j;
			}
		}
		int cnt=0;
		for(auto v:mp)
		{
			if(v.second==i)
			{
				if(cnt==0) ans[i]=1;
				else ans[i]=0;
				break;
			}
			cnt++;
		}
		redo();
	}*/
	//for(int i=1;i<=n;i++) cout<<ans[i];
}
