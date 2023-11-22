#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int c,t,n,m;
struct node{
	int next,to,w;
}e[N<<2];
int id[N],l=0;
int a[N],b[N],cnt,tim,head[N<<1],vis[N<<1];
int lc[N],d[N];
void add(int x,int y){
	e[++cnt].next=head[x];
	e[cnt].to=y;
	head[x]=cnt;
}
int ans=0;
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int y=e[i].to;
		if(vis[y])continue;
		else{
			e[y].w=1;
			dfs(y);
		}
	}
}
int upo=1;
char vu[15];
bool check(){
	ans=0;
	for(int i=1;i<=m;i++){
		if(vu[i]=='+'){
			a[b[i]]=a[lc[i]];
		}
		if(vu[i]=='-'){
			a[b[i]]=-a[lc[i]];
		}
		if(vu[i]=='T'){
			a[b[i]]=1;
		}
		if(vu[i]=='F'){
			a[b[i]]=-1;
		}
		if(vu[i]=='U'){
			a[b[i]]=0;
		}
	}
	int uo=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=d[i]){
			uo=1;
			return false;
		}
		if(a[i]==0)ans++;
	}
	return true;
}
void der(int num){
	if(upo==0)return;
	if(num==n){
		if(check()){
			cout<<ans<<endl;
			upo=0;
			return;
		}
		else return;
	}
	a[num]=1,d[num]=1;
	der(num+1);
	a[num]=0,d[num]=0;
	a[num]=-1,d[num]=-1;
	der(num+1);
	a[num]=0,d[num]=0;
	der(num+1);
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==3||c==4){
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			char r;
			int ans=0,lp,op[100005];
			for(int i=1;i<=m;i++){
				cin>>r;
				cin>>lp;
				if(r=='U'){
					op[lp]=0;
				}
				else if(r=='T'){
					op[lp]=1;
				}
				else op[lp]=-1;
			}
			for(int i=1;i<=n;i++){
				if(op[lp]==0)ans++;
			}
			cout<<ans<<endl;
		}
	}
	else if(c==1||c==2){
		while(t--){
			ans=0;
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(lc,0,sizeof(lc));
			memset(d,0,sizeof(d));
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>vu[i];
				if(vu[i]=='+'){
					cin>>b[i]>>lc[i];
				}
				else if(vu[i]=='-'){
					cin>>b[i]>>lc[i];
				}
				else if(vu[i]=='T'){
					cin>>b[i];
				}
				else if(vu[i]=='F'){
					cin>>b[i];
				}
				else if(vu[i]=='U'){
					cin>>b[i];
				}
			}
			der(1);
		}
		return 0;
	}
	else if(c==5||c==6){
		while(t--){
			ans=0;
			memset(vis,0,sizeof(vis));
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				char v;
				scanf("%s",&v);
				if(v=='+'){
					cin>>a[i]>>b[i];
					add(a[i],b[i]);
					add(b[i],a[i]);
				//	cout<<1<<endl;
				}
				else{
					++l;
					cin>>id[l];
					e[id[l]].w=1;
				}
			}
			for(int i=1;i<=l;i++)dfs(id[i]);
			int vis2[N<<1];
			memset(vis2,0,sizeof(vis2));
			for(int i=1;i<=n;i++){
				for(int j=head[i];j;j=e[j].next){
					int y=e[j].to;
					if(vis2[y])continue;
					else{
						vis2[y]=1;
						if(e[y].w==1)ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0
}
