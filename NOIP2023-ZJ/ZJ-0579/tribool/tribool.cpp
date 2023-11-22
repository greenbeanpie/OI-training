#include<bits/stdc++.h>
#define ll long long
#define debug cout<<"ok desu"<<endl
using namespace std;

int read(){
	int f=1,x=0; char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}

const int inf=0x7fffffff;
const int U=0,T=114514,F=-114514;

int c,t;
int n,m;
int x[100010];
short Mp[100010];

int rewrite(int id,int type){
	if(x[id]==U)return U;
	if(x[id]==T)return T;
	if(x[id]==F)return F;
	if(x[id]==-id)return x[id]=U;
	if(x[id]== id)return x[id]=T;
	if(Mp[id]!=0){
		if(type==Mp[id])return x[id]=T;
		return x[id]=U;
	}
	if(x[id]>0){
		Mp[id]=type;
		x[id]=rewrite(x[id],type);
		return x[id];
	}
	if(x[id]<0){
		Mp[id]=type;
		x[id]=-rewrite(-x[id],-type);
		return x[id];
	}
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),m=read();
		for(int i=0;i<=n+1;i++){
			x[i]=i;
			Mp[i]=0;
		}
		for(int qwq=0;qwq<m;qwq++){
			char u; cin>>u;
			if(u=='U'){
				int i=read();
				x[i]=U;
			}
			if(u=='T'){
				int i=read();
				x[i]=T;
			}
			if(u=='F'){
				int i=read();
				x[i]=F;
			}
			if(u=='+'){
				int i=read(),j=read();
				x[i]=x[j];
			}
			if(u=='-'){
				int i=read(),j=read();
				x[i]=-x[j];
			}
		}
		for(int i=1;i<=n;i++){
			rewrite(i,1);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(x[i]==0)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}