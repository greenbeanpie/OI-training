#include<bits/stdc++.h>
#define ll long long
#define ppi pair<int,int>
using namespace std;
int const gmn=1e5+15;
ll const minff=(ll)1e18+5;


ll mtre[gmn*2+10];
void mquery(int l,int r,ll v){
	for(int i=l;i<=r;i++){
		mtre[i]+=v;
	}
}
ll mmax(int l,int r){
	ll anss=mtre[l];
	for(int i=l+1;i<=r;i++){
		anss=max(anss,mtre[i]);
	}
	return anss;
}
struct N{
	int xi,yi,vi;
	void inin(){
		scanf("%d%d%d",&xi,&yi,&vi);
	}
	friend bool operator <(N a,N b){
		return a.xi<b.xi;
	}
}tasks[gmn*2];
ll dell=0;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int o=1;o<=t;o++){
		dell=0;
		int n,m,k,d;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		memset(mtre,0,sizeof(mtre));
		for(int j=1;j<=m;j++){
			tasks[j].inin();
		}
		sort(tasks+1,tasks+1+m);
		int jj=1;
		for(int i=1;i<=n;i++){
			//(n-i+5)-(n-i+5+k+5)
			int shi=n+5-i,ti=min(n+5-i+k,n+5);
			mtre[shi]=max((ll)0,mmax(shi+1,ti+1));
			while(tasks[jj].xi==i && jj<=m){
				mquery(shi+tasks[jj].yi,ti,tasks[jj].vi);
				jj++;
			}
			mquery(0,shi,d);
			dell+=d;
			//mquery(shi+1,ti,-d);
		}
		cout<<(ll)(mmax(5,5+k)-dell)<<"\n";
	}
	return 0;
}