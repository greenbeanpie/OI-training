#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MaxM=1e5+50;
struct chal{
	int x,y,v;
}c[MaxM];
ll f[MaxM][2];
int n,m,k,d,C,t,M;
bool cmp(chal x,chal y){
	return x.x<y.x || (x.x==y.x && x.y<y.y);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&C,&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<m+1;i++){
			scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].v);
			if(c[i].y<=k){
				c[++M].x=c[i].x;
				c[M].y=c[i].y;
				c[M].v=c[i].v;
			}
			f[i][0]=f[i][1]=0;
		}
		m=M;
		sort(c+1,c+m+1,cmp);
		for(int i=1;i<m+1;i++){
			f[i][0]=max(f[i-1][0],f[i-1][1]);
			for(int j=0;j<i;j++){
				if(c[i].x-c[i].y<=c[j].x-c[j].y)
					f[i][1]=max(f[i][1],f[j][1]-1ll*(c[i].y-c[j].y)*d+c[i].v);
				else
				if(c[i].x-c[i].y<c[j].x && c[i].x-c[j].x+c[j].y<=k)
					f[i][1]=max(f[i][1],f[j][1]-1ll*(c[i].x-c[j].x)*d+c[i].v);
				else
				if(c[i].x-c[i].y+1>c[j].x)
					f[i][1]=max(f[i][1],f[j][1]-1ll*c[i].y*d+c[i].v);
			}
		}
		printf("%lld\n",max(f[m][1],f[m][0]));
	}
	return 0;
}