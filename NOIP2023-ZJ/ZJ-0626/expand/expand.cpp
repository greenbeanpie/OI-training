#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int point,n,m,Q,X[N],Y[N],kx,ky,p,v;
int x[N],y[N];
string res;
bool flag,ans;
void init(){
	for(int i=1;i<=n;i++)x[i]=X[i];
	for(int i=1;i<=m;i++)y[i]=Y[i];
	ans=0;
}
void dfs(int p,int l,int r){
//	cout<<p<<"==="<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++){
		if(x[p]==y[i])return;
		if(flag&&x[p]<y[i])return;
		if(!flag&&x[p]>y[i])return;
	}
	if(p==n)ans=1;
	for(int i=min(m,r+1);i<=m;i++){
		dfs(p+1,r,i);
	}
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>point>>n>>m>>Q;
	for(int i=1;i<=n;i++){
		cin>>X[i];
	}
	for(int i=1;i<=m;i++){
		cin>>Y[i];
	}
	init();
	if(x[1]>y[1])flag=1;
	else flag=0;
	if(flag&&x[n]<=y[m]){
		res+="0";
	}else if(!flag&&x[n]>=y[m]){
		res+="0";
	}else{
		for(int i=1;i<=m;i++){
			dfs(1,1,i);
			if(ans){
				res+="1";break;
			}
		}
		if(!ans)res+="0";
	}
	while(Q--){
		init();
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++){
			cin>>p>>v;
			x[p]=v;
		}
		for(int i=1;i<=ky;i++){
			cin>>p>>v;
			y[p]=v;
		}
		if(x[1]>y[1])flag=1;
		else flag=0;
		if(flag&&x[n]<=y[m]){
			res+="0";continue;
		}else if(!flag&&x[n]>=y[m]){
			res+="0";continue;
		}
		for(int i=1;i<=m;i++){
			dfs(1,1,i);
			if(ans){res+="1";break;}
		}
		if(!ans)res+="0";
	}
	cout<<res;
	return 0;
}
//11:49 
