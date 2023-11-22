#include<bits/stdc++.h>
#define rr register
#define N 100005
using namespace std;
int read(){
	rr int num=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return f*num;
}
int c,T,n,m;
int ans;
int a[N],b[N];//1==U,2==T,3==F
char op[N],l[N],r[N];
bool check(){
	bool flag=1;
	for(rr int i=1;i<=n;++i) b[i]=a[i];
	for(rr int i=1;i<=m;++i){
//		printf("%c %d %d\n",op[i],l[i],r[i]);
//		printf("%d %d\n",b[l[i]],b[r[i]]);
		if(op[i]=='U') b[l[i]]=1;else
		if(op[i]=='T') b[l[i]]=2;else
		if(op[i]=='F') b[l[i]]=3;else
		if(op[i]=='+') b[l[i]]=b[r[i]];else
		if(op[i]=='-'){
			if(b[r[i]]==1) b[l[i]]=1;else
			if(b[r[i]]==2) b[l[i]]=3;else
			if(b[r[i]]==3) b[l[i]]=2;
		}
		
//		printf("%d %d\n",b[l[i]],b[r[i]]);
	}
	for(rr int i=1;i<=n;++i) if(a[i]!=b[i]){flag=0;break;}
	return flag;
}
void dfs(int x,int sum){
	if(x>n){
//		printf("%d\n",ans);
		if(check()) ans=min(sum,ans);
		return ;
	}else
	a[x+1]=1;dfs(x+1,sum+1);
	a[x+1]=2;dfs(x+1,sum);
	a[x+1]=3;dfs(x+1,sum);
}
int fa[N];
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[x]=fa[get(y)];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),T=read();
	if(c==1||c==2){
		while(T--){
			ans=1000005;
			n=read(),m=read();
			for(rr int i=1;i<=m;++i){
				op[i]=getchar();
				while(op[i]!='-'&&op[i]!='+'&&op[i]!='T'&&op[i]!='U'&&op[i]!='F') op[i]=getchar();
				if(op[i]=='-') l[i]=read(),r[i]=read();else
				if(op[i]=='+') l[i]=read(),r[i]=read();else
				if(op[i]=='U') l[i]=read();else
				if(op[i]=='T') l[i]=read();else
				if(op[i]=='F') l[i]=read();
			}
//			for(rr int i=1;i<=m;++i) printf("%c %d %d\n",op[i],l[i],r[i]);
			dfs(0,0);
			printf("%d\n",ans);
		}
		return 0;
	}
	if(c==3||c==4){
		while(T--){
			ans=0;
			n=read(),m=read();
			for(rr int i=1;i<=m;++i){
				op[i]=getchar();
				while(op[i]!='T'&&op[i]!='U'&&op[i]!='F') op[i]=getchar();
				if(op[i]=='U') a[read()]=1;else
				if(op[i]=='T') a[read()]=2;else
				if(op[i]=='F') a[read()]=3;
			}
			for(rr int i=1;i<=n;++i) printf("%d\n",a[i]);
			printf("%d\n",ans);
		}
		return 0;
	}
	if(c==5||c==6){
		while(T--){
			ans=0;
			n=read(),m=read();
			for(rr int i=1;i<=n;++i) fa[i]=i;
			for(rr int i=1;i<=m;++i){
					op[i]=getchar();
					while(op[i]!='+'&&op[i]!='U') op[i]=getchar();
					if(op[i]=='+'){
						rr int x=read(),y=read();
						merge(x,y);
					}else
					if(op[i]=='U'){
						rr int x=read();
						merge(x,0);
					}
			}
//			for(rr int i=1;i<=n;++i) printf("%d\n",get(i));
			for(rr int i=1;i<=n;++i) if(!get(i)) ans++;
			printf("%d\n",ans);
		}
		return 0;
	}
	
	return 0;
}
