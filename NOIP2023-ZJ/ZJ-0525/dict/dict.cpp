#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
char c[3005][3005];
char maxn[3005][3005];
char minn[3005][3005];
struct node{
	string s;
	int id;
	bool ans;
	bool operator <(const node &rhs)const{return id<rhs.id;}	
};
node maxs[3005],mins[3005];
bool cmp1(char x,char y){return x<y;}
bool cmp2(char x,char y){return x>y;}
bool cmp3(node x,node y){
	if(x.id==y.id) return true;
	for(int i=0;i<x.s.length();i++) if(x.s[i]!=y.s[i]) return x.s[i]>y.s[i];
	return false;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) maxn[i][j]=minn[i][j]=c[i][j];
	for(int i=1;i<=n;i++){
		sort(minn[i]+1,minn[i]+m+1,cmp1);
		sort(maxn[i]+1,maxn[i]+m+1,cmp2);
	}
	for(int i=1;i<=n;i++){
		string s1="",s2="";
		for(int j=1;j<=m;j++) s1+=maxn[i][j],s2+=minn[i][j];
		maxs[i].s=s1,mins[i].s=s2;
		maxs[i].id=mins[i].id=i;
	}
	sort(mins+1,mins+n+1,cmp3);
	sort(maxs+1,maxs+n+1,cmp3);
	int tmp=1;
	for(int i=1;i<=n;i++){
		while(cmp3(maxs[tmp],mins[i]) and tmp<=n) tmp++;
		tmp--;
		if(tmp!=n) mins[i].ans=0;
		else mins[i].ans=1;
	}
	sort(mins+1,mins+n+1);
	for(int i=1;i<=n;i++) cout<<mins[i].ans;
}