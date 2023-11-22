#include <bits/stdc++.h>
#define rep(a,b,c) for(int (a) = (b); (a) <= (c); (a)++)
using namespace std;
constexpr int MAXN = 1E5+5;
int c,n,m,q;
int x[MAXN], y[MAXN];
struct Node {
	int l, r;
	int d;

	Node() {
	}
	Node(int il, int ir, int id) {
		l=il,r=ir,d=id;
	}

	bool operator<(const Node& other) {
		return l < other.l;
	}
};
Node nodes[MAXN * 4];
void build(int i, int l, int r) {
	if (l==r) {
		nodes[i]=Node(l,r,x[l]);
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	auto v=max(nodes[i*2].d, nodes[i*2+1].d);
	nodes[i]=Node(l,r,v);
}
void change(int s, int i, int v) {
	if (nodes[s].l == nodes[s].r) {
		nodes[s].d = v;
		return;
	}
	int mid=(nodes[s].l+nodes[s].r)/2;
	if (i<=mid) change(s*2,i,v);
	else change(s*2+1,i,v);
	nodes[s].d = max(nodes[s*2].d, nodes[s*2+1].d);
}
int get(int s,int l, int r) {
	if (l<=nodes[s].l && r>=nodes[s].r) // fully contains
		return nodes[s].d;
	int mid=(nodes[s].l+nodes[s].r)/2;
	int mx=-0x3f3f3f3f;
	if(mid >= l) mx=max(mx, get(s*2,l,r));
	if (mid < r) mx=max(mx, get(s*2+1,l,r));
	return mx;
}
int main() {

	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c >> n >> m >> q;
	for(int i=1; i<=n; i++) cin >> x[i];
	for(int i=1; i<=m; i++) cin >> y[i];

	build(1,1,n);
	
	if (c >= 8 && c <= 14)
	{
		int x_max=get(1,1,n);
		if (x_max>y[m]) cout<<0;
		int f1=0;
		for(int i=1;i<=m;i++)
		{
			if (f1<0)
			{
				cout<<0;
				break;
			}
			if (y[i]<=x[i+f1])
			{
				f1--;
			}
		}
		
			cout<<1;
		
		for(int i=1;i<=q;i++)
		{s
			int x1,x2,a,b;
			cin>>x1>>x2;
			for(int j=1;j<=x1;j++)
			{
				cin >> a>>b;
				x[a]=b;
				change(1,a,b);
			}
			for(int j=1;j<=x2;j++)
			{
				cin>>a>>b;
				y[a]=b;
			}
			
			int x_max=get(1,1,n);
		if (x_max>y[m]) cout<<0;
		int f1=0;
		for(int i=1;i<=m;i++)
		{
			if (f1<0)
			{
				cout<<0;
				break;
			}
			if (y[i]<=x[i+f1])
			{
				f1--;
			}
		}
		}
	}
	cout<<endl;
	
//	if (x[1] > y[1]) {
//		int f1=1,f2=1;
//		while(1) {
//			if (y[f2]<x[f1]) {
//				f2++;
//			} else {
//				if (x[f1+1]>y[f2]) {
//					f1++;
//				} else {
//					while(f2>=2 && x[f1]<=y[f2]) {
//						f2--;
//						f1++;
//					}
//				}
//			}
//
//			if (f1==n && f2==m) {
//				cout<<1;
//				break;
//			}
//
//			if (f2 == m && f1 <= n) {
//				cout<<0;
//				break;
//			}
//		}
//	}

	fclose(stdin);
	fclose(stdout);
}
