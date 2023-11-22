#include<bits/stdc++.h>
using namespace std;
constexpr int N=500000,inf=1.1e9;
inline void down(int &x,int y){if(y<x) x=y;}
int n,m,a[N+10],b[N+10],ta[N+10],tb[N+10];
int query(){
	int n=::n,m=::m,*a=::a,*b=::b;
	if(a[1]<b[1]) swap(n,m),swap(a,b);
	int i,max_,min_=inf,pos;
	for(i=1;i<=n;++i) if(a[i]<min_) min_=a[i],pos=i;
	max_=-1,min_=inf;
	int len1=0;
	for(i=1;i<=pos;++i){
		if(a[i]>max_){
			max_=a[i];
			while(len1<m){
				if(b[len1+1]<max_) ++len1,down(min_,b[len1]);
				else break;
			}
		}
		if(a[i]<=min_) return 0;
	}
	int len2=m+1;
	max_=-1,min_=inf;
	for(i=n;i>=pos;--i){
		if(a[i]>max_){
			max_=a[i];
			while(len2>1){
				if(b[len2-1]<max_) --len2,down(min_,b[len2]);
				else break;
			}
		}
		if(a[i]<=min_) return 0;
	}
	if(len1==m||len2==1) return 1;
	else return 0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cid,q;
	cin>>cid>>n>>m>>q;
	int i,j;
	for(i=1;i<=n;++i) cin>>a[i];
	for(i=1;i<=m;++i) cin>>b[i];
	memcpy(ta,a,n+1<<2),memcpy(tb,b,m+1<<2);
	cout<<query();
	for(i=1;i<=q;++i){
		if(i>1) memcpy(a,ta,n+1<<2),memcpy(b,tb,m+1<<2);
		int kx,ky;
		cin>>kx>>ky;
		for(j=1;j<=kx;++j){
			int p,v;
			cin>>p>>v;
			a[p]=v;
		}
		for(j=1;j<=ky;++j){
			int p,v;
			cin>>p>>v;
			b[p]=v;
		}
		cout<<query();
	}
	cout<<'\n';
	return 0;
}
