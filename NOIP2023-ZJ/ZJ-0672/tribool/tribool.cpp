#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,ans;
int x[N],y[N],a[N],d[N];
char v[N];
bool f;
int read(){
	int f=1,k=0;
	char c;
	do{
		c=getchar();
		if(c=='-') f=-1;
	}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
bool check(){
	int i,j,b[N];
	for(i=1;i<=n;i++) b[i]=a[i];
	for(i=1;i<=m;i++){
		if(v[i]=='-'){
			b[x[i]]=-b[y[i]];
		}
		else if(v[i]=='+'){
			b[x[i]]=b[y[i]];
		}
		else{
			b[x[i]]=y[i];
		}
	}
	for(i=1;i<=n;i++) if(b[i]!=a[i]) return 0;
	return 1;
}
void dfs(int xx,int s,int sm){
	int i;
	if(f) return;
	if(xx==n+1){
		if(check()){
			cout<<sm<<endl;
			f=1;
			return;
		}
		else{
		}
	}
	else{
		a[xx]=1;
		dfs(xx+1,s,sm);
		a[xx]=-1;
		dfs(xx+1,s,sm);
		if(s<sm){
			a[xx]=0;
			dfs(xx+1,s+1,sm);
		}
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i,j;
	c=read();
	t=read();
	while(t--){
		f=0;
		ans=0;
		n=read();
		m=read();
		for(i=1;i<=m;i++){
			v[i]=getchar();
			if(v[i]=='-'){
				x[i]=read();
				y[i]=read();
			}
			else if(v[i]=='+'){
				x[i]=read();
				y[i]=read();
			}
			else{
				x[i]=read();
				if(v[i]=='T') y[i]=1;
				else if(v[i]=='F') y[i]=-1;
				else y[i]=0;
			}	
		}
		if(c==3||c==4){
			memset(d,1,sizeof(d));
			for(i=1;i<=m;i++) d[x[i]]=y[i];
			for(i=1;i<=n;i++) if(d[i]==0) ans++;
			cout<<ans<<endl;
			continue;
		}
		for(i=0;i<=n;i++) dfs(1,0,i);
	}
}
