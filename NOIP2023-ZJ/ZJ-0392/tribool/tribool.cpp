#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=100005;
struct node {
	int v;
	int md;
} a[N];
char res[N];
void get_v(int x) {
	if(!a[x].v) res[x]='T';
	if(a[x].md==2) {
		res[x]=char(a[x].v);
	}
	if(a[x].md==1) {
		if(x==a[x].v) {
			res[x]='T';
		} else {
			int to=a[x].v;
			//if(res[to]) {
//				res[x]=res[to];
//			} else {
				get_v(to);
				res[x]=res[to];
			//}
		}
	}
	if(a[x].md==0) {
		if(x==a[x].v) {
			res[x]='U';
		} else {
			int to=a[x].v;
//			if(res[to]) {
//				if(res[to]=='T') res[x]='F';
//				if(res[to]=='F') res[x]='T';
//				if(res[to]=='U') res[x]='U';
//			} else {
				get_v(to);
				if(res[to]=='T') res[x]='F';
				if(res[to]=='F') res[x]='T';
				if(res[to]=='U') res[x]='U';
			//}
		}
	}
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>t;
	while(t--) {
		memset(res,0,sizeof(res));
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=m; i++) {
			char c;
			cin>>c;
			if(c=='+'||c=='-') {
				int from,to;
				cin>>to>>from;
				if(c=='+') {
					if(a[from].v) {
						a[to].v=a[from].v;
						a[to].md=a[from].md;
					} else {
						a[from].md=1;
						a[to].v=from;
					}
				} else {
					if(a[from].v) {
						if(a[from].md==2) {
							if(a[from].v=='U') {
								a[to].v='U';
							}
							if(a[from].v=='T') {
								a[to].v='F';
							}
							if(a[from].v=='F') {
								a[to].v='T';
							}
							a[to].md=a[from].md;
						} else {
							a[to].v=a[from].v;
							if(a[from].md==0) a[to].md=1;
							if(a[from].md==1) a[to].md=0;
						}
					} else {
						a[from].md=0;
						a[to].v=from;
					}
				}
			} else {
				int x;
				cin>>x;
				if(c=='U') a[x].v='U';
				if(c=='T') a[x].v='T';
				if(c=='F') a[x].v='F';
				a[x].md=2;
			}
		}
		for(int i=1; i<=m; i++) {
			get_v(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(res[i]=='U') {
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
