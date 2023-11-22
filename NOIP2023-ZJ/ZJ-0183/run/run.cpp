#include <bits/stdc++.h>
using namespace std;
struct nd{
	long long l,r,v;
}cl[100001];
int c,t,n,m,k,d,x,y,z;
long long s=0,dd[100001];
bool cmp(nd cla,nd clb){
	return cla.r<clb.r;
}
bool b[100001];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d %d %d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			scanf("%lld %lld %lld",&cl[i].r,&cl[i].l,&cl[i].v);
			cl[i].l=cl[i].r-cl[i].l+1;
			b[i]=0;
		}
		sort(cl+1,cl+m+1,cmp);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=i;j++) if(cl[i].l>cl[j].r) dd[i]=max(dd[i],dd[j]+cl[i].v-(+cl[i].r-cl[j].r+1)*d);
			s=max(s,dd[i]);
		}
		printf("%lld\n",s);
	}
}