#include<bits/stdc++.h>
using namespace std;
int x[100010],y[100010];
int n,m;
void check(){
	if(n==1&&m==1){
		if(x[1]==y[1])
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}else if(n==1&&m==2){
		if(x[1]>y[1]&&x[1]>y[2])
			cout<<1<<endl;
		else if(x[1]<y[1]&&x[1]<y[2])
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}else if(n==2&&m==1){
		if(x[1]>y[1]&&x[2]>y[1])
			cout<<1<<endl;
		else if(x[1]<y[1]&&x[2]<y[1])
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}else if(n==2&&m==2){
		if(x[1]>y[1]&&x[2]>y[2])
			cout<<1<<endl;
		else if(x[1]<y[1]&&x[2]<y[2])
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	return ;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
	check();
	while(q--){
		int kx,ky;
		cin>>kx>>ky;
		while(kx--){
			int dx,dy;
			cin>>dx>>dy;
			x[dx]=dy;
		}
		while(ky--){
			int dx,dy;
			cin>>dx>>dy;
			y[dx]=dy;
		}
		check();
	}
	return 0;
}