#include<bits/stdc++.h>
using namespace std;
#define rt register int 
int n,m,flag;
char c[3005][3005];
char cmin[3005];
char cmax[3005];
int ans[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(rt i=1;i<=n;++i)
		cin>>c[i];
	for(rt i=1;i<=n;++i){
		cmin[i]='z';
		cmax[i]='a';
	}
	for(rt i=1;i<=n;++i)
	{
		for(rt j=0;j<m;++j)
		{
			if(cmin[i]>c[i][j])
				cmin[i]=c[i][j];
			if(cmax[i]<c[i][j])
				cmax[i]=c[i][j];
		}
	}
	for(rt i=1;i<=n;++i)
	{
		flag=1;
		for(rt j=1;j<=n;++j)
		{
			if(i==j)continue;
			if(cmax[j]<=cmin[i]){
				flag=0;
				break;
			}
		}
		if(flag)ans[i]=1;
		else ans[i]=0;
	}
	for(rt i=1;i<=n;++i)
		cout<<ans[i];
	return 0;		
}
