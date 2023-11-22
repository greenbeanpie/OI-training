#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>void read(T &x){x=0;char ch;bool f=0;while(!isdigit(ch=getchar())) f|=ch=='-';while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();x=f?-x:x;}
template<typename T1,typename ...T2>void read(T1 &x,T2& ...y){read(x);read(y...);}
int n,m;
char a[100005],b[100005];
bool isd(char ch){
	return ch=='F'||ch=='T'||ch=='U'||ch=='+'||ch=='-';
}
void readc(char &ch){
	while(!isd(ch=getchar()));
}
vector<int>G[100005];
bitset<100005>vis;
int tot;bool flag;
void dfs(int u){
	++tot;vis[u]=1;
	if(a[u]=='U')flag=1;
	for(int v:G[u])
		if(!vis[v])dfs(v);

}
void work(){
	read(n,m);char xt;int ans=0;
	for(int i=1,x,y;i<=m;i++){
		readc(xt);
		if(xt=='U'||xt=='T'||xt=='F')read(x),a[x]=xt;
		else if(xt=='+') read(x,y),G[x].emplace_back(y),G[y].emplace_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			flag=0;tot=0;
			dfs(i);
			
			if(flag)ans+=tot;
		}
	}
	vis.reset();
	for(int i=1;i<=n;i++)G[i].clear(),a[i]='\0';
	printf("%d\n",ans);
}
struct node{
	int x,y;
	char opt;
	node(){
		x=y=0;opt='\0';
	}
	node(int X,int Y,char Z){
		x=X,y=Y,opt=Z;
	}
}e[100005];
//012
//FTU
char change(int x){
	if(x==0)return 'F';
	else if(x==1) return 'T';
	else return 'U';
}
void T12(){
	read(n,m);
	char xt;
	int ans=n,now;
	for(int i=1,x,y;i<=m;i++){
		readc(xt);
		if(xt=='U'||xt=='T'||xt=='F')read(x),e[i]=node(x,-1,xt);
		else if(xt=='+') read(x,y),e[i]=node(x,y,xt);
		else read(x,y),e[i]=node(x,y,xt);
	}
//	puts("KKK");
//	printf("%lld\n",pow(3,n)-1);
	for(int k=pow(3,n)-1,kkk,tp;k>=0;k--){
		kkk=k;tp=now=0;
		while(kkk){
			++tp;
			a[tp]=b[tp]=change(kkk%3);
			if(a[tp]=='U')++now;
			kkk/=3;
		}
	//	printf("%d\n%s\n",now,a+1);
		for(int i=1,x,y;i<=m;i++){
			xt=e[i].opt;x=e[i].x;y=e[i].y;
			if(xt=='U'||xt=='T'||xt=='F')b[x]=xt;
			else if(xt=='+') b[x]=b[y];
			else{
				if(b[y]=='U')b[x]='U';
				else if(b[y]=='T') b[x]='F';
				else b[x]='T';
			}
		//	printf("<%d %d %c>\n%s\n",x,y,xt,b+1);
		}
//		puts("");
		flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				flag=1;break;
			}
		}
//		if(now==3&&!flag){
//			printf("%s\n%s\n",a+1,b+1);
//		}
		if(!flag) ans=min(now,ans);
		for(int i=1;i<=n;i++)a[i]=b[i]='\0';
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)a[i]=b[i]='\0';
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int T,c;read(c,T);
	while(T--){
		if(c<=2)T12();
		else work();
	}
	return 0;
}

