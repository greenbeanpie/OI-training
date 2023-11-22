#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fd(i,x,y,z) for(ll i=x;i>=y;i-=z)
ll c,n,m,q;
ll cas=0;
ll a[2005],b[2005];
ll kx[500005],kxx[500005];
ll ky[500005],kyy[500005];
ll s[66],tp;
bool dp[2005][2005];
void solve(){
	if(n<=2000&&m<=2000){
		cas++;
		//a>b
//		printf("%lld:\n",cas);
//		f(i,1,n,1){
//			printf("%lld ",a[i]);
//		}
//		printf("\n");
//		f(i,1,m,1){
//			printf("%lld ",b[i]);
//		}
//		printf("\n");
		dp[0][0]=1;
		f(i,1,n,1){
			f(j,1,m,1){
//				if(i>1){
//					dp[i][j]|=(dp[i-1][j]&(a[i]>b[j]));
//				}
//				if(j>1){
//					dp[i][j]|=(dp[i][j-1]&(a[i]>b[j]));
//				}
//				if(i>1&&j>1){
//					dp[i][j]|=(dp[i-1][j-1]&(a[i]>b[j]));
//				}
//				if(i==j&&i==1){
//					dp[i][j]=(a[i]>b[j]);
//				}
				bool jia=(dp[i-1][j]|dp[i-1][j-1]|dp[i][j-1]);
				bool bj=(a[i]>b[j]);
				dp[i][j]=jia&bj;
				//printf("%lld ",dp[i][j]);
			}
		//	printf("\n");
		}
		if(dp[n][m]){
			s[++tp]=1;
			memset(dp,0,sizeof(dp));
		}
		else{
			// b>a
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			f(i,1,n,1){
				f(j,1,m,1){
					bool jia=(dp[i-1][j]|dp[i-1][j-1]|dp[i][j-1]);
					bool bj=(a[i]<b[j]);
					dp[i][j]=jia&bj;
					//printf("%lld ",dp[i][j]);
				}
				//printf("\n");
			}
			//printf("\n");
			if(dp[n][m]){
				s[++tp]=1;
			}
			else{
				s[++tp]=0;
			}
		}
		memset(dp,0,sizeof(dp));
	}
	else{
		s[++tp]=0;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	f(i,1,n,1){
		scanf("%lld",&a[i]);
	}
	f(i,1,m,1){
		scanf("%lld",&b[i]);
	}
	solve();
	while(q--){
		ll xx,yy;
		scanf("%lld%lld",&xx,&yy);
		f(i,1,xx,1){
			scanf("%lld%lld",&kx[i],&kxx[i]);
			swap(a[kx[i]],kxx[i]);
		}
		f(i,1,yy,1){
			scanf("%lld%lld",&ky[i],&kyy[i]);
			swap(b[ky[i]],kyy[i]);
		}
		solve();
		f(i,1,xx,1){
			swap(a[kx[i]],kxx[i]);
		}
		f(i,1,yy,1){
			swap(b[ky[i]],kyy[i]);
		}
	}
	f(i,1,tp,1){
		printf("%lld",s[i]);
	}
	printf("\n");
	return 0;
}
