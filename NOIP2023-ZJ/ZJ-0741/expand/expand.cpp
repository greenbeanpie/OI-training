#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,q,kx,ky,px,vx,py,vy;
int q1[N],q2[N],qw1[N],qw2[N];

void sett(){
	for(int i=1;i<=n;i++)qw1[i]=q1[i];
	for(int i=1;i<=m;i++)qw2[i]=q2[i];
}

void fun(){
	if(n==1&&m==1){
		if(qw1[1]!=qw2[1])cout<<1;
		else cout<<0;
		return;
	}
	if(qw1[1]==qw2[1]||qw1[n]==qw2[m]){
		cout<<0;
		return;
	}
	if((qw1[1]>qw2[1]&&qw1[n]<qw2[m])||(qw1[1]<qw2[1]&&qw1[n]>qw2[m])){
		cout<<0;
		return;
	}
	cout<<1;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>q1[i];
	for(int i=1;i<=m;i++)cin>>q2[i];
	sett();
	fun();
	for(int i=1;i<=q;i++){
		cin>>kx>>ky;
		sett();
		for(int j=1;j<=kx;j++){
			cin>>px>>vx;
			qw1[px]=vx;
		}
		for(int j=1;j<=ky;j++){
			cin>>py>>vy;
			qw2[py]=vy;
		}
		fun();
	}
	return 0;
}
