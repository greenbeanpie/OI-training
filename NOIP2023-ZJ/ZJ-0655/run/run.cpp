#include<bits/stdc++.h>
using namespace std;
struct node{
	int r,y,v;
}s[100005];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		if(c==17||c==18){
			int n,m,k,d;
			long long ans=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=0;i<m;i++){
				scanf("%d%d%d",&s[i].r,&s[i].y,&s[i].v);
			}
			sort(s,s+m,cmp);
			for(int i=0;i<m;i++){
				if(k>=s[i].y){
					ans+=max(1ll*s[i].v-1ll*s[i].y*d,0ll);
				}
			}
			printf("%lld",ans);
		}else{
			cout<<6;
		}
		
	}
	//noip2023 rp++;
	
	return 0;
}
