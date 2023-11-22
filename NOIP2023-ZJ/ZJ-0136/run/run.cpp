#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n,m,k;
ll v[100005],ans,x[100005],y[100005],d,sum[1005][1005],f[1005][1005];

void solB(){
	for(int i = 1; i<= m; i++){
		if((y[i]-x[i]+1ll)<=k && (y[i]-x[i]+1ll)*d<=v[i])ans+=v[i]-(y[i]-x[i]+1ll)*d;
	}
	cout << ans << endl;
}

void sol1(){
	memset(sum,0,sizeof(sum));
	memset(f,-0x3f,sizeof(f));
	f[0][0]=0;
	for(int i = 1; i <= m; i++){
		int r = x[i];
		for(int l = x[i]-y[i]+1; l + k > r && l>=0; l--){
			sum[l][r]+=v[i];
		//	cout << "add: " << l << " " << r << " " << v[i] << endl;
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			sum[i][j]+=sum[i][j-1];
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = i;j <= n; j++){
			sum[i][j]-=d*(j-i+1);
			//cout << i << " " << j << ":" << sum[i][j] << endl;
		}
	}
	for(int r = 1; r <= n; r++){
		for(int i = 0; i <= k; i++)f[r][0]=max(f[r][0],f[r-1][i]);
		for(int day = 1; day <= k && day <= r; day++){//no run day i-day
			f[r][day] = max(f[r][day],f[r-day][0]+sum[r-day+1][r]);
		//	cout << "r day:" << r << " " << day << "<- " << f[r][day] << endl;
		}
	}
	ans = 0;
	for(int i = 0; i <= k; i++)ans=max(ans,f[n][i]);
	cout << ans << endl;
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans = 0;
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for(int i = 1; i <= m; i++){
			scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
		}
		//if(c == 17 || c == 18)solB();
		if(c <= 9)sol1();
	}
	return 0;
}