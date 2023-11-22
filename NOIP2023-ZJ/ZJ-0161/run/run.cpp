#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
namespace sl{
	const int maxn=1005;
	const LL INF=1e18;
	int T,N,M,K,D;
	LL A[maxn][maxn],F[maxn][maxn];
	template<typename Tp>void ExMax(Tp &x,Tp y){if(y>x) x=y;}
	void Get_Ans(){
		T=read();
		while(T--){
			N=read(),M=read(),K=read(),D=read();
			for(int i=0;i<=N;i++)
			for(int j=0;j<=K;j++)
			 A[i][j]=0,F[i][j]=-INF;
			for(int i=1;i<=M;i++){
				int x=read(),y=read(),w=read();
				if(y>K) continue;
				A[x][y]+=w;
			}
			for(int i=1;i<=N;i++)
			for(int j=1;j<=K;j++)
			 A[i][j]+=A[i][j-1];
			F[0][0]=0;
			for(int i=0;i< N;i++)
			for(int j=0;j<=K;j++) if(F[i][j]!=-INF){
				F[i][j]+=A[i][j];
				if(j!=K) ExMax(F[i+1][j+1],F[i][j]-D);
				ExMax(F[i+1][0],F[i][j]);
			}
			LL Ans=0;
			for(int i=0;i<=K;i++) ExMax(Ans,F[N][i]+A[N][i]);
			printf("%lld\n",Ans);
		}
	}
}
namespace ls{
	const int maxn=100005,INF=1e9;
	int T,N,M,K,D,L[maxn],R[maxn],W[maxn],R_Min[maxn],L_Min[maxn],P[maxn];
	LL Sum[maxn],F[maxn],tree[maxn<<2];
	template<typename Tp>void ExMax(Tp &x,Tp y){if(y>x) x=y;}
	void build(int root,int L,int R){
		tree[root]=-1e18;if(L==R) return;int Mid=L+R>>1;
		build(root<<1,L,Mid),build(root<<1|1,Mid+1,R);
	}
	void update(int root,int L,int R,int pos,LL w){
//		printf("upd: %d %d\n",pos,w);
		if(L==R) return tree[root]=w,void();
		int Mid=L+R>>1;
		if(pos<=Mid) update(root<<1,L,Mid,pos,w);else update(root<<1|1,Mid+1,R,pos,w);
		tree[root]=max(tree[root<<1],tree[root<<1|1]);
	}
	LL query(int root,int L,int R,int Q_L,int Q_R){
		if(Q_L>Q_R) return -1e18;
		if(Q_L<=L&&R<=Q_R) return tree[root];
		int Mid=L+R>>1;LL ret=-1e18;
		if(Mid>=Q_L) ret=max(ret,query(root<<1,L,Mid,Q_L,Q_R));
		if(Mid+1<=Q_R) ret=max(ret,query(root<<1|1,Mid+1,R,Q_L,Q_R));
//		printf("q %d %d %lld\n",max(L,Q_L),min(R,Q_R),ret);
		return ret;
	}
	LL check(int Now_L,int Now_R){
//		printf("check: %d %d\n",Now_L,Now_R);
		build(1,Now_L-1,Now_R);
		Sum[Now_L-1]=Sum[Now_R+1]=0;P[Now_L-1]=P[Now_R+1]=Now_L-1;
		for(int i=Now_L;i<=Now_R;i++) Sum[i]=Sum[i-1]+W[i],P[i]=Now_L-1;
		for(int i=Now_L;i<=Now_R;i++){
			//R[i]<L[p]-1 min p
			int P_L=i,P_R=Now_R;
			while(P_L<=P_R){
				int Mid=P_L+P_R>>1;
				if(R[i]<L[Mid]-1) P_R=Mid-1;
				else P_L=Mid+1;
			}
			R_Min[i]=P_L;
			ExMax(P[P_L],i);
		}
		for(int i=Now_L;i<=Now_R;i++){
			//R[i]-L[j]+1<=K min j
			int P_L=Now_L,P_R=i;
			while(P_L<=P_R){
				int Mid=P_L+P_R>>1;
				if(R[i]-L[Mid]+1<=K) P_R=Mid-1;
				else P_L=Mid+1;
			}
			L_Min[i]=P_L;
		}
		for(int i=Now_L;i<=Now_R;i++) P[i]=max(P[i],P[i-1]);
//		for(int i=Now_L;i<=Now_R;i++) printf("%d ",R_Min[i]);puts("");
//		for(int i=Now_L;i<=Now_R;i++) printf("%d ",L_Min[i]);puts("");
//		for(int i=Now_L;i<=Now_R;i++) printf("%d ",P[i]);puts("");
		F[Now_L]=W[Now_L]-1ll*(R[Now_L]-L[Now_L]+1)*D;
		F[Now_L]=max(0ll,F[Now_L]);
		update(1,Now_L-1,Now_R,Now_L,F[Now_L]-Sum[R_Min[Now_L]-1]+1ll*D*(L[R_Min[Now_L]]-1));
		update(1,Now_L-1,Now_R,Now_L-1,1ll*D*(L[Now_L]-1));
		for(int i=Now_L+1;i<=Now_R;i++){
			F[i]=Sum[i]+query(1,Now_L-1,Now_R,P[L_Min[i]-1],P[i])-1ll*D*R[i];
//			printf("!%d %lld\n",i,query(1,Now_L,Now_R,max(1,P[L_Min[i]-1]),P[i]));
//			printf("%d %d\n",P[L_Min[i]-1],P[i]);
			F[i]=max(F[i],W[i]-1ll*(R[i]-L[i]+1)*D);
			F[i]=max(F[i],F[i-1]);
			update(1,Now_L-1,Now_R,i,F[i]-Sum[R_Min[i]-1]+1ll*D*(L[R_Min[i]]-1));
		}
//		for(int i=Now_L;i<=Now_R;i++) printf("%lld ",F[i]);puts("");
		return F[Now_R];
	}
	void Get_Ans(){
		T=read();
		while(T--){
			N=read(),M=read(),K=read(),D=read();
			LL Ans=0;int P=0;
			for(int i=1;i<=M;i++) {
				int x=read(),y=read();W[i]=read();
				L[i]=x-y+1,R[i]=x;
				if(y<=K) P++,L[P]=L[i],R[P]=R[i],W[P]=W[i];
			}
			M=P;
			for(int i=1,j;i<=M;){
				j=i+1;
				while(j<=M&&R[j-1]+1>=L[j]) j++;
				Ans+=check(i,j-1);
				i=j;
			}
			printf("%lld\n",Ans);
		}
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	if(c<=9) sl::Get_Ans();else ls::Get_Ans();
	return 0;
}