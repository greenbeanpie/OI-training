#include<bits/stdc++.h>
using namespace std;
const int maxn=200105;
int C,T,N,M,A[maxn],Ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int Get_x(int x){return x+N+5;}
struct ds{
	int Fa[maxn],Sum[maxn];
	void init(){
		for(int i=1;i<=N+2;i++) Fa[Get_x( i)]=Get_x( i),Sum[Get_x( i)]=0;
		for(int i=1;i<=N+2;i++) Fa[Get_x(-i)]=Get_x(-i),Sum[Get_x(-i)]=0;
	}
	int Get_Fa(int x){
		if(x==Fa[x]) return x;
		int fa=Fa[x];
		int ff=Get_Fa(Fa[x]);
		Sum[x]=(Sum[x]+Sum[fa])&1;
		return Fa[x]=ff;
	}
}T1,T2;
vector<int> E[maxn];
bool vis[maxn];
void www(int x,int y){
//	printf("ww: %d %d\n",x,y);
	x=T1.Get_Fa(Get_x(x)),y=T1.Get_Fa(Get_x(y));
//	printf("%d %d\n",x,y);
	int fx=T2.Get_Fa(x),fy=T2.Get_Fa(y);
//	printf("%d %d\n",fx,fy);
	if(fx!=fy){
		vis[fy]|=vis[fx];
		T2.Fa[fx]=fy;
		T2.Sum[fx]=(1-T2.Sum[x]-T2.Sum[y])&1;
	}
	else{
		if((T2.Sum[x]+T2.Sum[y])%2==0)
		 vis[fx]=1;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	C=read(),T=read();
	while(T--){
		N=read(),M=read();Ans=0;
		for(int i=1;i<=N+2;i++) A[i]=i;
		for(int i=1;i<=N+2;i++) E[Get_x(i)].clear(),E[Get_x(-i)].clear(),vis[Get_x(i)]=vis[Get_x(-i)]=0;
		T1.init(),T2.init();
		for(int i=1;i<=M;i++){
			char ch=getchar();
			while(ch!='+'&&ch!='-'&&ch!='U'&&ch!='T'&&ch!='F') ch=getchar();
			int x=read();
			if(ch=='U') A[x]=  N+1 ;else
			if(ch=='T') A[x]=  N+2 ;else
			if(ch=='F') A[x]=-(N+2);else
			if(ch=='+') A[x]= A[read()];else
			if(ch=='-') A[x]=-A[read()];
		}
		A[N+1]=-(N+1);
//		for(int i=1;i<=N+2;i++) printf("%d ",A[i]);puts("");
		for(int i=1;i<=N+2;i++) {
			int fx=T1.Get_Fa(Get_x(i)),fy=T1.Get_Fa(Get_x(A[i]));
			if(fx!=fy) T1.Fa[fx]=fy;
		}
//		for(int i=1;i<=N+2;i++) printf("%d ",T1.Get_Fa(Get_x(i)));puts("");
//		for(int i=1;i<=N+2;i++) printf("%d ",T1.Get_Fa(Get_x(-i)));puts("");
		for(int i=1;i<=N+2;i++) www(i,-i);
//		for(int i=1;i<=N+2;i++) printf("%d ",T2.Get_Fa(Get_x(i)));puts("");
//		for(int i=1;i<=N+2;i++) printf("%d ",T2.Get_Fa(Get_x(-i)));puts("");
		for(int i=1;i<=N;i++) if(vis[T2.Get_Fa(T1.Get_Fa(Get_x(i)))]) Ans++;
		printf("%d\n",Ans);
	}
	return 0;
}