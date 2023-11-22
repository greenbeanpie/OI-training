#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;
int n, m;
int v[maxn], opn[maxn][2], vt[maxn], oplst[maxn];
bool flag[maxn];
char op[maxn];
bool nxt_per() {
	int now = n;
	while(now>0&&v[now]==3) now--;
	if(now==0) return false;
	v[now]++;
	for(int i = now+1; i <= n; i++) v[i]=1;
	return true;
}
int chk() {
	for(int i = 1; i <= n; i++) vt[i] = v[i];
	int now, now2;
	for(int i = 1; i <= m; i++) {
		now = opn[i][0];
		if(op[i]=='T') vt[now] = 1;
		else if(op[i]=='F') vt[now] = 2;
		else if(op[i]=='U') vt[now] = 3;
		else if(op[i]=='+') vt[now] = vt[opn[i][1]];
		else {
			now2 = vt[opn[i][1]];
			if(now2==1) vt[now]=2;
			else if(now2==2) vt[now]=1;
			else vt[now]=3;
		}
	}
	int ret = 0;
	for(int i = 1; i <= n; i++) {
		if(vt[i]!=v[i]) return -1;
		if(v[i]==3) ret++;
	}
	return ret;
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, T, t1, ans;
	cin>>c>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1; i<=m; i++) {
			cin>>op[i]>>opn[i][0];
			if(op[i]=='+'||op[i]=='-') cin>>opn[i][1];
		}
		ans=n;
		
		if(c==1||c==2) {
			for(int i = 1; i <= n; i++) v[i]=1;
			do {
				t1 = chk();
				if(t1!=-1) ans=min(ans, t1);
			} while(nxt_per());
		} else if(c==3||c==4) {
			for(int i = 1; i <= n; i++) v[i]=1;
			ans=0;
			for(int i = 1; i <= m; i++) {
				int now = opn[i][0];
				if(op[i]=='U'&&v[now]!=3) ans++;
				else if(op[i]!='U'&&v[now]==3) ans--;
				if(op[i]=='T') v[now]=1;
				else if(op[i]=='F') v[now]=2;
				else v[now]=3;
			}
		} else if(c==5||c==6) {
			for(int i = 1; i <= n; i++) v[i] = 1;
			ans = 0;
			for(int i = 1; i <= m; i++) {
				int now = opn[i][0];
				if(op[i]=='U') v[now]=3;
			}
			for(int j = 1; j <= 500; j++)
				for(int i = 1; i <= m; i++) {
					int now = opn[i][0];
					if(op[i]=='+') v[now]=v[opn[i][1]];
				}
			for(int i = 1; i <= n; i++) if(v[i]==3) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
