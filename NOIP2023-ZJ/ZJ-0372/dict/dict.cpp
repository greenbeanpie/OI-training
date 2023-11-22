#include <bits/stdc++.h>
#define MAXN 6009
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define dep(i,s,t) for(int i=(s);i>=(t);i--)
using namespace std;
int n,m;
string w[MAXN];
string s[MAXN][2],t[MAXN<<1];
int rk[MAXN][2];
int a[MAXN<<1];
bool cmp(int x,int y) {
	return t[x]<t[y];
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>w[i];
	rep(i,1,n) {
		s[i][0]=s[i][1]=w[i];
		sort(s[i][0].begin(),s[i][0].end(),less<char>());
		sort(s[i][1].begin(),s[i][1].end(),greater<char>());
		a[i]=i;
		a[i+n]=i+n;
		t[i]=s[i][0],t[i+n]=s[i][1];
	}
	sort(a+1,a+2*n+1,cmp);
	rep(i,1,n) rep(j,0,1) rk[i][j]=lower_bound(a+1,a+2*n+1,i+j*n,cmp)-a;
	rep(i,1,n) {
		bool flag=true;
		rep(j,1,n) if(j!=i) {
			if(rk[i][0]>=rk[j][1]) {
				flag=false;
				break;
			}
		}
		if(flag) cout<<"1";
		else cout<<"0";
	}
	cout<<endl;
	return 0;
}
