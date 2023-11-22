#include<bits/stdc++.h>
using namespace std;
int n,m,c,q;
int a[500010],b[500010],ans[70],ya[500010],yb[500010];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>ya[i];
		a[i]=ya[i];
	}
	for(int i=1;i<=m;i++){
		cin>>yb[i];
		b[i]=yb[i];
	}
	if((a[1]-b[1])*(a[n]-b[m])>0){
			ans[1]=1;
		}
		else
		ans[1]=0;
		for(int i=1;i<=n;i++)
		a[i]=ya[i];
		for(int i=1;i<=m;i++){
			b[i]=yb[i];
		}
		
	for(int w=2;w<=q+1;w++){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			int k,num;
			cin>>k>>num;
			a[k]=num;
		}
		for(int i=1;i<=y;i++){
			int k,num;
			cin>>k>>num;
			b[k]=num;
		}
		if((a[1]-b[1])*(a[n]-b[m])>0){
			ans[w]=1;
		}
		else
		ans[w]=0;
		for(int i=1;i<=n;i++)
		a[i]=ya[i];
		for(int i=1;i<=m;i++){
			b[i]=yb[i];
		}
			
	}
	for(int i=1;i<=q+1;i++){
		cout<<ans[i];
	}
	return 0;
}
