#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3007;
ll n,m; bool ok;
char s[M][M],smin[M][M],smax[M][M],tmp[M][M],cnt;
bool cmp1(char a,char b){
	return a<b;
}
bool cmp2(char a,char b){
	return a>b;
}
bool check2(int x,int y){
	for(int i=1;i<=m;i++){
		if(smin[x][i]>smax[y][i]) return 0;
		if(smin[x][i]<smax[y][i]) return 1;
	}
	return 0;
}
bool tsm(int x){
	for(int i=1;i<=m;i++)
		if(smin[x][i]!=smax[1][m-i+1]) return 0;
	return 1;
}
bool check(int x){
	int comp=1;
	if(tsm(x)) comp=2;
	if(check2(x,comp)) return 1;
	return 0;
}
bool check1(int x,int y){
	for(int i=1;i<=m;i++){
		if(smax[x][i]>smax[y][i]) return 0;
		if(smax[x][i]<smax[y][i]) return 1;
	}
	return 0;
}
void fg1(int x,int y){
	for(int i=1;i<=m;i++)
		tmp[y][i]=smax[x][i];
	return;
}
void fg2(int x,int y){
	for(int i=1;i<=m;i++)
		smax[y][i]=tmp[x][i];
	return;
}
void sortg(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	sortg(l,mid),sortg(mid+1,r);
	int pl=l,pr=mid+1,cnt=l;
	while(pl<=mid || pr<=r){
		if(pl>mid) fg1(pr,cnt),cnt++,pr++;
		else if(pr>r) fg1(pl,cnt),cnt++,pl++;
		else if(check1(pl,pr)) fg1(pl,cnt),cnt++,pl++;
		else fg1(pr,cnt),cnt++,pr++;
	}
	for(int i=l;i<=r;i++) fg2(i,i);
	return;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
			smin[i][j]=smax[i][j]=s[i][j];
		sort(smin[i]+1,smin[i]+1+m,cmp1);
		sort(smax[i]+1,smax[i]+1+m,cmp2);
	}
	sortg(1,n);
	for(int i=1;i<=n;i++)
		if(check(i)) putchar('1');
		else putchar('0');
	return 0;
}