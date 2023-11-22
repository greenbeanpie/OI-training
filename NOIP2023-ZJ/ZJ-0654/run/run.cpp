#include <bits/stdc++.h>
using namespace std;
struct R
{
	int x,y,v;
};
int dp[100005][2];
map<int,int> ds;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,m,d,k;
		scanf("%d%d%d%d",&n,&m,&d,&k);
		vector<R> rs(m);
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&rs[i].x,&rs[i].y,&rs[i].v);
		sort(rs.begin(),rs.end(),[](const R &a,const R &b){
			return a.v>b.v;
		});
		int res=0;
		ds[rs[0].x-rs[0].y]=rs[0].x;
		for(int i=1;i<m;i++)
		{
//			res+=rs[i].v-k*rs[i].y;
			bool f=false;
			auto a=rs[i];
			for(auto i=ds.begin();i!=ds.end();i++)
			{
				if(i->first<=a.x-a.y&&i->second>=a.x-a.y)
				{
					if(a.x-i->first<d)
					{
						i->second=a.x;
						f=true;
						break;
					}
				}
				if(i->first<=a.x&&i->second>=a.x)
				{
					if(i->second-(a.x-a.y)<d)
					{
						int t=i->second;
						ds.erase(i);
						ds[a.x-a.y]=t;
						f=true;
						break;
					}
				}
			}
			if(f) res+=rs[i].v-k*rs[i].y;
		}
		printf("%d\n",res);
	}
	fclose(stdin);
	fclose(stdout);
}
