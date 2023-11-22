#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
using namespace std;
const int N=3007;
int n,m;
unsigned ll hs1[N][N],hs2[N][N];
string a[N],b[N];
inline bool cmp(int x,int y){
	int l=1,r=m,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(hs1[x][mid]==hs2[y][mid])l=mid+1;
		else r=mid;
	}
	return a[x][l-1]<b[y][l-1];
}
inline void cal(unsigned ll*hs,string&x){
	for(int i=1;i<=m;i++)hs[i]=hs[i-1]*233+x[i-1]-'a';
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],   sort(all(a[i])),cal(hs1[i],a[i]),
		b[i]=a[i],reverse(all(b[i])),cal(hs2[i],b[i]);
	for(int i=1;i<=n;i++){
		bool flg=1;
		for(int j=1;j<=n;j++)
			if(i!=j&&!cmp(i,j)){flg=0;break;}
		cout<<(flg?'1':'0');
	}
	cout<<'\n';
	return 0;
}
