#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
unordered_map<int,int> trr[maxn];
int n;
void upd(int x,int y,int val){
	for(;x<=n;x+=x&-x)
		for(int i=y;i<=n;i+=i&-i)
			trr[x][i]=max(trr[x][i],val);
}
int qry(int x,int y){
	int res=0;
	for(;x;x^=x&-x)
		for(int i=y;i;i^=i&-i)
			if(trr[x].count(i)) res=max(res,trr[x][i]);
	return res;
}
int a[maxn],b[maxn];
int main(){
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i) scanf("%d",b+i);
	for(int i=1;i<=n;++i) upd(a[i],b[i],qry(a[i]-1,b[i]-1)+1);
	printf("%d",qry(n,n));	
}
