#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x,y,fa[100010],ans;
char fh[100010],zhi[100010],f;
int head[100010],cnt;
struct nn {
	int to,next;
} edge[100010];
void add(int u,int v) {
	cnt++;
	edge[cnt].next=head[u];
	head[u]=cnt;
	edge[cnt].to=v;
}
queue<int>q;
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>m;
		cnt=0;
		ans=0;
		while(!q.empty()) {
			q.pop();
		}
		for(int i=1; i<=n; ++i) {
			head[i]=0;
			fa[i]=i;
			fh[i]='0';
			zhi[i]='0';
		}
		for(int i=1; i<=100010; ++i) {
			edge[i].next=0;
			edge[i].to=0;
		}
		for(int i=1; i<=m; ++i) {
			cin>>f;
			if(f=='+') {
				cin>>x>>y;
				if(fh[y]=='+') {
					fh[x]='+';
					fa[x]=fa[y];
				}
				if(fh[y]=='-') {
					fh[x]='-';
					fa[x]=fa[y];
				}
				if(fh[y]=='1') {
					fh[x]=1;
					zhi[x]=zhi[y];
				}
				if(fh[y]=='0') {
					fh[x]='+';
					fa[x]=y;
				}
			} else if(f=='-') {
				cin>>x>>y;
				if(fh[y]=='+') {
					fh[x]='-';
					fa[x]=fa[y];
				}
				if(fh[y]=='-') {
					fh[x]='+';
					fa[x]=fa[y];
				}
				if(fh[y]=='1') {
					fh[x]=1;
					if(zhi[y]=='U') {
						zhi[x]='U';
					}
					if(zhi[y]=='T') {
						zhi[x]='F';
					}
					if(zhi[y]=='F') {
						zhi[x]='T';
					}
				}
				if(fh[y]=='0') {
					fh[x]='-';
					fa[x]=y;
				}
			} else {
				cin>>x;
				fh[x]='1';
				zhi[x]=f;
			}
		}
		for(int i=1; i<=n; ++i) {
			if(fh[i]=='1') {
				if(zhi[i]=='U') {
					ans++;
					q.push(i);
				}
			}
			if(fa[i]==i&&fh[i]=='-'){
				ans++;
				q.push(i);
			}
			if(fh[i]=='+'&&fa[i]!=i){
				add(fa[i],i);
			}
			if(fh[i]=='-'&&fa[i]!=i){
				add(fa[i],i);
			}
		}
		while(!q.empty()){
			x=q.front();
			q.pop();
			for(int i=head[x];i!=0;i=edge[i].next){
				y=edge[i].to;
				ans++;
				q.push(y);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
