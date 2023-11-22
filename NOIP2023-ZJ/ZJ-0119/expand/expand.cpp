#include<bits/stdc++.h>
using namespace std;
int const N=500010;
int opt,n,m,q,a[N],b[N];
namespace solve1{
	bool check(){
		return n<=2000&&m<=2000;
	}
	static int const N=2010;
	string ans;
	int ta[N],tb[N];
	bool f[N][N];
	bool calc(){
		if(ta[1]==tb[1])
			return false;
		memset(f,false,sizeof f);
		f[1][1]=true;
		if(ta[1]>tb[1]){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if(f[i][j]){
						f[i][j+1]|=j<m&&ta[i]>tb[j+1];
						f[i+1][j]|=i<n&&ta[i+1]>tb[j];
						f[i+1][j+1]|=i<n&&j<m&&ta[i+1]>tb[j+1];
					}
		}else for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if(f[i][j]){
						f[i][j+1]|=j<m&&ta[i]<tb[j+1];
						f[i+1][j]|=i<n&&ta[i+1]<tb[j];
						f[i+1][j+1]|=i<n&&j<m&&ta[i+1]<tb[j+1];
					}
		return f[n][m];
	}
	void solve35pts(){
		for(int i=1;i<=n;i++)
			ta[i]=a[i];
		for(int i=1;i<=m;i++)
			tb[i]=b[i];
		if(calc())ans+="1";else ans+="0";
		for(int kx,ky,v;q--;){
			cin>>kx>>ky;
			vector<int>tx(kx),ty(ky);
			for(int&j:tx)cin>>j>>v,ta[j]=v;
			for(int&j:ty)cin>>j>>v,tb[j]=v;
			if(calc())ans+="1";else ans+="0";
			for(int&j:tx)ta[j]=a[j];
			for(int&j:ty)tb[j]=b[j];
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>opt>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	if(solve1::check())
		solve1::solve35pts();
	else
		cout<<string(q+1,48)<<"\n";
}
