#include<bits/stdc++.h>
using namespace std;
int f,t,fa[300001],a[300001],n,m,ans;
int c[300001],cc[300001];
bool flag;
//vector<int> v[100001];
struct pp{
	int x,y;
	char c;
}sr[100001];
void dfs(int dq,int s){
	if(dq>n){
		for(int i=1;i<=n;i++)
			cc[i]=c[i];
		for(int i=1;i<=m;i++){
			int c=sr[i].c;
			if(c=='+'){
				int x=sr[i].x,y=sr[i].y;
				cc[x]=cc[y];
			}
			else if(c=='-'){
				int x=sr[i].x,y=sr[i].y;
				cc[x]=-cc[y];
			}
			else if(c=='T'){
				int x=sr[i].x;
				cc[x]=1;
			}
			else if(c=='U'){
				int x=sr[i].x;
				cc[x]=0;
			}
			else{
				int x=sr[i].x;
				cc[x]=-1;
			}
		}
		bool b=1;
		for(int i=1;i<=n;i++)
			if(c[i]!=cc[i]){
				b=0;break;
			}
		if(b) flag=1,ans=s;
		return;
	}
	c[dq]=1;
	dfs(dq+1,s);
	if(flag) return;
	c[dq]=-1;
	dfs(dq+1,s);
	if(flag) return;
	c[dq]=0;
	dfs(dq+1,s+1);
	if(flag) return;
}
int find(int x){
	if(x==fa[x]) return x;
	else if(x==-fa[x]) return -x;
	if(fa[x]<0) return fa[x]=-find(-fa[x]);
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>f>>t;
	if(f<=2){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				char c;int x,y;cin>>c;
				sr[i].c=c;
				if(c=='+'){
					cin>>x>>y;
					sr[i].x=x,sr[i].y=y;
				}
				else if(c=='-'){
					cin>>x>>y;
					sr[i].x=x,sr[i].y=y;
				}
				else if(c=='T'){
					cin>>x;
					sr[i].x=x;
				}
				else if(c=='U'){
					cin>>x;
					sr[i].x=x;
				}
				else{
					cin>>x;
					sr[i].x=x;
				}
			}
			flag=0;
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	if(f==3||f==4){
		while(t--){
			ans=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				char c;int x,y;cin>>c>>x;
				if(c=='U')
					ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
//	while(t--){
//		cin>>n>>m;
//		for(int i=1;i<=n;i++) fa[i]=i;
//		for(int i=n+1;i<=2*n;i++) fa[i]=i-n;
//		fa[2*n+1]=2*n+1,fa[2*n+2]=2*n+2,fa[2*n+3]=2*n+3;
//		for(int i=1;i<=m;i++){
//			char c;int x,y;cin>>c;
//			if(c=='+'){
//				cin>>x>>y;
//				int u=x+n,v=fa[y+n];
//				fa[u]=v;
//			}
//			else if(c=='-'){
//				cin>>x>>y;
//				int u=x+n,v=fa[y+n];
//				fa[u]=-v;
//			}
//			else if(c=='T'){
//				cin>>x;
//				fa[x+n]=2*n+1;
//			}
//			else if(c=='U'){
//				cin>>x;
//				fa[x+n]=2*n+2;
//			}
//			else{
//				cin>>x;
//				fa[x+n]=2*n+3;
//			}
//		}
//		for(int i=1;i<=n;i++)
//			fa[i]=fa[i+n]=find(i+n);
//		for(int i=1;i<=2*n+3;i++)
//			cout<<fa[i]<<" ";
////		for(int i=1;i<=n;i++) v[i].clear();
////		memset(a,0,sizeof(a));
////		for(int i=n+1;i<=2*n;i++) v[abs(fa[i])].push_back(i-n);
////		ans=0;
////		for(int i=n+1;i<=2*n;i++)
////			if(fa[i]==2*n+2||fa[i]==-(i-n)){
////				a[i-n]=1;ans++;
////				dfs(i-n);
////			}
//		cout<<ans<<"\n";
//	}
	return 0;
}
