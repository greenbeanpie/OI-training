#include<bits/stdc++.h>
#define ll long long
#define ord(i,l,r) for(int i=l;i<=r;i++)
#define dord(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=3020;
int n,m,p[N<<1],as[N]; char s[N<<1][N];
bool cmp(int x,int y){
	ord(i,1,m) if(s[x][i]!=s[y][i]) return s[x][i]<s[y][i];
	return x<y;// same: aaaaaa  i should< i+n   
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	ord(i,1,n){
		scanf("%s",s[i]+1);
		sort(s[i]+1,s[i]+m+1);
		ord(j,1,m) s[i+n][j]=s[i][m-j+1];
	}
	ord(i,1,2*n) p[i]=i;
	sort(p+1,p+2*n+1,cmp);
	ord(i,1,2*n){
		if(p[i]>n) break;
		else as[p[i]]=1;
	}
	ord(i,1,n) putchar('0'+as[i]);
	return 0;
}