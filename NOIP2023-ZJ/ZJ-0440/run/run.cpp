#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int c,t,n,m,k,d,ans,cnt,pos;
int f[N];
int run[N],s[N];
struct apple {
	int ed,len,val,st;
};
apple a[N];

bool cmp (apple x,apple y) {
	if (x.ed!=y.ed) {
		return x.ed<y.ed;
	} else {
		return x.st<y.st;
	}
}

void cl() {
	cnt=ans=pos=0;
	memset(f,0,sizeof(f));
	memset(s,0,sizeof(s));
}

void dfs(int p,int con) {
	//cout<<p<<" "<<con<<endl;
	if (p==n+1) {
		int i,sum=0;
        for (i=1;i<=n;i++){
        	s[i]=s[i-1]+run[i];
		}
		for (i=1;i<=cnt;i++){
			if (s[a[i].ed]-s[a[i].st-1]==a[i].len){
				sum+=a[i].val;
			}
		}
		ans=max(ans,sum);
		return ;
	}
	if (con+1<=k) {
		run[p]=1;
		dfs(p+1,con+1);
		run[p]=0;
	}
	run[p]=0;
	dfs(p+1,0);
}

signed main () {
	int i,j,x,y,z;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	//cout<<"st"<<endl;
	while (t--) {
		cl();
		cin>>n>>m>>k>>d;
		for (i=1; i<=m; i++) {
			cin>>x>>y>>z;
			if (y>k) continue;
			if (z<=y*d) continue;
			a[++cnt].ed=x,a[cnt].len=y,a[cnt].val=z-y*d,a[cnt].st=x-y+1;
		}
		//cout<<"L"<<endl;
		sort(a+1,a+1+cnt,cmp);
		if (c==17||c==18) {
			f[1]=a[1].val;
			ans=max(ans,f[1]);
			for (i=2; i<=cnt; i++) {
				f[i]=f[i-1];
				f[i]=max(f[i],ans+a[i].val);
				ans=max(ans,f[i]);
			}
			cout<<ans<<endl;
		}
		if (c==19||c==20||c==21) {
			f[1]=a[1].val;
			ans=max(ans,f[1]);
			for (i=2; i<=cnt; i++) {
				f[i]=f[i-1];
				f[i]=max(f[i],ans+a[i].val);
				ans=max(ans,f[i]);
			}
			cout<<ans<<endl;
		}
		if (c==1||c==2) {
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
