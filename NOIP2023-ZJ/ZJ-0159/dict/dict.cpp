#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define cl(f,x) memset(f,x,sizeof(f))
using namespace std;
const int N=3e3+5,M=26;
int cnt[N][M],n,m;
char s[N];
bool check(int k) {
	rep(i,1,n) {
		if(i==k)
			continue;
		int c1=-1,c2=-1;
		rep(j,0,25) {
			if(cnt[k][j]) {
				c1=j;
				break;
			}
		}
		per(j,25,0) {
			if(cnt[i][j]) {
				c2=j;
				break;
			}
		}
		if(c1>=c2)
			return false;
	}
	return true;
}
//pretest at 8:41
signed main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		scanf("%s",s+1);
		rep(j,1,m)
			++cnt[i][s[j]-'a'];
	}
	rep(i,1,n)
		printf("%d",(int)check(i));
	return 0;
}