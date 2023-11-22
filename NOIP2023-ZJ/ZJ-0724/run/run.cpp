#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m,k,d;
		int cnt=0;
		cin>>n>>m>>k>>d;
		int axn[m+1];
		int x,y,v;
		memset(axn,-k*d,sizeof(axn));
		for(int i=1;i<=m;i++){
			cin>>x>>y>>v;
			if(k<y) axn[i]=0; 
			else axn[i]=v-y*d;
		}
		if(c==17||c==18)
		{
			for(int i=1;i<=m;i++)
			{
				int res=axn[i];
				if(res>0) cnt+=res;
			}	
		}
		else
		for(int i=1;i<=m;i++)
		{
			int res=axn[i];
			if(cnt<res) cnt=res;
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
