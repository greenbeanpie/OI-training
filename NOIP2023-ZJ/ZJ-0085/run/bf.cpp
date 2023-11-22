#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define ll long long
#define ull unsigned ll
#define Tp template<typename _T>
Tp _T mabs(_T x){ return x<0?-x:x; }
Tp _T mmin(_T x,_T y){ return x<y?x:y; }
Tp _T mmax(_T x,_T y){ return x<y?y:x; }
Tp void mswap(_T &x,_T &y){ _T t=x; x=y; y=t; return; }
using namespace std;
#define maxn 100039
bool m1;
int n,m,k,d,x,y,v;
struct JTZ{
	int x,y,v;
	bool operator < (const JTZ &x) const {
		return this->x < x.x;
	}
}ch[maxn];
int ti[maxn],tcnt; ll f[1039][1039];
void work(){
	cin>>n>>m>>k>>d; int i,j,l=1; tcnt=0;
	for(i=1;i<=m;i++){
		cin>>ch[i].x>>ch[i].y>>ch[i].v;
		ti[++tcnt]=ch[i].x-ch[i].y; ti[++tcnt]=ch[i].x;
	}
	sort(ch+1,ch+m+1);
	sort(ti+1,ti+tcnt+1);
//	for(i=1;i<=m;i++) if(ch[i].y<=k) cout<<ch[i].x<<' '<<ch[i].y<<' '<<ch[i].v<<'\n';
	for(i=1;i<=n;i++) f[0][i]=-1e18; f[0][0]=0;
	for(i=1;i<=n;i++){
		f[i][0]=-1e18; for(j=0;j<=k;j++) f[i][0]=mmax(f[i][0],f[i-1][j]);
		for(j=1;j<=k;j++) f[i][j]=f[i-1][j-1]-d;
		while(l<=m&&ch[l].x<=i){
			for(j=ch[l].y;j<=k;j++) f[i][j]+=ch[l].v;
			l++;
		}
//		for(j=0;j<=k;j++) cout<<f[i][j]<<" \n"[j==k];
	}
	ll ans=0; for(i=0;i<=k;i++) ans=mmax(ans,f[n][i]); cout<<ans<<'\n';
}
bool m2;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.ans","w",stdout);
	//cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	//cerr<<(&m2-&m1)/1024./1024.<<'\n';
	int id,T; cin>>id>>T; while(T--) work(); return 0;
}
