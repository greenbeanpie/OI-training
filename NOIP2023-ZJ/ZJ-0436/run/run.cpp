#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10;
LL f[2000][2000];
LL ans[N];
LL da;
int n,m,k,d;
int x,y,v;
int c,t;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(ans,0,sizeof(ans));
	cin>>n>>m>>k>>d;
	da=0;
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	f[i][j]=(i-j-1)*d;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>v;
		int l=x-y+1;
		for(int j=l;j>=1;j--)
		for(int r=x;r<=n;r++)
		f[j][r]+=v;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(k>=i-j+1)
			ans[i]=max(ans[i],f[j][i]);
			for(int r=j-2;r>=0;r--)
			if(k>=i-j+1){
			ans[i]=max(ans[i],ans[r]+f[j][i]);}
		}
		da=max(ans[i],da);
	}
	cout<<da<<endl;}
}
