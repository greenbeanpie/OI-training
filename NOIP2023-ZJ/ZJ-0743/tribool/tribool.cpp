#include<bits/stdc++.h>
using namespace std;
int st1[10005][100],top[10005]={0};
int c,n,m,t,tmp;
int ans[10005]={0};
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==1 ||c==2){//d1d-bao li mo ni
		for(int i=1;i<=t;i++){
			cin>>n>>m;
			char c1;
			int x,y,cnt=0;
			for(int j=1;j<=m;j++){
				cin>>c1>>x;
				if(c1=='U')
					ans[x]=3;
				if(c1=='T')
					ans[x]=1;
				if(c1=='F')
					ans[x]=2;
				if(c1=='-')
				{
					cin>>y;
					if(ans[y]==1)
						ans[x]=2;
					if(ans[y]==2)
						ans[x]=1;
					if(ans[y]==3)
						ans[x]=3;
				}
				if(c1=='+'){
					cin>>y;
					if(ans[y]==3)
						ans[x]=3;
					else
						ans[x]=ans[y];
				}
			}
			for(int j=1;j<=n;j++){
				if(ans[j]==3)
					cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	else if(c==3||c==4){//d2d-panduanchuzhi
		for(int i=1;i<=t;i++){
			cin>>n>>m;
			char c1;
			int x,cnt=0;
			for(int j=1;j<=m;j++){
				cin>>c1>>x;
				if(c1=='T')
					ans[x]=1;
				if(c1=='F')
					ans[x]=2;
				if(c1=='U')
					ans[x]=3;
			}
			for(int j=1;j<=n;j++){
				if(ans[j]==3)
					cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	else if(c==5||c==6){//d3d-shifoubeifuzhi
		for(int i=1;i<=t;i++){
			cin>>n>>m;
			char c1;
			int x,y,cnt=0;
			for(int j=1;j<=m;j++){
				cin>>c1>>x;
				if(c=='U')
					ans[x]=3;
				else{
					cin>>y;
					if(ans[y]==3)
						ans[x]=3;
				}
			}
			for(int j=1;j<=n;j++){
				if(ans[j]==3)
					cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
