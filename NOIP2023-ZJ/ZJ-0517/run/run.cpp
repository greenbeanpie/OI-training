#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,k,d,sum,re_sum = 0;
long long x[100010],y[100010],v[100010];
int f[100010],r[100010];
long long read() {
	char c = getchar();
	long long res = 0;
	int d;
	if(c == '-') d = -1;
	else d = 1;
	while(c<'0' ||c > '9') c = getchar();
	while('0' <= c && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return 1LL*d * res;
}
bool check(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(r[i]) cnt++; else cnt = 0;
		if(cnt > k) return false;
	}
	return true;
}
void work(int now){
	if(now > n) {
		if(check()){
			re_sum = max(re_sum,sum);
		}
		return;
	}
	work(now+1);
	int k = 0;
	for(int i = x[now] - y[now] + 1;i <= x[now];i++){
		if(r[i] > 0) k++;
		r[i]++;
	}
	sum += v[now] - (y[now]-k) * d;
	work(now+1);
	for(int i = x[now] - y[now] + 1;i <= x[now];i++){
		r[i]--;
	}
	sum -= v[now] - (y[now]-k) * d;
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c <= 4) {
		while(t--) {
			memset(f,0,sizeof(f));
			n = read();
			m = read();
			k = read();
			d = read();
			for(int i = 1;i <= n;i++) r[i] = 0;
			for(int i = 1; i <= m; i++) {
				x[i] = read();
				y[i] = read();
				v[i] = read();
			}
			work(1);
			printf("%lld\n",re_sum);
		}
		return 0;
	}
	while(t--) {
		re_sum = 0;
		n = read();
		m = read();
		k = read();
		d = read();
		for(int i = 1; i <= m; i++) {
			x[i] = read();
			y[i] = read();
			v[i] = read();
			if(y[i] <= k&&v[i]>y[i]*d) {
				re_sum += v[i] - y[i]*d;
			}
		}
		printf("%lld\n",re_sum);
	}
	return 0;
}