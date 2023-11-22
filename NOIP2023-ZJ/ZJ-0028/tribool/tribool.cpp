#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#ifdef DEBUG
template<typename T>
ostream& operator << (ostream &out,vector<T> a){
	out<<'[';
	for(T x:a)out<<x<<',';
	return out<<']';
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
const int N=1e5+10,M=N*2;
int sid,T,n,m,k,a[N],fa[M],is[M],id[N][2];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)fa[x]=y;
}
char op[10];
void get(){
	scanf("%d%d",&n,&m),k=0;
	for(int i=1;i<=n;i++){
		id[i][0]=++k,id[i][1]=++k;
		a[i]=i;
	}
	for(int x,y;m--;){
		scanf("%s%d",op,&x);
		if(op[0]=='T')a[x]=n+1;
		else if(op[0]=='F')a[x]=-n-1;
		else if(op[0]=='U')a[x]=0;
		else if(op[0]=='+'){
			scanf("%d",&y);
			a[x]=a[y];
		}else{
			scanf("%d",&y);
			a[x]=-a[y];
		}
	}
	iota(fa,fa+1+k,0),fill(is+1,is+1+k,1);
	for(int i=1;i<=n;i++){
		if(1<=a[i]&&a[i]<=n){
			merge(id[i][0],id[a[i]][0]);
			merge(id[i][1],id[a[i]][1]);
		}else if(-n<=a[i]&&a[i]<=-1){
			merge(id[i][0],id[-a[i]][1]);
			merge(id[i][1],id[-a[i]][0]);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==n+1)is[find(id[i][0])]=0;
		else if(a[i]==-n-1)is[find(id[i][1])]=0;
		else if(!a[i]){
			is[find(id[i][0])]=is[find(id[i][1])]=0;
		}
		if(find(id[i][0])==find(id[i][1])){
			is[find(id[i][0])]=0;
		}
	}
	// debug(ary(a,1,n));
	// debug(ary(fa,1,k));
	// debug(ary(is,1,k));
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=!is[find(id[i][0])]&&!is[find(id[i][1])];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	for(scanf("%d%d",&sid,&T);T--;)get();
	return 0;
}
