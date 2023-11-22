#include<bits/stdc++.h>
using namespace std;
int n,m,N,M,C,T,a[500010],b[500010],A[500010],B[500010],f[2010][2010];
inline bool check(){
	if(A[1]==B[1]||A[N]==B[M])return 0;
	if(A[1]<B[1]){
		for(int i=1;i<=N||i<=M;i++)swap(A[i],B[i]);
		swap(N,M);
	}
	if(A[N]<=B[M])return 0;
	for(int i=0;i<=2000;i++)
	for(int j=0;j<=2000;j++)
	f[i][j]=0;
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++){
		if(i==1&&j==1){f[i][j]=1;continue;}
		if(A[i]>B[j])f[i][j]=f[i-1][j]||f[i][j-1]||f[i-1][j-1];
	}
	return f[N][M];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	N=n,M=m;
	for(int i=1;i<=n;i++)A[i]=a[i];
	for(int i=1;i<=m;i++)B[i]=b[i];
	if(check())cout<<1;
	else cout<<0;
	for(int i=1;i<=max(n,m);i++)A[i]=B[i]=0;
	while(T--){
		N=n,M=m;
	    for(int i=1;i<=n;i++)A[i]=a[i];
	    for(int i=1;i<=m;i++)B[i]=b[i];
	    int X,Y;
	    cin>>X>>Y;
	    for(int i=1,x,y;i<=X;i++)cin>>x>>y,A[x]=y;
	    for(int i=1,x,y;i<=Y;i++)cin>>x>>y,B[x]=y;
	    if(check())cout<<1;
	    else cout<<0;
	    for(int i=1;i<=max(n,m);i++)A[i]=B[i]=0;
	}
	return 0;
}