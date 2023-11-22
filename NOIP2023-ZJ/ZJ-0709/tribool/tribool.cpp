#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,ans,fa[100010];
char x;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int e=1;e<=t;e++){
		ans=0;
		cin>>n>>m;
		if(c==3 or c==4){
			char a[100010];
			int y;
			for(int i=1;i<=m;i++){
				cin>>x;
				cin>>y;
				a[y]=x;
			}
			for(int j=1;j<=n;j++){
				if (a[j]=='U') ans+=1;
			}
			cout<<ans<<endl;
		}
		else if (c==6 or c==5){
			bool b1[100010],b2[100010];
 			memset(b1,0,sizeof(b1));
			memset(b2,0,sizeof(b2));
			int u,v;
			for(int i=1;i<=m;i++){
				cin>>x;
				if (x=='U') {
					cin>>u;
					b1[u]=1;
				}
				else{
					cin>>u>>v;
					if (b1[v])
						b1[u]=1;
					else
						b1[u]=0;
 				}
			}
			cout<<ans<<endl;
		}
		else{
			cout<<e<<endl;
		}
	}
}
