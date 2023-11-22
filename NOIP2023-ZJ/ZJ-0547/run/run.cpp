#include<bits/stdc++.h>
using namespace std;
int ans,x,y,z,n,m,k,d,c,t;
struct note{
	int x;int y;int v;
}a[100005];
bool cmp(note xx,note yy)
{
	return xx.x>yy.x||(xx.x=yy.x&&xx.y>yy.y);
}
int dfs(int sum,int xx,int kk,int yy)
{
	if (xx==m) return sum;
	if (a[xx+1].x-a[xx+1].y>yy) return max(dfs(sum+a[xx+1].v,xx+1,a[xx+1].y,a[xx+1].x),dfs(sum,xx+1,kk,yy));
		else if (a[xx+1].x-yy+kk<=k) return max(dfs(sum+a[xx+1].v,xx+1,a[xx+1].x-yy+kk,a[xx+1].x),dfs(sum,xx+1,kk,yy));
			else return dfs(sum,xx+1,kk,yy);
			
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	if (c==17||c==18)
	{
	while (t--)
	{
		cin>>n>>m>>k>>d;
		for (int i=1;i<=m;i++)
		{
			cin>>x>>y>>z;
			if (y<=k) ans+=max(0,z-d*y);
		}
	}
	cout<<ans;
	}
	else{
		while (t--){
			cin>>n>>m>>k>>d;
			for (int i=1;i<=m;i++){
				cin>>a[i].x>>a[i].y>>a[i].v;
				while ((a[i].y>k)&&((a[i].v-d*a[i].y)<=0)){
					m--;
					cin>>a[i].x>>a[i].y>>a[i].v;
				}
				a[i].v=a[i].v-d*a[i].y;
			}
			sort(a+1,a+m+1,cmp);
			cout<<dfs(0,0,0,0);
		}	
	}
	return 0;
}