#include<bits/stdc++.h>
using namespace std;
int n,m,K,d,c,t;
bool sy[100005];
int o[100005];
int e[100005];
long long ans;
struct node{
	int x,y,v,s;
}a[100005];
bool cmp2(node a,node b)
{
	return a.v-a.y*d>=b.v-b.y*d;
}
bool cmp1(node a,node b)
{
	return a.s>b.s;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	cin>>n>>m>>K>>d;
	int i=0;
	while(m)
	{
		m--;
		cin>>a[++i].x>>a[i].y>>a[i].v;
		a[i].s=a[i].x-a[i].y+1;
		if(a[i].y*d-a[i].v>=0)
			i--;
		else if(a[i].y>K)
			i--;
	}
	for(int k=1;k<=i;k++)
	{
		ans+=a[i].y*d-a[i].v+d;
	}
	cout<<ans<<endl;
		return 0;
}
