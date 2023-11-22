#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,mx;
struct str
{
	int last,v;
};
str chal[100005];
void dfs(int date,int keep,int val)
{
	//cout<<date<<' '<<keep<<' '<<val<<endl;
	if(date>=n+1)
	{
	//cout<<"got "<<val<<endl;
		if(val>mx)
		{
			
			mx=val;
		}
		//cout<<endl;
		return ;
	}
	if(chal[date].v!=-1)
	{
		if(chal[date].last<=keep)
		{
			val+=chal[date].v;
		}
	}
	
	if(keep+1<=k)
	{
		dfs(date+1,keep+1,val-d);
	}
	dfs(date+1,0,val);
	return ;

}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int g=1;g<=t;g++)
	{
		for(int i=0;i<=n;i++)
		{
			chal[i].last=-1;
			chal[i].v=-1;
		}
		mx=INT_MIN;
		//n-day   m-challenge
		//k-limit d-downspeed
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			int xi,yi,vi;
			cin>>xi>>yi>>vi;
			chal[xi].last=yi;
			chal[xi].v=vi;
		}
		dfs(0,0,0);
		cout<<mx<<endl;
	}
	return 0;
}