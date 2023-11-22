#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=1e6+10;
int n,m,fa[N],pre[N];
int fnd(int x){
	if(x==fa[x])return x;
	int nxt=fnd(fa[x]);
	pre[x]=(pre[x]+pre[fa[x]])%2;
	return fa[x]=nxt;
}
#define endl '\n'
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			fa[i]=i+n,fa[i+n]=i+n;
			pre[i]=0,pre[i+n]=0;
		}
		for(int i=n*2+1;i<=n*2+3;i++)
			fa[i]=i,pre[i]=0;
		for(int i=1;i<=m;i++){
			char op;cin>>op;
			if(op=='+'){
				int x=read(),y=read();
				int fy=fnd(y);
				fa[x]=fy,pre[x]=pre[y];
			}
			else if(op=='-'){
				int x=read(),y=read();
				int fy=fnd(y);
				fa[x]=fy,pre[x]=(pre[y]+1)%2;
			}
			else if(op=='T'){
				int x=read();
				fa[x]=n*2+2,pre[x]=0;
			}
			else if(op=='F'){
				int x=read();
				fa[x]=n*2+3,pre[x]=0;
			}
			else{
				int x=read();
				fa[x]=n*2+1,pre[x]=0;
			}
		}
		for(int i=1;i<=n;i++){
			int fx=fnd(i+n),fy=fnd(i);
			if(fx==fy){
				if(pre[i]!=pre[i+n])fa[fy]=n*2+1;
				continue;
			}
			pre[fx]=(pre[i]+pre[i+n])%2;
			if(fx!=fy)fa[fx]=fy,fnd(i),fnd(i+n);
			if(pre[i+n]!=pre[i])fa[fa[i+n]]=n*2+1;
		}
		int cnt=0;
		for(int i=n+1;i<=n*2;i++){
			int fx=fnd(i);
			if(fx==n*2+1)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
