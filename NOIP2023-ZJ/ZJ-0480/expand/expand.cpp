#include<bits/stdc++.h>
using namespace std;
int ch,n,m,q;
int x[100100],y[100100],px[100100],py[100100];
int dp[2020][2020];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>ch>>n>>m>>q;
	for (int i=1;i<=n;i++)
	cin>>x[i],px[i]=x[i];
	for (int i=1;i<=m;i++)
	cin>>y[i],py[i]=y[i];
	if (x[1]>y[1]&&x[n]<y[m])cout<<0;
	else if(x[1]==y[1]||x[n]==y[m])cout<<0;
	else{ 
		if (x[1]<y[1]&&x[n]<y[m])swap(n,m),swap(x,y);
		dp[0][0]=1;
		for (int i=1;i<=n;i++){
			int w=m+1,pre=-1;
			for (int j=m;j>=1;j--){
				
				if (w>j) w=j+1;
				if (pre>j) pre=-1;
				while(w>1&&y[w-1]<x[i]){
					w--;
					if (dp[i-1][w])pre=w;
				}
				if (pre!=-1||(w<=j&&dp[i-1][w-1]))dp[i][j]=1;
			}
		}
		cout<<dp[n][m];
	}
//	for (int i=1;i<=n;i++)
//			{
//				for (int j=1;j<=m;j++)
//				cout<<dp[i][j]<<"*";
//				cout<<endl;
//			}
	while(q--){
		int xx,yy,kx,ky;
		cin>>kx>>ky;
		for (int i=1;i<=n;i++)
		x[i]=px[i];
		for (int i=1;i<=m;i++)
		y[i]=py[i];
		for (int i=1;i<=kx;i++)
		cin>>xx>>yy,x[xx]=yy;
		for (int i=1;i<=ky;i++)
		cin>>xx>>yy,y[xx]=yy;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		dp[i][j]=0;
		if (x[1]>y[1]&&x[n]<y[m])cout<<0;
		else if(x[1]==y[1]||x[n]==y[m])cout<<0;
		else{ 
			if (x[1]<y[1]&&x[n]<y[m])swap(n,m),swap(x,y);
			dp[0][0]=1;
			for (int i=1;i<=n;i++){
				int w=m+1,pre=-1;
				for (int j=m;j>=1;j--){
					if (w>j) w=j+1;
					if (pre>j) pre=-1;
					while(w>1&&y[w-1]<x[i]){
						w--;
						if (dp[i-1][w])pre=w;
					}
					if (pre!=-1||(w<=j&&dp[i-1][w-1]))dp[i][j]=1;
				}
			}
			cout<<dp[n][m];
		}
	}
}