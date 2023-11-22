#include<bits/stdc++.h>
using namespace std;
int a[505000],b[505000],A[505000],B[505000];
int c,n,m,q;
int premxA[505000],premxB[505000],premnA[505000],premnB[505000],X[505000],Y[505000];
int N,M;
inline bool solve() {
	premxA[0]=premxB[0]=-1e9;
	premnA[0]=premnB[0]=1e9;
	for(int i=1; i<=N; ++i)
		premxA[i]=max(premxA[i-1],A[i]),
		premnA[i]=min(premnA[i-1],A[i]);
	for(int i=1; i<=M; ++i)
		premxB[i]=max(premxB[i-1],B[i]),
		premnB[i]=min(premnB[i-1],B[i]);
	for(int i=1,ptr=1;i<=M;++i){
		while(ptr<=N&&premxA[ptr]+premnB[i]<=0)
			ptr++;
		Y[i]=ptr-1;
	}
	for(int i=1,ptr=1; i<=N; ++i) {
		while(ptr<=M&&premnA[i]+premxB[ptr]<=0)
			ptr++;
		X[i]=ptr-1;
		if(X[i]&&Y[X[i]]>=i)return 0;
	}
	return 1;
}
inline void check() {
	if((A[1]==B[1])||(A[n]==B[m])||((A[1]<B[1])^(A[n]<B[m])))
		cout<<0;
	else {
		N=n,M=m;
		if(A[1]<B[1])swap(A,B),swap(N,M);
		int mnb=1e9,mxa=-1e9,mna=1e9,mxb=-1e9;
		for(int i=1; i<=M; ++i)
			B[i]=-B[i],mnb=min(mnb,B[i]),mxb=max(mxb,B[i]);
		for(int i=1; i<=N; ++i)
			mxa=max(mxa,A[i]),mna=min(mna,A[i]);
		if(mxa+mnb<=0)cout<<0;
		else if(mxb+mna<=0)cout<<0;
		else {
			bool flag=solve();
			reverse(A+1,A+N+1);
			reverse(B+1,B+M+1);
			flag&=solve();
			cout<<flag;
		}
	}
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; ++i)
		cin>>a[i],A[i]=a[i];
	for(int i=1; i<=m; ++i)
		cin>>b[i],B[i]=b[i];
	check();
	while(q--) {
		int kx,ky;
		cin>>kx>>ky;
		memcpy(A,a,sizeof(a));
		memcpy(B,b,sizeof(b));
		for(int i=1; i<=kx; ++i) {
			int px,vx;
			cin>>px>>vx;
			A[px]=vx;
		}
		for(int i=1; i<=ky; ++i) {
			int py,vy;
			cin>>py>>vy;
			B[py]=vy;
		}
		check();
	}
}