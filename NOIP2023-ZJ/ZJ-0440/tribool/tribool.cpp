#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,ans,cnt;
int st[N],ed[N],col[N];
char ch;
struct apple {
	int type,x,y;
};
apple a[N];

void dfs(int k) {
	if (k==n+1) {
		int i,sum=0;
		for (i=1; i<=n; i++) {
			ed[i]=st[i];
			if (st[i]) sum++;
		}
		for (i=1; i<=m; i++) {
			if (a[i].type==1) {
				ed[a[i].x]=ed[a[i].y];
			}
			if (a[i].type==2) {
				ed[a[i].x]=(3-ed[a[i].y])%3;
			}
			if (a[i].type==10) {
				ed[a[i].x]=1;
			}
			if (a[i].type==11) {
				ed[a[i].x]=2;
			}
			if (a[i].type==12) {
				ed[a[i].x]=0;
			}
		}
		for (i=1; i<=n; i++) {
			if (st[i]!=ed[i]) sum=0;
		}
		ans=max(ans,sum);
		return;
	}
	st[k]=1;
	dfs(k+1);
	st[k]=2;
	dfs(k+1);
	st[k]=0;
	dfs(k+1);
}

void cl(){
	cnt=0;
	memset(col,-1,sizeof(col));
}

int main () {
	int c,t,i,x,y,tag;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while (t--) {
		cin>>n>>m;
		ans=0;
		for (i=1; i<=m; i++) {
			cin>>ch;
			if (ch=='+') {
				cin>>x>>y;
				a[i].type=1,a[i].x=x,a[i].y=y;
			}
			if (ch=='-') {
				cin>>x>>y;
				a[i].type=2,a[i].x=x,a[i].y=y;
			}
			if (ch=='T'||ch=='U'||ch=='F') {
				cin>>x;
				if (ch=='T') tag=col[x]=0;
				if (ch=='F') tag=col[x]=1;
				if (ch=='U') tag=col[x]=2;
				a[i].type=10+tag,a[i].x=x;
			}
		}
		if (c==1||c==2) {
			dfs(1);
			cout<<(n-ans)<<endl;
		}
        if (c==3||c==4){
            for (i=1;i<=n;i++){
            	if (col[i]==2){
            		cnt++;
				}
			}
			cout<<cnt<<endl;
			cl();
		}
		if (c==5||c==6){
			memset(col,-1,sizeof(col));
			for (i=1;i<=m;i++){
				if (a[i].type==1){
					col[a[i].x]=col[a[i].y];
				}
				if (a[i].type==12){
					col[a[i].x]=2;
				}
			}
			for (i=1;i<=n;i++){
            	if (col[i]==2){
            		cnt++;
				}
			}
			cout<<cnt<<endl;
			cl();
		}
	}
	return 0;
}
