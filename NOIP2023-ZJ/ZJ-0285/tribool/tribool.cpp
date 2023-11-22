#include<bits/stdc++.h>
using namespace std;
int dian,T,n,m,ans,i,x,y,flag[100010],f[100010],c[100010],a[100010],b[100010];
char opt;
void dg(int t){
	int s,pd,i;
	if(t==n+1){
		s=0;pd=1;
		for(i=1;i<=n;i++){
			c[i]=f[i];
			if(f[i]==2)s++;
		}
		for(i=1;i<=m;i++){
			if(flag[i]==0)f[a[i]]=0;
			if(flag[i]==1)f[a[i]]=1;
			if(flag[i]==2)f[a[i]]=2;
			if(flag[i]==3)f[a[i]]=f[b[i]];
			if(flag[i]==4){
				if(f[b[i]]==0)f[a[i]]=1;
				else if(f[b[i]]==1)f[a[i]]=0;
				else if(f[b[i]]==2)f[a[i]]=2;
			}
		}
		for(i=1;i<=n;i++)
			if(f[i]!=c[i]){
				pd=0;
				break;
			}
		for(i=1;i<=n;i++)f[i]=c[i];
		if(pd)ans=min(ans,s);
		return ;
	}
	f[t]=0;
	dg(t+1);
	f[t]=1;
	dg(t+1);
	f[t]=2;
	dg(t+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>dian>>T;
	if(dian<=2){
		while(T--){
			cin>>n>>m;
			for(i=1;i<=m;i++){
				cin>>opt;
				if(opt=='T'){
					flag[i]=0;
					cin>>x;a[i]=x;
				}
				if(opt=='F'){
					flag[i]=1;
					cin>>x;a[i]=x;
				}
				if(opt=='U'){
					flag[i]=2;
					cin>>x;a[i]=x;
				}
				if(opt=='+'){
					flag[i]=3;
					cin>>x>>y;
					a[i]=x;b[i]=y;
				}
				if(opt=='-'){
					flag[i]=4;
					cin>>x>>y;
					a[i]=x;b[i]=y;
				}
			}
			ans=2e9;
			dg(1);cout<<ans<<'\n';
		}
		return 0;
	}
	if(dian==3||dian==4){
		while(T--){
			cin>>n>>m;ans=0;
			for(i=1;i<=n;i++)flag[i]=0;
			for(i=1;i<=m;i++){
				cin>>opt>>x;
				if(opt=='T')flag[x]=0;
				if(opt=='F')flag[x]=1;
				if(opt=='U')flag[x]=2;
			}
			for(i=1;i<=n;i++)
				if(flag[i]==2)
					ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}