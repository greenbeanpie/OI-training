#include<bits/stdc++.h>
using namespace std;
const long long inf = 1ll << 62;
const int M = 100010;
const int N = 1010;
long long dp[N][N];
long long tmp[2][M],tot;
long long c,t,n,m,k,d;
long long read(){
	long long ret = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		ret = 10 * ret + ch - '0';
		ch = getchar();
	}
	return ret;
}
struct node{
	long long x,y,v;
}q[M];
bool cmp(node a,node b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
int find(int j){
	int l = 1,r = tot,mid,ans = 0;
	while(l <= r){
		mid = (l+r) / 2;
		if(tmp[0][mid] <= j){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
void tomax(long long &x,long long y){
	if(x == -inf || x < y) x = y;
}
void solve1(){
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i = 1;i <= m;i++)
			scanf("%lld%lld%lld",&q[i].x,&q[i].y,&q[i].v);
		sort(q+1,q+m+1,cmp);
		for(int i = 0;i <= n;i++)
			for(int j = 0;j <= k;j++) dp[i][j] = -inf;
		dp[0][0] = 0;
		for(int i = 0,now = 0;i < n;i++){
			tot = 0;
			while(now < n && q[now+1].x == i+1){
				tot++,now++;
				tmp[0][tot] = q[now].y;
				tmp[1][tot] = tmp[1][tot-1] + q[now].v;
			}
			for(int j = 0;j <= k;j++)if(dp[i][j] != -inf){
				tomax(dp[i+1][0],dp[i][j]);
				if(j == k) continue;
				int tmpp = find(j+1);
				tomax(dp[i+1][j+1],dp[i][j]-d+tmp[1][tmpp]);
			}
		}
		long long ans = -inf;
		for(int i = 0;i <= k;i++) tomax(ans,dp[n][i]);
		printf("%lld\n",ans);
	}
}
void solve2(){
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		long long ans = 0,x,y,v;
		for(int i = 1;i <= m;i++){
			x = read();
			y = read();
			v = read();
			if(y > k) continue;
			ans += max(v-y*d,0ll);
		}
		printf("%lld\n",ans);
	}
}
int main(){
	//44
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c <= 9) solve1();
	else solve2();
	return 0;
}