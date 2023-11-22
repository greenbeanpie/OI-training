#include<bits/stdc++.h>
using namespace std;
const int N=500020;
int c,n,m,k,d,t,ans;
int en[N];//,con[N],v[N]
struct node{
	int con,v;
};
vector<node> q[120];
void dfs(int now,int days,int num)
{
	if(now>n) return;
	if(q[now].size())
	{
		for(int i=0;i<q[now].size();i++)
		{
			node o=q[now][i];
			if(days>=o.con)
			{
				num+=o.v;
			}
		}
	}
	ans=max(ans,num);
	if(days<k){
		dfs(now+1,days+1,num-d);
		dfs(now+1,0,num);
	}
	else{
		dfs(now+1,0,num);
	}
	return;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c>2) cout<<"114514";
	else{
		for(int yyyyy=1;yyyyy<=t;yyyyy++)
		{
			scanf("%d%d%d%d",&n,&m,&k,&d);//k days d energy
			ans=0;
			for(int i=1;i<=n;i++) q[i].clear();
			for(int i=1;i<=m;i++)
			{
				int b,c;
				scanf("%d%d%d",&en[i],&b,&c);
				node o;
				o.con=b;o.v=c;
				q[en[i]].push_back(o);
			}
			//cout<<"good";
			dfs(1,1,-d);
			dfs(1,0,0);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
