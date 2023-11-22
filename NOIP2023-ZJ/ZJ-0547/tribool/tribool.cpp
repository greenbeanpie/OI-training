#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,ans,a[100050],x[100050],y[100050];
char ch[100050];
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	if (c==3||c==4){
		while (t--){
			ans=0;
			memset(a,0,sizeof(a));
			cin>>n>>m;
			for (int i=1;i<=m;i++){
				cin>>ch[i]>>x[i];
				if (a[x[i]]==0){
					a[x[i]]=1;
				}
			}
			cout<<ans<<"\n";
		}
	}
	/*if (c==5||c==6){
		while (t--){
			ans=0;
			memset(a,0,sizeof(a));
			cin>>n>>m;
			for (int i=1;i<=m;i++){
				cin>>ch[i];
				if (ch[i]=='U') {cin>>x[i];a[x[i]]++;}
					else{
						cin>>x[i]>>y[i];
						if (a[y[i]]>0) a[x]++;
					}
			}
			for (int i=1;i<=m;i--){
				if (ch[i]=='U'){
					a[x[i]]--;
				}
				if (ch[i]=='+'){
					if (a[y[i]]==1&&a[x[i]]==0){
						a[x[i]]=1;
					}
					if (a[x[i]]==&&a[y[i]]==){
						a[x[i]]=0;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}*/
}