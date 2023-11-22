#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c,n,m,q;
int a[100001],b[100001];
int ca[100001],cb[100001];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i,j;
	cin>>c>>n>>m>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	if((a[1]-b[1])*(a[n]-b[m])<=0) cout<<0;
	else cout<<1;
	
//	for(i=1;i<=n;i)
	
	for(i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		
		for(j=1;j<=n;j++){
			ca[j]=a[j];
		}
		for(j=1;j<=m;j++){
			cb[j]=b[j];
		}
		
		for(j=1;j<=x;j++){
			int g,h;
			cin>>g>>h;
			ca[g]=h;
		}
		for(j=1;j<=y;j++){
			int g,h;
			cin>>g>>h;
			cb[g]=h;
		}
		if((ca[1]>cb[1])^(ca[n]<cb[m])) cout<<1;
		else cout<<0;
	}
		fclose(stdin);
	fclose(stdout);
	return 0;
}