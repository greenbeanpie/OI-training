#include<bits/stdc++.h>
bool mem1;
using namespace std;
using ll=long long;
using vp=vector<pair<int,int> >;
#ifdef DEBUG
template<typename T>
ostream& operator << (ostream &out,vector<T> a){
	out<<'[';
	for(T x:a)out<<x<<',';
	return out<<']';
}
ostream& operator << (ostream &out,pair<int,int> a){
	return out<<'('<<a.first<<','<<a.second<<')';
}
template<typename T>
vector<T> ary(T *a,int l,int r){
	return vector<T>{a+l,a+1+r};
}
template<typename T>
void debug(T x){
	cerr<<x<<endl;
}
template<typename T,typename...S>
void debug(T x,S...y){
	cerr<<x<<' ',debug(y...);
}
#else
#define debug(...) void()
#endif
const int N=5e5+10,K=__lg(N)+1,INF=1e9;
int sid,n,m,q,a[N],b[N];
int cmpa(int x,int y){
	return a[x]<a[y];
}
int cmpb(int x,int y){
	return b[x]<b[y];
}
int amn[K][N],amx[K][N],bmn[K][N],bmx[K][N];
pair<int,int> Amn[K][N],Amx[K][N],Bmn[K][N],Bmx[K][N];
pair<int,int> min_a(int l,int r){
	int k=__lg(r-l+1);
	int i=min(amn[k][l],amn[k][r-(1<<k)+1],cmpa);
	return {a[i],i};
}
pair<int,int> max_a(int l,int r){
	int k=__lg(r-l+1);
	int i=max(amx[k][l],amx[k][r-(1<<k)+1],cmpa);
	return {a[i],i};
}
pair<int,int> min_b(int l,int r){
	int k=__lg(r-l+1);
	int i=min(bmn[k][l],bmn[k][r-(1<<k)+1],cmpb);
	return {b[i],i};
}
pair<int,int> max_b(int l,int r){
	int k=__lg(r-l+1);
	int i=max(bmx[k][l],bmx[k][r-(1<<k)+1],cmpb);
	return {b[i],i};
}
pair<int,int> min_A(int l,int r){
	int k=__lg(r-l+1);
	return min(Amn[k][l],Amn[k][r-(1<<k)+1]);
}
pair<int,int> max_A(int l,int r){
	int k=__lg(r-l+1);
	return max(Amx[k][l],Amx[k][r-(1<<k)+1]);
}
pair<int,int> min_B(int l,int r){
	int k=__lg(r-l+1);
	return min(Bmn[k][l],Bmn[k][r-(1<<k)+1]);
}
pair<int,int> max_B(int l,int r){
	int k=__lg(r-l+1);
	return max(Bmx[k][l],Bmx[k][r-(1<<k)+1]);
}
int sa,sb,ia[N],ib[N],va[N],vb[N];
int la,lb,pa[N],pb[N],Ra[N],La[N],Rb[N],Lb[N];
void calcA(int l,int r,pair<int,int> &amn,pair<int,int> &amx){
	int L=Ra[l],R=La[r];
	if(L>R){
		amn=min_a(l,r),amx=max_a(l,r);
		return;
	}
	amn=min(amn,min_A(pa[L],pa[R]));
	amx=max(amx,max_A(pa[L],pa[R]));
	if(l<ia[L]){
		amn=min(amn,min_a(l,ia[L]-1));
		amx=max(amx,max_a(l,ia[L]-1));
	}
	if(ia[R]<r){
		amn=min(amn,min_a(ia[R]+1,r));
		amx=max(amx,max_a(ia[R]+1,r));
	}
	// debug("calcA",L,R,ary(va,1,n),ary(a,1,n),l,r,amn,amx);
}
void calcB(int l,int r,pair<int,int> &bmn,pair<int,int> &bmx){
	int L=Rb[l],R=Lb[r];
	if(L>R){
		bmn=min_b(l,r),bmx=max_b(l,r);
		return;
	}
	// debug(l,r,pb[L],pb[R]);
	bmn=min(bmn,min_B(pb[L],pb[R]));
	bmx=max(bmx,max_B(pb[L],pb[R]));
	if(l<ib[L]){
		bmn=min(bmn,min_b(l,ib[L]-1));
		bmx=max(bmx,max_b(l,ib[L]-1));
	}
	if(ib[R]<r){
		bmn=min(bmn,min_b(ib[R]+1,r));
		bmx=max(bmx,max_b(ib[R]+1,r));
	}
	// debug("calcB",L,R,ary(vb,1,n),ary(b,1,n),l,r,bmn,bmx);
}
int solve(int op,int l,int r,int x,int y,int t1,int t2,int t3,int t4){
	// if(!op)debug("solve",op,l,r,x,y,t1,t2,t3,t4,A,B);
	if((t1&&t4)||(t2&&t3))return 1;
	if(l>r&&x>y)return t1||t2||t3||t4;
	if(l>r)return t2||t4;
	if(x>y)return t1||t3;
	pair<int,int> amn(INF,0),amx(-1,0),bmn(INF,0),bmx(-1,0);
	calcA(l,r,amn,amx),calcB(x,y,bmn,bmx);
	if(op){
		swap(amn,amx),swap(bmn,bmx);
		amn.first*=-1,amx.first*=-1,bmn.first*=-1,bmx.first*=-1;
	}
	// if(!op)debug(amn,amx,bmn,bmx);
	if(bmn.first<=amn.first&&amx.first<bmx.first){
		// debug("tag2",bmn.second,bmx.second);
		if(t2&&t4)return 1;
		if(!t2&&!t4)return 0;
		if(t2)return solve(op,l,r,bmn.second+1,y,0,t2,t3,t4);
		else return solve(op,l,r,x,bmn.second-1,t1,t2,0,t4);
	}
	if(amn.first<bmn.first&&amx.first>=bmx.first){
		if(t1&&t3)return 1;
		if(!t1&&!t3)return 0;
		if(t1)return solve(op,amx.second+1,r,x,y,t1,0,t3,t4);
		else return solve(op,l,amx.second-1,x,y,t1,t2,t3,0);
	}
	if(amn.first<bmn.first&&bmx.first>amx.first){
		// debug("tag",bmx.second);
		if((t1&&t3)||(t2&&t4))return 1;
		return
			solve(op,l,amn.second-1,x,bmx.second-1,t1,t2,1,1)&
			solve(op,amn.second+1,r,bmx.second+1,y,1,1,t3,t4);
	}
	if(bmn.first<=amn.first&&amx.first>=bmx.first){
		return 0;
	}
	assert(0);
	return 0;
}
void solve(){
	printf("%d",
		solve(0,1,n,1,m,0,0,0,0)|
		solve(1,1,n,1,m,0,0,0,0)
	);
}
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second<y.second;
}
bool mem2;
int main(){
	debug(abs(&mem1-&mem2)/1048576.0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&sid,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		amn[0][i]=amx[0][i]=i;
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			amn[i][j]=min(amn[i-1][j],amn[i-1][j+(1<<i-1)],cmpa);
			amx[i][j]=max(amx[i-1][j],amx[i-1][j+(1<<i-1)],cmpa);
		}
	}
	for(int i=1;i<=m;i++){
		bmn[0][i]=bmx[0][i]=i;
	}
	for(int i=1;(1<<i)<=m;i++){
		for(int j=1;j+(1<<i)-1<=m;j++){
			bmn[i][j]=min(bmn[i-1][j],bmn[i-1][j+(1<<i-1)],cmpb);
			bmx[i][j]=max(bmx[i-1][j],bmx[i-1][j+(1<<i-1)],cmpb);
		}
	}
	// debug(1.0*clock()/CLOCKS_PER_SEC);
	for(int i=0;i<=n+1;i++)La[i]=0,Ra[i]=n+1;
	for(int i=0;i<=m+1;i++)Lb[i]=0,Rb[i]=m+1;
	solve();
	fill(va+1,va+1+n,-1);
	fill(vb+1,vb+1+m,-1);
	for(int x,y,i,j;q--;){
		scanf("%d%d",&x,&y);
		sa=sb=0;
		for(;x--;){
			scanf("%d%d",&i,&j);
			va[i]=j,ia[++sa]=i;
		}
		for(;y--;){
			scanf("%d%d",&i,&j);
			vb[i]=j,ib[++sb]=i;
		}
		sort(ia+1,ia+1+sa);
		sort(ib+1,ib+1+sb);
		ia[sa+1]=n+1,ib[sb+1]=m+1;
		la=lb=0;
		int las=0;
		for(int i=1;i<=sa+1;i++){
			for(int j=ia[i-1]+1;j<=ia[i];j++)Ra[j]=i;
			for(int j=ia[i-1];j<ia[i];j++)La[j]=i-1;
			if(ia[i-1]+1<ia[i]){
				la++;
				Amn[0][la]=min_a(ia[i-1]+1,ia[i]-1);
				Amx[0][la]=max_a(ia[i-1]+1,ia[i]-1);
			}
			if(i<=sa){
				la++;
				Amn[0][la]=Amx[0][la]={va[ia[i]],ia[i]};
				pa[i]=la;
			}
		}
		for(int i=1;i<=sb+1;i++){
			for(int j=ib[i-1]+1;j<=ib[i];j++)Rb[j]=i;
			for(int j=ib[i-1];j<ib[i];j++)Lb[j]=i-1;
			if(ib[i-1]+1<ib[i]){
				lb++;
				Bmn[0][lb]=min_b(ib[i-1]+1,ib[i]-1);
				Bmx[0][lb]=max_b(ib[i-1]+1,ib[i]-1);
			}
			if(i<=sb){
				lb++;
				Bmn[0][lb]=Bmx[0][lb]={vb[ib[i]],ib[i]};
				pb[i]=lb;
			}
		}
		// debug("Amn0",ary(Amn[0],1,la));
		// debug("Bmn0",ary(Bmn[0],1,lb));
		for(int i=1;(1<<i)<=la;i++){
			for(int j=1;j+(1<<i)-1<=la;j++){
				Amn[i][j]=min(Amn[i-1][j],Amn[i-1][j+(1<<i-1)]);
				Amx[i][j]=max(Amx[i-1][j],Amx[i-1][j+(1<<i-1)]);
			}
		}
		for(int i=1;(1<<i)<=lb;i++){
			for(int j=1;j+(1<<i)-1<=lb;j++){
				Bmn[i][j]=min(Bmn[i-1][j],Bmn[i-1][j+(1<<i-1)]);
				Bmx[i][j]=max(Bmx[i-1][j],Bmx[i-1][j+(1<<i-1)]);
			}
		}
		// debug(ta,tb);
		solve();
		for(int i=1;i<=sa;i++)va[ia[i]]=-1;
		for(int i=1;i<=sb;i++)vb[ib[i]]=-1;
	}
	puts("");
	debug(1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}
