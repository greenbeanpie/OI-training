#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

int id,n,m,Q,a[N],b[N];
namespace bf {
	const int NN=2e3+5;
	bool f[NN][NN];
	bool solve() {
		for (int i=0;i<=n;i++) {
			for (int j=0;j<=m;j++) {
				f[i][j]=0;
			}
		}
		f[0][0]=1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if (a[i]<=b[j]) {
					continue;
				}
				f[i][j]=f[i-1][j]||f[i][j-1]||f[i-1][j-1];
			}
		}
		return f[n][m];
	}
}
namespace sp {
	int mna[N],mxa[N],mnb[N],mxb[N];
	bool check(int p) {
		int x=n,y=m,lx=x,ly=y,flag=0;
		do {
			if (p==0) {
				while (x>1&&mna[x-1]<mnb[y-1]&&a[x-1]<b[y]) {
					x--;
				}
			} else {
				while (y>1&&mxb[y-1]>mxa[x-1]&&a[x]<b[y-1]) {
					y--;
				}
			}
			p^=1;
			if (x!=lx||y!=ly) {
				flag=0;
			} else {
				flag++;
			}
			lx=x,ly=y;
		}while (flag<4);
		return x==1&&y==1;
	}
	bool solve() {
		if (a[1]>=b[1]||a[n]>=b[m]) {
			return 0;
		}
		mna[0]=mnb[0]=1e9+7;
		mxa[0]=mxb[0]=-1;
		for (int i=1;i<=n;i++) {
			mna[i]=min(mna[i-1],a[i]);
			mxa[i]=max(mxa[i-1],a[i]);
		}
		for (int i=1;i<=m;i++) {
			mnb[i]=min(mnb[i-1],b[i]);
			mxb[i]=max(mxb[i-1],b[i]);
		}
		return check(0)||check(1);
	}
}
namespace ac {
	int mna[N],mxa[N],mnb[N],mxb[N];
	bool check1(int p,int x,int y) {
		int lx=x,ly=y,flag=0;
		do {
			if (p==0) {
				while (x>1&&mna[x-1]<mnb[y-1]&&a[x-1]<b[y]) {
					x--;
				}
			} else {
				while (y>1&&mxb[y-1]>mxa[x-1]&&a[x]<b[y-1]) {
					y--;
				}
			}
			p^=1;
			if (x!=lx||y!=ly) {
				flag=0;
			} else {
				flag++;
			}
			lx=x,ly=y;
		}while (flag<4);
		return x==1&&y==1;
	}
	bool check2(int p,int x,int y) {
		int lx=x,ly=y,flag=0;
		do {
			if (p==0) {
				while (x<n&&mna[x+1]<mnb[y+1]&&a[x+1]<b[y]) {
					x++;
				}
			} else {
				while (y<m&&mxb[y+1]>mxa[x+1]&&a[x]<b[y+1]) {
					y++;
				}
			}
			p^=1;
			if (x!=lx||y!=ly) {
				flag=0;
			} else {
				flag++;
			}
			lx=x,ly=y;
		}while (flag<4);
		return x==n&&y==m;
	}
	bool solve() {
		if (a[1]>=b[1]||a[n]>=b[m]) {
			return 0;
		}
		int A=1,B=1;
		for (int i=1;i<=n;i++) {
			if (a[i]<a[A]) {
				A=i;
			}
		}
		for (int i=1;i<=m;i++) {
			if (b[i]>b[B]) {
				B=i;
			}
		}
		if (a[A]>=b[B]) {
			return 0;
		}
		mna[0]=mnb[0]=1e9+7;
		mxa[0]=mxb[0]=-1;
		for (int i=1;i<=n;i++) {
			mna[i]=min(mna[i-1],a[i]);
			mxa[i]=max(mxa[i-1],a[i]);
		}
		for (int i=1;i<=m;i++) {
			mnb[i]=min(mnb[i-1],b[i]);
			mxb[i]=max(mxb[i-1],b[i]);
		}
		if (!check1(0,A,B)&&!check1(1,A,B)) {
			return 0;
		}
		mna[n+1]=mnb[m+1]=1e9+7;
		mxa[n+1]=mxb[m+1]=-1;
		for (int i=n;i>=1;i--) {
			mna[i]=min(mna[i+1],a[i]);
			mxa[i]=max(mxa[i+1],a[i]);
		}
		for (int i=m;i>=1;i--) {
			mnb[i]=min(mnb[i+1],b[i]);
			mxb[i]=max(mxb[i+1],b[i]);
		}
		if (!check2(0,A,B)&&!check2(1,A,B)) {
			return 0;
		}
		return 1;
	}
}
int getans() {
	if (n<=200) {
		if (bf::solve()) {
			return 1;
		}
		for (int i=1;i<=max(n,m);i++) {
			swap(a[i],b[i]);
		}
		swap(n,m);
		bool res=bf::solve();
		for (int i=1;i<=max(n,m);i++) {
			swap(a[i],b[i]);
		}
		swap(n,m);
		return res;
	}/*
	if (id<=14) {
		return sp::solve();
	}
	int p[100],cnt=0;
	for (int i=1;i<=n;i++) {
		p[++cnt]=a[i];
	}
	for (int i=1;i<=n;i++) {
		p[++cnt]=b[i];
	}
	sort(p+1,p+1+cnt);
	cnt=unique(p+1,p+1+cnt)-p-1;
	for (int i=1;i<=n;i++) {
		a[i]=lower_bound(p+1,p+1+cnt,a[i])-p;
		cerr<<a[i]<<" \n"[i==n];
	}
	for (int i=1;i<=m;i++) {
		b[i]=lower_bound(p+1,p+1+cnt,b[i])-p;
		cerr<<b[i]<<" \n"[i==m];
	}*/
	if (ac::solve()) {
		return 1;
	}
	for (int i=1;i<=max(n,m);i++) {
		swap(a[i],b[i]);
	}
	swap(n,m);
	bool res=ac::solve();
	for (int i=1;i<=max(n,m);i++) {
		swap(a[i],b[i]);
	}
	swap(n,m);
	return res;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	cin>>id>>n>>m>>Q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=m;i++) {
		cin>>b[i];
	}
	cout<<getans();
	while (Q--) {
		int k1,k2;
		cin>>k1>>k2;
		vector<pair<int,int>>p1(k1),p2(k2);
		for (int i=0;i<k1;i++) {
			int x,y;
			cin>>x>>y;
			swap(a[x],y);
			p1[i]=make_pair(x,y);
		}
		for (int i=0;i<k2;i++) {
			int x,y;
			cin>>x>>y;
			swap(b[x],y);
			p2[i]=make_pair(x,y);
		}
		cout<<getans();
		for (int i=0;i<k1;i++) {
			swap(a[p1[i].first],p1[i].second);
		}
		for (int i=0;i<k2;i++) {
			swap(b[p2[i].first],p2[i].second);
		}
	}
	
	return 0;
}
