#include<bits/stdc++.h>
#define tr 100001
#define fa 100002
#define un 100003
using namespace std;
const int N=1e5+10;

int c,t;//²âÊÔµã±àºÅ£¬×éÊý
int n,m,ans;
struct node {
	int id,val;
} a[N];
struct edge {
	int id,val;
};
//1e5+1->true 1e5+2->false 1e5+3->unknown
vector<edge>gr[N];
//int sta[N],tp;
//int dfn[N],low[N],idx;
//int sid[N],stot[N],scnt;
//inline void tarjan(int x) {
//	dfn[x]=low[x]=++idx;
//	sta[++tp]=x;
//	for(auto t:gr[x]) {
//		int v=t.id;
//		if(!dfn[v]) {
//			low[x]=min(low[x],low[v]);
//			tarjan(v);
//		} else if(sid[x]!=sid[v]) {
//			low[x]=min(low[x],low[v]);
//			tarjan(v);
//		}
//	}
//	++scnt;
//	do {
//		
//		sid[sta[tp--]]=scnt;
//		stot[scnt]++;
//	} while(x!=sta[tp]);
//}
inline void init() {
	for(int i=1; i<=n; ++i) {
		a[i].id=i;
		a[i].val=0;
		gr[i].clear();
	}
	ans=0;
	return;
}

signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=1; i<=n; ++i) {
			a[i].id=i;
			a[i].val=1;
		}
//		cout<<"orign:"<<endl;
//		for(int i=1; i<=n; ++i) {
//			cout<<a[i].id<<" "<<a[i].val<<endl;
//		}
		for(int i=1; i<=m; ++i) {
			char v;
			int x,y;
			cin>>v;
			if(v=='-') {
				cin>>x>>y;
				if(x==a[y].id&&a[y].val==1) {
					a[x].id=100003;
				} else {
					a[x].id=a[y].id;
					a[x].val=a[y].val*-1;
				}
			}
			if(v=='+') {
				cin>>x>>y;
				if(x==a[y].id&&a[y].val==-1) {
					a[x].id=100003;
				} else {
					a[x].id=a[y].id;
					a[x].val=a[y].val;
				}
			}
			if(v=='T') {
				cin>>x;
				a[x].id=100001;
			}
			if(v=='F') {
				cin>>x;
				a[x].id=100002;
			}
			if(v=='U') {
				cin>>x;
				a[x].id=100003;
			}
		}
		if(c==3||c==4) {
			for(int i=1; i<=n; ++i) {
				if(a[i].id==100003) {
					ans++;
				}
			}
			cout<<ans<<endl;
		} else {
			for(int i=1; i<=n; ++i) {
				if(a[i].id!=0) {
					gr[a[i].id].push_back({i,a[i].val});
				}
			}
//			for(int i=100001;i<=100003;++i){
//				if(!dfn[i])tarjan(i);
//			}
//			for(int i=1;i<=n;++i){
//				if(!dfn[i])tarjan(i);
//			}
//			for(int i=1;i<=scnt;++i){
//				cout<<stot[i]<<endl;
//			}
			queue<int>q;
			for(int i=1;i<=n;++i){
				if(a[i].id==100003){
					q.push(i);
				}
			}
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto x:gr[u]){
					int v=x.id;
					a[v].id=100003;
					q.push(v);
				}
			}
			for(int i=1; i<=n; ++i) {
				if(a[i].id==100003) {
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		init();
	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2

*/
