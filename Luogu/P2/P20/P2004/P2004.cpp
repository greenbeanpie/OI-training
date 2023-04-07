#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("P2004.in","r",stdin);
    #endif
	int n,m,c;
	cin  >> n >> m >> c;
	int nmap[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> nmap[i][j];
		}
	}
	int f[n+1][m+1];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+nmap[i][j];
		}
	}
	int maxinum=INT_MIN,maxx=-1,maxy=-1;
	for(int i=c;i<=n;i++){
		for(int j=c;j<=m;j++){
			if(maxinum<f[i][j]-f[i-c][j]-f[i][j-c]+f[i-c][j-c]){
				maxinum=f[i][j]-f[i-c][j]-f[i][j-c]+f[i-c][j-c];
				maxx=i-c+1;
				maxy=j-c+1;
			}
		}
	}
	cout << maxx<< " " << maxy;
	return 0;
}