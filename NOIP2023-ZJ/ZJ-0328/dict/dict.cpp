#include <bits/stdc++.h>
#define int long long 
using namespace std;
/*
对于所有字符串二分哈希比较即可
注意到是noip，所以双哈希上一下
原因未知，nlog的跑这么慢 600ms
fc d:\dict.out d:\dict4.ans
*/
const int N=3005,H=2;
const int mo[]={998244853,1000000009};
const int bs[]={131,233};
int n,m;
string bss[N];
int hs[N][N][H];
int bh[N][H];
int jc[N][H];
int ct[27];
bool cmp(char a,char b){return a>b;}
inline int get(int k,int l,int r,int h){
	if(l==0)return hs[k][r][h];
	return (hs[k][r][h]-((hs[k][l-1][h]*jc[r-l+1][h])%mo[h])+mo[h])%mo[h];
}
inline int gt(int l,int r,int h){
	if(l==0)return bh[r][h];
	return (bh[r][h]-((bh[l-1][h]*jc[r-l+1][h])%mo[h])+mo[h])%mo[h];
}
struct node{
	string s;
	int id;
	bool operator<(const node &T)const{
		int l=0,r=m-1,mid,ans=m-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(get(id,0,mid,0)==get(T.id,0,mid,0) and get(id,0,mid,1)==get(T.id,0,mid,1))
				l=mid+1;
			else ans=mid,r=mid-1;
		}
		return s[ans]>T.s[ans];
	}
}a[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	// int st=clock();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	cin>>n>>m;
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	for(int i=0;i<H;i++)jc[0][i]=1;
	for(int i=1;i<=m;i++)for(int j=0;j<H;j++)jc[i][j]=(jc[i-1][j]*bs[j])%mo[j];
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		for(int j=1;j<=26;j++)ct[j]=0;
		for(auto j:a[i].s)ct[j-'a'+1]++;
		int nw=-1;
		for(int j=26;j>=1;j--)for(int u=1;u<=ct[j];u++)a[i].s[++nw]=(char)(j-1+'a');
		a[i].id=i;
		bss[i]=a[i].s;
		for(int j=0;j<m;j++)for(int h=0;h<H;h++){
			if(j==0)hs[i][j][h]=a[i].s[j]-'a'+1;
			else hs[i][j][h]=(hs[i][j-1][h]*bs[h]+a[i].s[j]-'a'+1)%mo[h];
		}
	}
	sort(a+1,a+n+1);
	// int st=clock();
	for(int i=1;i<=n;i++){
		reverse(bss[i].begin(),bss[i].end());
		for(int j=0;j<m;j++)for(int h=0;h<H;h++){
			if(j==0)bh[j][h]=bss[i][j]-'a'+1;
			else bh[j][h]=(bh[j-1][h]*bs[h]+bss[i][j]-'a'+1)%mo[h];
		}
		bool bom=false;
		int p=a[n].id,ms=n;
		if(a[n].id==i)p=a[n-1].id,ms=n-1;
		int l=0,r=m-1,mid,ans=m-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(get(p,0,mid,0)==gt(0,mid,0) and get(p,0,mid,1)==gt(0,mid,1))
				l=mid+1;
			else ans=mid,r=mid-1;
		}
		if(bss[i][ans]>=a[ms].s[ans])bom=true;
		if(bom)cout<<"0";
		else cout<<"1";
	}
	cout<<"\n";
	// cerr<<clock()-st<<"\n";
}