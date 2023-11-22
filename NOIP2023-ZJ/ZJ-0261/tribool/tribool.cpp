#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,u,v;bool addans;
int f[100039],p[100039],z[100039];char w[100039];
char ch;int top,ans,aqw;
int abs(int x){return x<0?-x:x;}
struct Node{
	int to,v;
};vector<Node>a[100039],b[100039];
char change(char ch,int x){
	if(ch=='U')return 'U';
	if(ch=='0')return '0';
	if(x==1)return ch;
	return (ch=='T')?('F'):('T');
}
void dp(int u,char ch){
	if(ch=='U')ans++;
	if(p[u])return;p[u]=1;
	for(int i=0;i<b[u].size();i++){
		if(!p[b[u][i].to]){
			dp(b[u][i].to,change(ch,b[u][i].v));
		}
	}return ;
}
void dp2(int u,int deep,int ti,int fa){
	if(p[u]!=0){
		if(aqw==-1)if(abs(z[u]-ti)%2)addans=1,aqw=u;
		return;
	}
	p[u]=deep;z[u]=ti;top++;
	for(int i=0;i<b[u].size();i++){
		if(b[u][i].to!=fa){
			dp2(b[u][i].to,deep+1,(b[u][i].v==-1?1:0)+ti,u);
		}
	}
	for(int i=0;i<a[u].size();i++){
		if(a[u][i].to!=fa){
			dp2(a[u][i].to,deep+1,(a[u][i].v==-1?1:0)+ti,u);
		}
	}return ;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);ans=0;
		for(int i=1;i<=n+3;i++){f[i]=i;p[i]=0;w[i]='0';a[i].clear();b[i].clear();z[i]=0;}
		for(int i=1;i<=m;i++){
			cin>>ch;
			if(ch=='+'){
				scanf("%d%d",&u,&v);
				if(w[v]=='0')f[u]=f[v],w[u]='0';
				else w[u]=w[v],f[u]=u;
			}else if(ch=='-'){
				scanf("%d%d",&u,&v);
				if(w[v]=='0')f[u]=-f[v],w[u]='0';
				else w[u]=w[v],f[u]=u;
			}else if(ch=='T'){
				scanf("%d",&u);
				f[u]=u;w[u]=ch;
			}else if(ch=='F'){
				scanf("%d",&u);
				f[u]=u;w[u]=ch;
			}else if(ch=='U'){
				scanf("%d",&u);
				f[u]=u;w[u]=ch;
			}
		}
		for(int i=1;i<=n;i++){
			a[i].push_back((Node){abs(f[i]),f[i]/abs(f[i])});
			b[abs(f[i])].push_back((Node){i,f[i]/abs(f[i])});
		}
		for(int i=1;i<=n;i++){
			if(f[i]==i){
				dp(i,w[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(!p[i]){
				top=addans=0;aqw=-1;dp2(i,1,0,-1);if(addans==1)ans+=top;
			}
		}
		printf("%d\n",ans);
	}
}