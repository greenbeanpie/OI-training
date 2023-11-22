#include<bits/stdc++.h>
using namespace std;
const int N=3005,M=3005;
int n,m,i,j,flag;
char minn[N][M],maxx[N][M];
signed main(){
	freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>minn[i]+1;
	for(i=1;i<=n;i++){
		sort(minn[i]+1,minn[i]+m+1);
		for(j=1;j<=m;j++) maxx[i][j]=minn[i][m-j+1];
	}
	for(i=1;i<=n;i++){
		flag=1;
		for(j=1;j<=n;j++)
			if(i!=j)
				if(strcmp(minn[i]+1,maxx[j]+1)>=0){
					flag=0;
					break;
				}
		cout<<flag;
	}
	return 0;
}
