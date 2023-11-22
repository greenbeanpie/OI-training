#include<bits/stdc++.h>
using namespace std;
int f[100010],n,m,c,t,x[1000010],y[100002],v[100010],cnt,minn=99999999;
char s[100010],cs[100010],ss[100010];
void sxl(int now,int k) {
	if(k>minn)return;
	if(now==n+1) {
		for(int i=1; i<=n; i++)ss[i]=cs[i];
		for(int i=1; i<=m; i++) {
			if(s[i]=='T')ss[x[i]]='T';
			if(s[i]=='U')ss[x[i]]='U';
			if(s[i]=='F')ss[x[i]]='F';
			if(s[i]=='+')ss[x[i]]=ss[y[i]];
			if(s[i]=='-') {
				if(ss[y[i]]=='U')ss[x[i]]='U';
				else if(ss[y[i]]=='T')ss[x[i]]='F';
				else if(ss[y[i]]=='F')ss[x[i]]='T';
			}
		}
		int cnt=0,ans=0;
		for(int i=1; i<=n; i++)if(cs[i]==ss[i])cnt++;
		if(cnt==n) {
			for(int i=1; i<=n; i++)if(cs[i]=='U')ans++;
			minn=min(ans,minn);
		}
		return;
	}
	cs[now]='U';
	sxl(now+1,k+1);
	cs[now]='T';
	sxl(now+1,k);
	cs[now]='F';
	sxl(now+1,k);
	return;
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	if(c<=2) {
		while(t--) {
			minn=999999999;
			cin>>n>>m;
			for(int i=1; i<=m; i++) {
				char q;
				cin>>q;
				if(q=='+')cin>>x[i]>>y[i],s[i]='+';
				if(q=='-')cin>>x[i]>>y[i],s[i]='-';
				if(q=='U')cin>>x[i],s[i]='U';
				if(q=='T')cin>>x[i],s[i]='T';
				if(q=='F')cin>>x[i],s[i]='F';
			}
			sxl(1,0);
			cout<<minn<<endl;
		}
	} else if(c<=4) {
		while(t--) {
			cnt=0;
			cin>>n>>m;
			for(int i=1; i<=n; i++)v[i]=0;
			for(int i=1; i<=m; i++) {
				char q;
				int u;
				cin>>q>>u;
				if(q=='U')v[u]=1;
				else v[u]=0;
			}
			for(int i=1; i<=n; i++)if(v[i]==0)cnt++;
			cout<<cnt<<endl;
		}
	}
	return 0;
}

