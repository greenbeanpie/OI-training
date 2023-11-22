#include<bits/stdc++.h>
#define LL long long
#define IL inline
using namespace std;
const int N = 1e5 + 10,YHH = 0x3f3f3f3f;
bool _u;
int c,T,n,m,a[N],b[N],ans;
char v[N],l[N],r[N];
bool _v;
IL void dfs(int x) {
	if(x > n) {
		for(int i = 1;i <= n;i ++)	r[i] = l[i];
		for(int i = 1;i <= m;i ++) {
			if(v[i] == '+')	r[a[i]] = r[b[i]];
			else if(v[i] == '-')	r[a[i]] = (r[b[i]] == 'U' ? r[b[i]] : (r[b[i]] == 'T' ? 'F' : 'T'));
			else	r[a[i]] = v[i];
		}
		int sum = 0;
		for(int i = 1;i <= n;i ++) {
			if(l[i] != r[i])	return;
			if(r[i] == 'U')	sum ++;
		}
		ans = min(ans,sum);return;
	}
	l[x] = 'T',dfs(x + 1);
	l[x] = 'F',dfs(x + 1);
	l[x] = 'U',dfs(x + 1);
	return;
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	//cerr << abs(&_u - &_v) / 1048576.0 << "MB" << endl;
	ios::sync_with_stdio(0);
	cin >> c >> T;
	while(T --) {
		cin >> n >> m,ans = YHH;
		for(int i = 1;i <= m;i ++) {
			cin >> v[i];
			if(v[i] == '+' || v[i] == '-')	cin >> a[i] >> b[i];
			else	cin >> a[i];
		}
		if(c == 1 || c == 2) {dfs(1),printf("%d\n",ans);continue;}
		if(c == 3 || c == 4) {
			int sum = 0;
			for(int i = 1;i <= n;i ++)	l[i] = 'T';
			for(int i = 1;i <= m;i ++)	l[a[i]] = v[i];
			for(int i = 1;i <= n;i ++)	if(l[i] == 'U')	sum ++;
			printf("%d\n",sum);continue;
		}
	}
	return 0;
}
