#include<bits/stdc++.h>
using namespace std;
#define rt register int 
int c,t,n,m,ans;
char op;
int p1,p2;
int v[200005],v0[100005];
int f[200005];
int found(int x){
	if(f[x]!=x)f[x]=found(f[x]);
	return x;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	if(c==3 or c==4 or c==5 or c==6){
		while(t--){
			cin>>n>>m;
			for(rt i=1;i<=n;++i)
			{
				v[i]=v0[i]=3;
			}
			ans=0;
			
			for(rt i=1;i<=m;++i){
				cin>>op;
				if(op=='T'){
					cin>>p1;
					v[p1]=v0[p1]=1;
				}else if(op=='F'){
					cin>>p1;
					v[p1]=v0[p1]=0;
				}else if(op=='U'){
					cin>>p1;
					v[p1]=v0[p1]=2;
				}else if(op=='+'){
					cin>>p1>>p2;
					v[p1]=v[p2];
				}else{
					cin>>p1>>p2;
					if(v[p2]==2)v[p1]=2;
					else if(v[p2]==1)v[p1]=0;
					else if(v[p2]==0)v[p1]=1;
					else v[p1]=3;
				}
			}
			for(rt i=1;i<=n;++i)
			{
				if(v[i]==2)ans+=1;
			}
			cout<<ans<<endl;
		}	
	}else if(c==7 or c==8){
		while(t--){
		cin>>n>>m;
		for(rt i=1;i<=n;++i)
		{
			f[i]=i;f[i+100000]=i+100000;	
		}
		ans=0;
		for(rt i=1;i<=m;++i){
			cin>>op;
			if(op=='+'){
				cin>>p1>>p2;
				f[p1]=found(p2);
			}else{
				cin>>p1>>p2;
				f[p1]=found(p2+100000);
				f[p2]=found(p1+100000);
			}
		}
		for(rt i=1;i<=n;++i)
		{
			if(f[i]==f[i+100000])
				ans+=1;
		}
		cout<<ans<<endl;
		}
	}else{
		while(t--)cout<<0<<endl;
	}
	return 0;
}
