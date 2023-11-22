#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
string a[N];
int n,m;
int p[N<<1];
bool tmp[N<<1],f[N<<1];
int c[N<<1];
int d[N<<1][N];
bool cmp1(int x,int y){return x<y;}
bool cmp2(int x,int y){return x>y;}
bool cmp(int x,int y){
	for(int i=0;i<m;++i){
		if(d[x][i]==d[y][i])continue;
		else return d[x][i]<d[y][i];
	}
	return x<y;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j) c[j]=a[i][j]-'a'+1;
		sort(c,c+m,cmp1);
		for(int j=0;j<m;++j) d[i][j]=c[j];
		sort(c,c+m,cmp2);
		for(int j=0;j<m;++j) d[i+n][j]=c[j];
	}
	for(int i=1;i<=n*2;++i) p[i]=i;
	sort(p+1,p+1+2*n,cmp);
	for(int i=1;i<=n;++i) tmp[i]=true;
//	bool tmp1=false;
//	for(int i=1;i<=2*n;++i){
//		if(p[i]>n)tmp1=true;
//		else if(p[i]<=n){
//			if(tmp1==true) tmp[p[i]]=false;
//		}
//	}
	int cnt=0;
	for(int i=2*n;i>=1;--i){
		if(p[i]>n) cnt++,f[p[i]-n]=true;
		else{
			if(cnt==n) continue;
			else if(cnt==n-1&&f[p[i]]==false) continue;
			else tmp[p[i]]=false;
		}
	}
	for(int i=1;i<=n;++i) printf("%d",tmp[i]?1:0);
	return 0;
}
