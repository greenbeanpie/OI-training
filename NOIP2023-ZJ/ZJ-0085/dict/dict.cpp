#include<cstdio>
#include<string>
#include<iostream>
#define ll long long
#define ull unsigned ll
#define Tp template<typename _T>
Tp _T mabs(_T x){ return x<0?-x:x; }
Tp _T mmin(_T x,_T y){ return x<y?x:y; }
Tp _T mmax(_T x,_T y){ return x<y?y:x; }
Tp void mswap(_T &x,_T &y){ _T t=x; x=y; y=t; return; }
using namespace std;
#define maxn 3039
int n,m,minx[maxn],maxx[maxn],suf[maxn],pre[maxn];
string s;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin>>n>>m; int i;
	for(i=1;i<=n;i++){
		cin>>s; minx[i]=1e9; maxx[i]=-1;
		for(auto ch:s) minx[i]=mmin(minx[i],(int)ch),maxx[i]=mmax(maxx[i],(int)ch);
	}
	pre[0]=suf[n+1]=1e9;
	for(i=n;i>=1;i--) suf[i]=mmin(suf[i+1],maxx[i]);
	for(i=1;i<=n;i++) pre[i]=mmin(pre[i-1],maxx[i]);
	for(i=1;i<=n;i++)
		if(mmin(suf[i+1],pre[i-1])>minx[i]) cout<<'1';
		else cout<<'0';
	cout<<'\n';
	return 0;
}
