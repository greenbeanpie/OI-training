#include<cstdio>
#include<iostream>
#define ll long long
#define ull unsigned ll
#define Tp template<typename _T>
Tp _T mabs(_T x){ return x<0?-x:x; }
Tp _T mmin(_T x,_T y){ return x<y?x:y; }
Tp _T mmax(_T x,_T y){ return x<y?y:x; }
Tp void mswap(_T &x,_T &y){ _T t=x; x=y; y=t; return; }
using namespace std;
#define maxn 100039
int n,m,a[maxn],x,y,flag[maxn<<1],fa[maxn<<1]; char ch;
int getfa(int x){ if(fa[x]==x) return x; return fa[x]=getfa(fa[x]); }
#define meg(x,y) fa[getfa(x)]=getfa(y)
void work(){
	cin>>n>>m; int i,cnt=0,lt=0,lf=0; for(i=1;i<=n;i++) a[i]=i*2;
	for(i=1;i<=n*2;i++) flag[i]=0,fa[i]=i;
	while(m--){
		cin>>ch;
		if(ch=='-'){
			cin>>x>>y;
			if(a[y]==-1) a[x]=-2;
			else if(a[y]==-2) a[x]=-3;
			else if(a[y]==-3) a[x]=-3;
			else a[x]=(a[y]^1);
		}
		else if(ch=='+') cin>>x>>y,a[x]=a[y];
		else{
			cin>>x;
			if(ch=='T') a[x]=-1;
			else if(ch=='F') a[x]=-2;
			else if(ch=='U') a[x]=-3;
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]>0){
			if(a[i]&1) meg(i+n,a[i]>>1),meg(i,(a[i]>>1)+n);
			else meg(i,a[i]>>1),meg(i+n,(a[i]>>1)+n);
		} else if(a[i]==-1){ if(lt) meg(i,lt),meg(i+n,lt+n); else lt=i; }
		else if(a[i]==-2){ if(lf) meg(i,lf),meg(i+n,lf+n); else lf=i; }
	}
	for(i=1;i<=n;i++) if(getfa(i)==getfa(i+n)||a[i]==-3)
		flag[getfa(i)]=flag[getfa(i+n)]=1; 
	for(i=1;i<=n;i++)
		if(a[i]>0) cnt+=flag[getfa(i)];
		else if(a[i]==-3) cnt++;
	cout<<cnt<<'\n';
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int id,T; cin>>id>>T; while(T--) work(); return 0;
}
