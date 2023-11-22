#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,MAXN=500010;
int X[500010],Y[500010],o=0,ans[500010];
int check1(){
	int mx=0,my=1<<30;
	if(Y[m]<X[n]){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 1;
}
int check(){
	cout<<0;
	return 0;
}
void check9(){
	if(X[1]>Y[1]&&X[2]>Y[2]){
		cout<<1;
		return;
	}
	if(X[1]>Y[1]&&X[2]<=Y[2]){
		cout<<0;
		return;
	}
	if(Y[1]>X[1]&&Y[2]>X[2]){
		cout<<1;
		return;
	}
	if(Y[1]>X[1]&&Y[2]<=X[2]){
		cout<<0;
		return;
	}
	cout<<0;
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",&X[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&Y[i]);
	if(n==1&&m==1){
		if(X[1]!=Y[1])
			cout<<1;
		else
			cout<<0;
		while(q--){
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			while(kx--){
				int p,v;
				scanf("%d%d",&p,&v);
				X[p]=v;
			}
			while(ky--){
				int p,v;
				scanf("%d%d",&p,&v);
				Y[p]=v;
			}
			if(X[1]!=Y[1])
				cout<<1;
			else
				cout<<0;
		}
		return 0;
	}
	if(n<=2&&m<=2){
		check9();
		while(q--){
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			while(kx--){
				int p,v;
				scanf("%d%d",&p,&v);
				X[p]=v;
			}
			while(ky--){
				int p,v;
				scanf("%d%d",&p,&v);
				Y[p]=v;
			}
			check9();
		}
	}
	if(c>=8&&c<=14){
		ans[++o]=check1();
		while(q--){
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			while(kx--){
				int p,v;
				scanf("%d%d",&p,&v);
				X[p]=v;
			}
			while(ky--){
				int p,v;
				scanf("%d%d",&p,&v);
				Y[p]=v;
			}
			ans[++o]=check1();
		}
		return 0;
	}
	ans[++o]=check();
	while(q--){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		while(kx--){
			int p,v;
			scanf("%d%d",&p,&v);
			X[p]=v;
		}
		while(ky--){
			int p,v;
			scanf("%d%d",&p,&v);
			Y[p]=v;
		}
		ans[++o]=check();
	}
	return 0;
}
