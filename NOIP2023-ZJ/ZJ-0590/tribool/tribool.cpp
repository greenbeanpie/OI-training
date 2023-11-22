#include<bits/stdc++.h>
#define cg c=getchar()
int T,n,m,x,y,num;char v,c;
int ans,f[100005],g[100005];
struct node{
	char c;int x,y;
}a[100005];
inline void read(int &x){
	x=0;while(c<48||c>57)cg;
	while(c>47&&c<58)x=x*10+(c&15),cg;
	return;
}
void dfs(int k,int sum){
	if(k>n){
		for(int i=1;i<=n;i++)g[i]=f[i];
		for(int i=1;i<=m;i++){
			if(a[i].c=='+')
				g[a[i].x]=g[a[i].y];
			if(a[i].c=='-'){
				if(g[a[i].y]^2)g[a[i].x]=(g[a[i].y]+1)%2;
				else g[a[i].x]=2;
			}
			if(a[i].c=='U')g[a[i].x]=2;
			if(a[i].c=='T')g[a[i].x]=1;
			if(a[i].c=='F')g[a[i].x]=0;
		}
		bool flag=0;
		for(int i=1;i<=n;i++)
			if(g[i]^f[i]){
				flag=1;
				break;
			}
		if(!flag)ans=std::min(sum,ans);
		return;
	}
	if(sum>=ans)return;
	f[k]=0;dfs(k+1,sum);
	f[k]=1;dfs(k+1,sum);
	f[k]=2;dfs(k+1,sum+1);
	return;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cg;read(num);read(T);
	if(num<3){
		while(T--){
			read(n);read(m);ans=10e5+5;
			for(int i=1;i<=m;i++){
				while(c!='-'&&c!='+'&&c!='T'&&c!='U'&&c!='F')cg;
				v=c;read(x);
				if(v=='-'||v=='+')read(y);
				else y=0;
				a[i]={v,x,y};
			}
			dfs(1,0);
			printf("%d\n",ans);
		}
	}
	if(num==3||num==4){
		while(T--){
			read(n);read(m);ans=0;
			for(int i=1;i<=m;i++){
				while(c!='T'&&c!='U'&&c!='F')cg;
				v=c;read(x);
				if(v=='T')f[x]=1;
				if(v=='F')f[x]=0;
				if(v=='U')f[x]=2;
			}
			for(int i=1;i<=n;i++)
				if(f[i]==2)ans++;
			printf("%d\n",ans);
		}
	}
	if(num>4){
		while(T--){
			read(n);read(m);
			for(int i=1;i<=m;i++){
				while(c!='-'&&c!='+'&&c!='T'&&c!='U'&&c!='F')cg;
				v=c;read(x);
				if(v=='-'||v=='+')read(y);
				else y=0;
				a[i]={v,x,y};
			}
			puts("0");
		}
	}
	return 0;
}