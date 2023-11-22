#include<bits/stdc++.h>
using namespace std;
long long f[10010][1010];
struct chan{
	int x,y,v;
	friend operator <(chan a,chan b){
		return a.x<b.x;
	}
}c[10010];
void check(){
	long long n,m,k,d;
	cin>>n>>m>>k>>d;
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	for(int i=1;i<=m;i++){
		cin>>c[i].x>>c[i].y>>c[i].v;
	}
	sort(c+1,c+m+1);
	for(int i=1;i<=m;i++){
		for(int j=0;j<=k;j++){
			f[i][0]=max(f[i][0],f[i-1][j]);
		}
		if(c[i].y<=k)
			f[i][c[i].y]=max(0ll,f[i][0]-d*c[i].y+c[i].v);
		for(int j=k;j>=0;j++){
			if(j+c[i].x-c[i-1].x>k)continue;
			f[i][j+c[i].x-c[i-1].x]=max(f[i][j+c[i].x-c[i-1].x],
			f[i-1][j]-d*(c[i].x-c[i-1].x)+c[i].v);
		}
	}
	long long ans=0;
	for(int i=0;i<=k;i++){
		ans=max(ans,f[m][i]);
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)check();
	return 0;
}
