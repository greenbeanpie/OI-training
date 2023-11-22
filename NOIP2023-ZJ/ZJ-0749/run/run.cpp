#include<bits/stdc++.h>
using namespace std;

int c,t;

int n,m,k,d,mmin=-10000000;

struct node {
	int x,y,v;
} Run[100200];

bool cmp(node a,node b) {
	return a.x<b.x;
}

void dfs(int Day,int Remain,bool isRun,int K) {
	if(Day==n+1) {
		if(Remain>mmin) {
			mmin=Remain;
		}
		return;
	}
	int Now_En=Remain;
	if(isRun==true) {
		Now_En-=d;
		for(int i=1; i<=m; i++) {
			if(Run[i].x-Run[i].y+1<=K&&Run[i].x<=Day) {
				Now_En+=Run[i].v;
			}
		}
	}

	if(K+1<=k) dfs(Day+1,Now_En,true,K+1);
	dfs(Day+1,Now_En,false,0);
}

signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	if(c==1||c==2) {
		while(t--) {
			cin>>n>>m>>k>>d;
			for(int i=1; i<=m; i++) {
				cin>>Run[i].x>>Run[i].y>>Run[i].v;
			}
			sort(Run+1,Run+1+m,cmp);
			dfs(1,0,true,1);
			dfs(1,0,false,0);
			cout<<mmin<<'\n';
		}
	}
	return 0;
}
