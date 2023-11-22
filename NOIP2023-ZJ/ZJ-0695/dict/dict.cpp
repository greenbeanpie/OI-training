#include<bits/stdc++.h>
using namespace std;
#define re register
#define N 3005
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >heap;
string s;
int maxx[N],minn[N];
int n,m;
bool check(int x,int i)
{
	pii u=heap.top();
	if(i!=u.se)
	{
		if(x<u.fi) return true;
		else
		{
			return false;
		}
	}else
	{
		heap.pop();
		pii v=heap.top();
		heap.push(u);
		if(x<v.fi) return true;
		else
		{ 	
			return false;
		}
	}
	return false;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(re int i=1;i<=n;++i)
	{
		cin>>s;
		int now_max=s[0]-'a',now_min=s[0]-'a';
		for(re int j=0;j<m;++j)
		{
			now_max=max(now_max,s[j]-'a');
			now_min=min(now_min,s[j]-'a');
		}
		
		maxx[i]=now_max;
		heap.push(mp(maxx[i],i));
		minn[i]=now_min;
	}
	string ans="";
	for(re int i=1;i<=n;i++)
	{
		int now=minn[i];
		if(check(now,i)) ans=ans+'1';
		else 
		{
			ans=ans+'0';
		}
	}
	cout<<ans<<"\n";
	return 0;
}
