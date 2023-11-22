#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define endl "\n"
using namespace std;
const int N=15,inf=1e9,M=1e5+5;
int C,T;
int n,m,ans=inf;
int a[M],b[N];
struct node{
	char op;
	int x,y;
}q[M];
void pd(){
	FOR(i,1,m){
		int x=q[i].x,y=q[i].y;
		if(q[i].op=='+') a[x]=a[y];
		else if(q[i].op=='-') a[x]=-a[y];
		else{
			if(q[i].op=='T') a[x]=1;
			else if(q[i].op=='F') a[x]=-1;
			else a[x]=0;
		}
	}
	int res=0;
	FOR(i,1,n){
		if(a[i]==0) res++;
		if(a[i]!=b[i]) return;
	} 
	ans=min(res,ans);
}
void dfs(int c){
	if(c==n+1){
		pd();
		FOR(i,1,n) a[i]=b[i];
		return;
	}
	FOR(i,-1,1){
		a[c]=b[c]=i;
		dfs(c+1);
	}
}
void sol1(){
	while(T--){
		ans=inf;
		cin>>n>>m;
		FOR(i,1,m){
			cin>>q[i].op;
			if(q[i].op=='+'||q[i].op=='-'){
				cin>>q[i].x>>q[i].y;
			}else{
				cin>>q[i].x;
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
}
void sol2(){
	while(T--){
		ans=0;
		cin>>n>>m;
		FOR(i,1,n) a[i]=2;
		FOR(i,1,m){
			char op;
			int j;
			cin>>op>>j;
			if(op=='T') a[j]=1;
			else if(op=='F') a[j]=-1;
			else a[j]=0;
		}
		FOR(i,1,n) if(a[i]==0) ans++;
		cout<<ans<<endl;
	}
}
//void sol3(){
//	while(T--){
//		ans=0;
//		cin>>n>>m;
//		FOR(i,1,n) a[i]=2;
//		FOR(i,1,m){
//			cin>>q[i].op;
//			if(q[i].op=='+'){
//				int x,y;
//				cin>>x>>y;
//				q[i].x=x,q[i].y=y;
//				a[x]=a[y];
//			}else{
//				int x;
//				cin>>x;
//				q[i].x=x;
//				a[x]=0;
//			}
//		}
//		FOR(i,1,m){
//			if(q[i].op=='+'){
//				int x=q[i].x,y=q[i].y;
//				a[x]=a[y];
//			}else{
//				int x=q[i].x;
//				a[x]=0;
//			}
//		}
//		FOR(i,1,n) if(a[i]==0) ans++;
////		FOR(i,1,n) cout<<a[i]<<" ";
////		cout<<endl;
//		cout<<ans<<endl;
//	}
//}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>C>>T;
	if(C==1||C==2){
		sol1();
		return 0;
	}
	if(C==3||C==4){
		sol2();
		return 0; 
	}
//	if(C==5||C==6){
//		sol3();
//		return 0;
//	}
	return (0-0);
}

