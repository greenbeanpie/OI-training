#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	long long x,y,v;
}z[100003];
int c,t,m,E,w,i,j;
long long n,k,d,p[200003],D[100003],tree[200003],ans,sum;
bool cmp(node A,node B){return A.x<B.x;}
int find(long long x){
	int l=1,r=E,mid,A=-1;
	while(l<=r){
		mid=(l+r)/2;
		if(p[mid]>=x)  A=mid,r=mid-1;
		else  l=mid+1;
	}
	return A;
}
void p1(int x,long long X){while(x!=0&&x<=m)  tree[x]+=X,x+=x&-x;}
long long p2(int x){
	long long sum=0;
	while(x>0)  sum+=tree[x],x-=x&-x;
	return sum;
}
int main(){
	freopen("run.in","r",stdin),freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==17||c==18){
		while(t--){
			for(scanf("%lld%d%lld%lld",&n,&m,&k,&d),ans=0,i=1;i<=m;i++){
				scanf("%lld%lld%lld",&z[i].x,&z[i].y,&z[i].v);
				if(z[i].y<=k&&z[i].v-d*z[i].y>0)  ans+=z[i].v-d*z[i].y;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(t--){
		for(scanf("%lld%d%lld%lld",&n,&m,&k,&d),i=1;i<=m;i++)  scanf("%lld%lld%lld",&z[i].x,&z[i].y,&z[i].v),p[2*i-1]=z[i].x,p[2*i]=z[i].x-z[i].y+1;
		for(sort(z+1,z+m+1,cmp),sort(p+1,p+2*m+1),E=0,i=1;i<=2*m;i++)
			if(p[i]!=p[i-1])  p[++E]=p[i];
		for(ans=-1,i=1;i<=m;i++){
			D[i]=D[i-1],p1(find(z[i].x-z[i].y+1),z[i].v);
			for(j=1;j<=i;j++){
				if(z[i].x-(z[j].x-z[j].y)>k)  continue;
				sum=p2(find(z[i].x))-p2(find(z[j].x-z[j].y+1)-1)-(z[i].x-(z[j].x-z[j].y))*d;
				sum+=D[find(z[j].x-z[j].y)-1],D[i]=max(D[i],sum);
			}
			ans=max(ans,D[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
