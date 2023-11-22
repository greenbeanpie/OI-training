#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define int long long
int n,m,cnt;
int a[maxn];
int yue[maxn],vis[maxn];
queue <int>q;
int c,t,sum,head[maxn];
struct node{
	int from,to,next;
}tr[maxn];
void add(int u,int v){
	tr[++sum].next=head[u];
	tr[sum].from=u;
	tr[sum].to=v;
	head[u]=sum;
}
signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		sum=0;
		memset(head,0,sizeof(head));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cnt=0;
		cin>>n>>m;
		for(int i=1; i<=n; i++)
			a[i]=i;
		for(int i=1; i<=m; i++) {
			char v[5];
			cin>>v;
			if(v[0]=='-') {
				int u,g;
				cin>>u>>g;
				a[u]=-a[g];
			}
			if(v[0]=='+') {
				int u,g;
				cin>>u>>g;
				a[u]=a[g];
			}
			if(v[0]=='U' || v[0]=='T' || v[0]=='F') {
				int u;
				cin>>u;
				a[u]=100000+v[0];
			}
		}
		for(int i=1; i<=n; i++) {
			if(a[i]>100000) {
				if(a[i]==100000+'U'){
					q.push(i);
					cnt++;
				}	
			}
            else{
            	if(a[i]==-i){
            		q.push(i);
					cnt++;
				}
            	else {
            	add(abs(a[i]),i);
				}
			}
		}
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=head[x];i;i=tr[i].next){
				cnt++;
				q.push(tr[i].to);
			}
		}
		cout<<cnt<<endl;
	}

}
