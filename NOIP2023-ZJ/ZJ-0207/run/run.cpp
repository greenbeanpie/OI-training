#include<bits/stdc++.h>
using namespace std;
struct P{
	int l,r,x;
	long long v;
}q[100005];
bool cmp(P x,P y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
int n,m,k,cnt;
long long d,mx[100005],s[100005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T,i,j,o,p;
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		cnt=0;
		for(i=1;i<=m;i++){
			int x,y,l;
			long long v;
			scanf("%d%d%lld",&x,&y,&v);
			l=x-y+1;
			if(y>k)continue;
			cnt++;
			q[cnt].l=l,q[cnt].r=x,q[cnt].x=y,q[cnt].v=v;
		}
		m=cnt;
		sort(q+1,q+1+m,cmp);
		j=o=0;
		s[0]=mx[0]=0;
		for(i=1;i<=m;i++){
			s[i]=s[i-1]+q[i].v;
			mx[i]=mx[i-1];
			if(i==1){
				mx[i]=max(mx[i],q[i].v-1ll*q[i].x*d);
				o=1;
			}
			else{
				if(q[i-1].r+1>=q[i].l){
					while(q[i].r-q[o].l+1>k)o++;
				}
				else o=i;
				j=0;
				for(p=o;p<=i;p++){
					while(q[j+1].r+1<q[p].l)j++;
					mx[i]=max(mx[i],mx[j]+s[i]-s[p-1]-1ll*d*(q[i].r-q[p].l+1));
				}
			}
		}
		printf("%lld\n",mx[m]);
	}
	return 0;
}