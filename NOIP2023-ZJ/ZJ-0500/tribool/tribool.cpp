#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N+1],ta[N+1];
class Node {
public:
	char v;
	int a,b;
} b[N+1];
int n,m;
bool check() {
	memcpy(ta,a,sizeof(a));
	for(int i=1;i<=m;i++) {
		if(b[i].v=='T'||b[i].v=='F'||b[i].v=='U')
			ta[b[i].a]=b[i].v-'A';
		if(b[i].v=='+')
			ta[b[i].a]=ta[b[i].b];
		if(b[i].v=='-') {
			if(ta[b[i].b]=='T'-'A')
				ta[b[i].a]='F'-'A';
			else if(ta[b[i].b]=='F'-'A')
				ta[b[i].a]='T'-'A';
			else if(ta[b[i].b]=='U'-'A')
				ta[b[i].a]='U'-'A';
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=ta[i])
			return false;
	return true;
}
int minn;
char t[3]={'T','F','U'};
void DFS(int x,int cnt) {
	if(cnt>=minn)
		return;
	if(x==n+1) {
		if(check())
			minn=cnt;
		return;
	}
	for(int i=0;i<3;i++) {
		a[x]=t[i]-'A';
		if(a[x]=='U'-'A')
			DFS(x+1,cnt+1);
		else
			DFS(x+1,cnt);
	}
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==3||c==4) {
		while(t--) {
			int n,m;
			cin>>n>>m;
			while(m--) {
				char v;
				cin>>v;
				if(v=='T'||v=='F'||v=='U') {
					int p;
					cin>>p;
					a[p]=v-'A';
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(a[i]=='U'-'A')
					cnt++;
			cout<<cnt<<endl;
		}
		return 0;
	}
	while(t--) {
		cin>>n>>m;
		for(int i=1;i<=m;i++) {
			cin>>b[i].v;
			if(b[i].v=='+'||b[i].v=='-')
				cin>>b[i].a>>b[i].b;
			else
				cin>>b[i].a;
		}
		minn=2e9;
		DFS(1,0);
		cout<<minn<<endl;
	}
	return 0;
}