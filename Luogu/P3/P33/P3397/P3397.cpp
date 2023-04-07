#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int nmap[++n][n]={0};
	for(int i=0;i<m;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int l=x1;l<=x2;l++){
			for(int r=y1;r<=y2;r++){
				nmap[l][r]++;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			cout << nmap[i][j] << " ";
		}
		
		cout << endl;
	}
	return 0;
}