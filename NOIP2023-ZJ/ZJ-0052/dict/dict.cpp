#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
const int N=3e3+10;
struct Node{string s;int tag;};
int n,m;
Node a[N<<1];
int ans[N];
int vis[N];
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		sort(a[i].s.begin(),a[i].s.end());
		a[i+n]=a[i];
		reverse(a[i+n].s.begin(),a[i+n].s.end());
		a[i+n].tag=i;a[i].tag=-i;
	}
	sort(a+1,a+2*n+1,[&](const Node&x,const Node&y)
	{
		if(x.s!=y.s)return x.s<y.s;
		return x.tag>y.tag;
	});
	int sum=0;for(int i=2*n;i>=1;i--)
	{
		if(a[i].tag>=0)sum++,vis[a[i].tag]=1;
		else if(sum==n||(sum==n-1&&!vis[-a[i].tag]))ans[-a[i].tag]=1;
	}
	for(int i=1;i<=n;i++)cout<<(char)(ans[i]+'0');cout<<endl;
	return 0;
}
/*
2 2
ab
ab
*/