//finished at 9:06
#include <iostream>
#include <algorithm>
//#include <bits/exc++.h>
using namespace std;
//using namespace __gnu_pbds;
//tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> tr;
const int maxn=3005;
struct node{int cnt[26],flg=-1;} a[maxn];
char s[maxn];
int b[maxn<<1];
bool cmp(int x,int y){
	int flg1=x&1,flg2=y&1,plx=x>>1,ply=y>>1;
	if (flg1&&flg2){
		for (int i=25;i>=0;--i)
			if (a[plx].cnt[i]!=a[ply].cnt[i]) return a[plx].cnt[i]<a[ply].cnt[i];
	}
	else if (flg1&&(!flg2)){
		if (a[plx].flg!=-1&&a[ply].flg!=-1)
			return a[plx].flg<a[ply].flg;
		int tmp1=25,tmp2=0;
		for (;tmp1>=0;--tmp1) if (a[plx].cnt[tmp1]) break;
		for (;tmp2<26;++tmp2) if (a[ply].cnt[tmp2]) break;
		return tmp1<=tmp2;
	}
	else if ((!flg1)&&flg2){
		if (a[plx].flg!=-1&&a[ply].flg!=-1)
			return a[plx].flg<a[ply].flg;
		int tmp1=0,tmp2=25;
		for (;tmp1<26;++tmp1) if (a[plx].cnt[tmp1]) break;
		for (;tmp2>=0;--tmp2) if (a[ply].cnt[tmp2]) break;
		return tmp1<tmp2;
	}
	else{
		for (int i=0;i<26;++i)
			if (a[plx].cnt[i]!=a[ply].cnt[i]) return a[plx].cnt[i]>a[ply].cnt[i];
	}
	return false;
}
int ccnt[maxn];
bool ans[maxn];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%s",s+1);
		for (int j=1;j<=m;++j) ++a[i].cnt[s[j]-'a'];
		for (int j=0;j<26;++j) if (a[i].cnt[j]==m){a[i].flg=j;break;}
	}
	for (int i=1;i<=(n<<1);++i) b[i]=i+1;
	sort(b+1,b+(n<<1)+1,cmp);
//	for (int i=1;i<=(n<<1);++i) printf("%d ",b[i]);putchar(10);
	for (int i=1;i<=(n<<1);++i){
		++ccnt[b[i]>>1];
		if (ccnt[b[i]>>1]==2) break;
		else ans[b[i]>>1]=1;
	}
	for (int i=1;i<=n;++i) putchar(ans[i]?'1':'0');
	return 0;
}
