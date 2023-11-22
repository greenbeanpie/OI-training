#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
const int N=1e5+10;
const int inf=1e9+10;
struct node{
	char c;
	int x,y;
}op[N];
int n,m,ans=1e5+10;
int a[N],b[N];
int cg(int x){
	if(x==1) return 2;
	if(x==2) return 1;
	else return 3;
}
void dfs(int x,int sum){
	if(x==n+1){
		for(int i=1;i<=n;i++) b[i]=a[i];
		for(int i=1;i<=m;i++){
			int t=op[i].x;
			if(op[i].c=='T') b[t]=1;
			else if(op[i].c=='F') b[t]=2;
			else if(op[i].c=='U') b[t]=3;
			else{
				int z=op[i].y;
				if(op[i].c=='+') b[t]=a[z];
				if(op[i].c=='-') b[t]=cg(a[z]);
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=a[i]) return;
		}
		ans=min(ans,sum);
		return;
	}
	a[x]=1;
	dfs(x+1,sum);
	a[x]=2;
	dfs(x+1,sum);
	a[x]=3;
	dfs(x+1,sum+1);
}
void work1(){
	dfs(1,0);
	if(ans!=inf) printf("%d\n",ans);
	else printf("0\n");
}
void work2(){
	int res=0;
	for(int i=1;i<=m;i++){
		int t=op[i].x;
		if(op[i].c=='T') a[t]=1;
		else if(op[i].c=='F') a[t]=2;
		else if(op[i].c=='U') a[t]=3;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==3) res++; 
		a[i]=0;
	}
	printf("%d\n",res);
}
int fa[N],sum[N];
bool vis[N],ck[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void work3(){
	int res=0;
	for(int i=1;i<=n;i++) a[i]=i,fa[i]=i,sum[i]=1,ck[i]=0,vis[i]=0;
	
	for(int i=1;i<=m;i++){
		int t=op[i].x;
		if(op[i].c=='U') a[t]=-1;
		if(op[i].c=='+'){
			int z=op[i].y;
			a[t]=a[z];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			int f1=find(i);
			int f2=find(a[i]);
			if(f1!=f2) {
				fa[f1]=f2;
				sum[f2]+=sum[f1];
				if(ck[f1]==1) ck[f2]=1;
			}
		}
		else{
			int f=find(i);
			ck[f]=1;
		}
	}
	for(int i=1;i<=n;i++){
		int f=find(i);
		if(ck[f]&&!vis[f]){
			res+=sum[f];
			vis[f]=1;
		}
	}
	printf("%d\n",res);
}
void work4(){
	int res=0;
	for(int i=1;i<=n;i++) a[i]=1,b[i]=1;
	for(int i=1;i<=m;i++){
		int t=op[i].x,z=op[i].y;
		if(op[i].c=='T'){
			a[i]=1;
		}
		else if(op[i].c=='F') a[i]=2;
		else if(op[i].c=='U') a[i]=3;
		if(op[i].c=='+') a[t]=a[z];
		else{
			if(a[z]==1) a[t]=2;
			else a[t]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			res++;
		}
	}
	printf("%d\n",res);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		n=read(),m=read(),ans=inf;
		for(int i=1;i<=m;i++){
			cin>>op[i].c;
			if(op[i].c=='T'||op[i].c=='F'||op[i].c=='U'){
				op[i].x=read(),op[i].y=0;
			}
			else op[i].x=read(),op[i].y=read();
		}
		if(c==1||c==2) work1();
		if(c==3||c==4) work2();
		if(c==5||c==6) work3();
		else work4();
	}
	return 0;
}
