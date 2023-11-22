#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return f*s;
}
int c,n,m,q,x[500005],y[500005];
int xx_15[500005],yy_15[500005];
bool dp[2005][2005];
void test_15(){
	if(x[1]==y[1]||x[n]==y[m]){
		printf("0");
	}
	else if(x[1]<y[1]&&x[n]>y[m]){
		printf("0");
	}
	else if(x[1]>y[1]&&x[n]<y[m]){
		printf("0");
	}
	else{
		memset(dp,false,sizeof(dp));
		dp[0][0]=true;
		bool bl;
		if(x[1]<y[1]) bl=false;
		else bl=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(dp[i-1][j-1]==true){
					if(bl==false&&x[i]<y[j]) dp[i][j]=true;
					else if(bl==true&&x[i]>y[j]) dp[i][j]=true;
				}
				if(dp[i][j-1]==true){
					if(bl==false&&x[i]<y[j]) dp[i][j]=true;
					else if(bl==true&&x[i]>y[j]) dp[i][j]=true;
				}
				if(dp[i-1][j]==true){
					if(bl==false&&x[i]<y[j]) dp[i][j]=true;
					else if(bl==true&&x[i]>y[j]) dp[i][j]=true;
				}
			}
		}
		cout<<dp[n][m];
	}
	while(q--){
		int kx=read(),ky=read();
		memcpy(xx_15,x,sizeof(x));
		memcpy(yy_15,y,sizeof(y));
		for(int i=1;i<=kx;i++){
			int p=read(),v=read();
			xx_15[p]=v;
		}
		for(int i=1;i<=ky;i++){
			int p=read(),v=read();
			yy_15[p]=v;
		}
		if(xx_15[1]==yy_15[1]||xx_15[n]==yy_15[m]){
			printf("0");
		}
		else if(xx_15[1]<yy_15[1]&&xx_15[n]>yy_15[m]){
			printf("0");
		}
		else if(xx_15[1]>yy_15[1]&&xx_15[n]<yy_15[m]){
			printf("0");
		}
		else{
			memset(dp,false,sizeof(dp));
			dp[0][0]=dp[0][1]=dp[1][0]=true;
			bool bl;
			if(xx_15[1]<yy_15[1]) bl=false;
			else bl=true;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(dp[i-1][j-1]==true){
						if(bl==false&&xx_15[i]<yy_15[j]) dp[i][j]=true;
						else if(bl==true&&xx_15[i]>yy_15[j]) dp[i][j]=true;
					}
					if(dp[i][j-1]==true){
						if(bl==false&&xx_15[i]<yy_15[j]) dp[i][j]=true;
						else if(bl==true&&xx_15[i]>yy_15[j]) dp[i][j]=true;
					}
					if(dp[i-1][j]==true){
						if(bl==false&&xx_15[i]<yy_15[j]) dp[i][j]=true;
						else if(bl==true&&xx_15[i]>yy_15[j]) dp[i][j]=true;
					}
				}
			}
			cout<<dp[n][m];
		}
	}
}
void test_res(){
	if(x[1]==y[1]||x[n]==y[m]){
		printf("0");
	}
	else if(x[1]<y[1]&&x[n]>y[m]){
		printf("0");
	}
	else if(x[1]>y[1]&&x[n]<y[m]){
		printf("0");
	}
	else{
		printf("1");
	}
	while(q--){
		int kx=read(),ky=read();
		memcpy(xx_15,x,sizeof(x));
		memcpy(yy_15,y,sizeof(y));
		for(int i=1;i<=kx;i++){
			int p=read(),v=read();
			xx_15[p]=v;
		}
		for(int i=1;i<=ky;i++){
			int p=read(),v=read();
			yy_15[p]=v;
		}
		if(xx_15[1]==yy_15[1]||xx_15[n]==yy_15[m]){
			printf("0");
		}
		else if(xx_15[1]<yy_15[1]&&xx_15[n]>yy_15[m]){
			printf("0");
		}
		else if(xx_15[1]>yy_15[1]&&xx_15[n]<yy_15[m]){
			printf("0");
		}
		else{
			printf("1");
		}
	}  
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	for(int i=1;i<=m;i++){
		y[i]=read();
	}
	if(c<=7){
		test_15();
		return 0;
	}
	else{
		test_res();
		return 0;
	}
}