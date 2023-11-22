//#include <bits/stdc++.h>
//using namespace std;
//const int N=1e5+10;
//int c,t,n,m,f[N],b[N];
//inline int find(int x) {
//	if (f[x]==x) return x; else return f[x]=find(f[x]);
//}
//inline int fan(int x) {
//	if (x==2*n+1) return 2*n+2;
//	if (x==2*n+2) return 2*n+1;
//	if (x==2*n+3) return 2*n+3;
//	if (x>n) return x-n;
//	else return x+n;
//}
//inline void check(int x) {
//	if (find(f[x])==fan(x)||find(f[x])==2*n+3) b[find(f[x])]=1;
//}
//int main() {
//	freopen("tribool.in","r",stdin);
//	freopen("tribool.out","w",stdout);
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cin>>c>>t;
//	while (t--) {
//		cin>>n>>m; int ans=0;
//		for (int i=1;i<=2*n+3;++i) f[i]=i,b[i]=0;
//		while (m--) {
//			char op; cin>>op; int x,y;
//			if (op=='T') {cin>>x; f[x]=2*n+1; f[fan(x)]=2*n+2;}
//			if (op=='F') {cin>>x; f[x]=2*n+2; f[fan(x)]=2*n+1;}
//			if (op=='U') {cin>>x; f[x]=2*n+3; f[fan(x)]=2*n+3;}
//			if (op=='+') {cin>>x>>y; f[x]=f[find(y)]; f[fan(x)]=fan(f[x]);}
//			if (op=='-') {cin>>x>>y; f[x]=fan(f[find(y)]); f[fan(x)]=fan(f[x]);}
//		}
//		for (int i=1;i<=n;++i) check(i);
//		for (int i=1;i<=n;++i) if (b[find(f[i])]) ans++;
//		cout<<ans<<endl;
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,m,f[N],X[N],Y[N],F[N],g[N],Ans=0;
char op[N];
inline int fan(int x) {
	if (x==2*n+1) return 2*n+2;
	if (x==2*n+2) return 2*n+1;
	if (x==2*n+3) return 2*n+3;
	if (x>n) return x-n;
	else return x+n;
}
inline int find(int x) {
//	cout<<x<<" "<<f[x]<<endl;
	if (f[x]==x||f[x]==fan(x)) return f[x]; else {
		f[x]=find(f[x]); f[fan(x)]=fan(f[x]);
		return f[x];
	}
}
inline void check() {
	for (int i=1;i<=n;++i) f[i]=F[i];
	for (int i=1;i<=m;++i) {
		if (op[i]=='T') f[X[i]]=1;
		if (op[i]=='F') f[X[i]]=-1;
		if (op[i]=='U') f[X[i]]=0;
		if (op[i]=='+') f[X[i]]=f[Y[i]];
		if (op[i]=='-') f[X[i]]=-f[Y[i]];
	} int res=0;
	for (int i=1;i<=n;++i) {
		if (f[i]!=F[i]) return;
		if (F[i]==0) res++;
	}
	Ans=min(Ans,res);
}
inline void dfs(int x) {
	if (x>n) return check();
	F[x]=1; dfs(x+1);
	F[x]=-1; dfs(x+1);
	F[x]=0; dfs(x+1);
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>t;
	if (c==1||c==2) {
		while (t--) {
			Ans=1e9; cin>>n>>m;
//			cout<<t<<" "<<n<<" "<<m<<endl;
			for (int i=1;i<=m;++i) {
				cin>>op[i]>>X[i];
				if (op[i]=='+'||op[i]=='-') cin>>Y[i];
//				cout<<op[i]<<" "<<X[i]<<" "<<Y[i]<<endl;
			}
			dfs(1); cout<<Ans<<endl;
		}
		return 0;
	}
	if (c==5||c==6) {
		while (t--) {
			cin>>n>>m; int ans=0;
			for (int i=1;i<=m;++i) {
				cin>>op[i]>>X[i];
				if (op[i]=='+'||op[i]=='-') cin>>Y[i];
			}
			for (int i=1;i<=n;++i) f[i]=i;
			for (int i=1;i<=m;++i) {
				if (op[i]=='U') f[X[i]]=0;
				if (op[i]=='+') f[X[i]]=f[Y[i]];
			}
			for (int ooo=1;ooo<=n;++ooo) {
				for (int i=1;i<=n;++i) g[i]=f[i];
				for (int i=1;i<=m;++i) {
					if (op[i]=='U') f[X[i]]=0;
					if (op[i]=='+') f[X[i]]=f[Y[i]];
				}
				int flag=1;
				for (int i=1;i<=n;++i) if (f[i]==0&&g[i]!=0) {flag=0; break;}
				if (flag) break;
			}
			for (int i=1;i<=n;++i) if (f[i]==0) ans++;
			cout<<ans<<endl;
		}
		return 0;
	}
	while (t--) {
		cin>>n>>m; int ans=0;
		for (int i=1;i<=2*n+3;++i) f[i]=i;
		while (m--) {
			char op; cin>>op; int x,y;
			if (op=='T') {cin>>x; f[x]=2*n+1; f[fan(x)]=2*n+2;}
			if (op=='F') {cin>>x; f[x]=2*n+2; f[fan(x)]=2*n+1;}
			if (op=='U') {cin>>x; f[x]=2*n+3; f[fan(x)]=2*n+3;}
			if (op=='+') {cin>>x>>y; f[x]=find(f[y]); f[fan(x)]=fan(f[x]);}
			if (op=='-') {cin>>x>>y; f[x]=fan(find(f[y])); f[fan(x)]=fan(f[x]);}
		}
		for (int i=1;i<=n;++i) {
			if (f[i]==fan(i)) f[i]=f[fan(i)]=2*n+3;
		}
		for (int i=1;i<=n;++i) if (find(f[i])==2*n+3) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
