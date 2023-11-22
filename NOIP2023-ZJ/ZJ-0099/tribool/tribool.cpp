#include<bits/stdc++.h>
using namespace std;
int a[110000],b[110000];
int f[110000],t[110000];
int find(int i){
	if(f[i]==i){
		assert(t[i]==0);
		return i;
	}
	int u=find(f[i]);
	if(u)t[i]^=t[f[i]];
	else if(f[i])t[i]=t[f[i]];
	f[i]=u;
	return u;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)a[i]=i,b[i]=0;
		while(m--){
			char v[4];
			scanf("%s",v);
			if(v[0]=='+'){
				int i,j;
				scanf("%d%d",&i,&j);
				a[i]=a[j];
				b[i]=b[j];
			}
			if(v[0]=='-'){
				int i,j;
				scanf("%d%d",&i,&j);
				a[i]=a[j];
				b[i]=2-b[j];
			}
			if(v[0]=='T'){
				int i;
				scanf("%d",&i);
			    a[i]=0,b[i]=0;
			}
			if(v[0]=='F'){
				int i;
				scanf("%d",&i);
			    a[i]=0,b[i]=2;
			}
			if(v[0]=='U'){
				int i;
				scanf("%d",&i);
			    a[i]=0,b[i]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)f[i]=i,t[i]=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				int u=find(i);
				f[u]=0;
				t[u]=b[i];
			}
			else{
				int u=find(a[i]),s=find(i);
				if(u==0)f[s]=0,t[s]=t[a[i]];
				else{
					if(s==u){
						if(t[i]^t[a[i]]!=b[i]){
							f[s]=0;
							t[s]=1;
						}
					}
					else f[s]=u,t[s]=t[i]^t[a[i]]^b[i];
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			find(i);
			if(f[i]==0&&t[i]==1)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}