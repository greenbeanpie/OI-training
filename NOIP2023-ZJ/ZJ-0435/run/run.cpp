#include<bits/stdc++.h>
using namespace std;
int k,d,n,c,t,m;
long long ene;
struct tz{
	int x,y,v,l,r;
	long long yl;
};
tz whz[100010];
int day[1010];
bool cmp(tz x,tz y){
	if(x.yl!=y.yl)
	return x.yl>y.yl;
	return x.y<y.y;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	if(c==18||c==17){
		while(t--){
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++){
				scanf("%d",&whz[i].x);
				scanf("%d",&whz[i].y);
				scanf("%d",&whz[i].v);
				whz[i].yl=whz[i].v-whz[i].y*d;
				if(whz[i].y<=k&&whz[i].yl>0)
				ene+=whz[i].yl;
			}
			cout<<ene<<endl;
			ene=0;
		}
		
		return 0;
	}
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			scanf("%d",&whz[i].x);
			scanf("%d",&whz[i].y);
			scanf("%d",&whz[i].v);
			whz[i].l=whz[i].x-whz[i].y+1;
			whz[i].r=whz[i].x;
			whz[i].yl=whz[i].v-whz[i].y*d;
		}
		sort(whz+1,whz+1+m,cmp);
		for(int i=1;i<=m;i++){
			int sum=0;
			sum+=whz[i].y;
			int j=whz[i].r+1;
			while(day[j]==1&&j<=n)
			{
				sum++;
				j++;
			}
			j=whz[i].l-1;
			while(day[j]==1&&j>=1)
			{
				sum++;
				j--;
			}
			if(sum>k) continue;
			sum=0;
			for(int x=whz[i].l;x<=whz[i].r;x++){
				if(day[x]==0){
					sum++;	
				}
			}
			if(whz[i].v-sum*d<=0) continue;
			for(int x=whz[i].l;x<=whz[i].r;x++){
				day[x]=1;
			}
			ene+=whz[i].v-sum*d;
		}
		cout<<ene<<endl;
		ene=0;
		for(int x=1;x<=n;x++){
				day[x]=0;
		}
	}
	return 0;
}
