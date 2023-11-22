#include<bits/stdc++.h>
using namespace std;
const int MS=1e5+6;
struct node{
	int l,r,v;
}a[MS];
int c,t,n,m,k,d;
int run[MS];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int cnt=0;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);			
			if(y<=k&&y*d<v){
				cnt++;
				a[cnt].r=x;
				a[cnt].l=x-y+1;
				a[cnt].v=v-y*d;
			}
		}	
		if(n<=20){
			int ans=0;
			for(int i=0;i<(1<<n);i++){
				int x=i;
				for(int j=1;j<=n;j++){
					run[j]=run[j-1]+x%2;
					x/=2;
				}	
				int flagyes=1;;
				for(int i=k+1;i<=n;i++)
					if(run[i]-run[i-k-1]==k+1){
						flagyes=0;
						break;
					}
				if(!flagyes)continue;
				int sum=0;	
				for(int k=1;k<=cnt;k++){	
					int flag=1;
					if(run[a[k].r]-run[a[k].l-1]==a[k].r-a[k].l+1)sum+=a[k].v;
				}
				ans=max(ans,sum);
			}
			printf("%d\n",ans);		
		}else{
			long long ans=0;
			for(int i=1;i<=cnt;i++)
				ans+=a[i].v;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
//伟大的CCF保佑我rp++ 
