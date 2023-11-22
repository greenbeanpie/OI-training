#include<bits/stdc++.h>
using namespace std;
int c,t,sum;
int n,m,k,d,MAX,ans;
int x,y,v,tx[114514],ty[114514],tv[114514],cnt=1;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>k>>d;
		while(m--){
			cin>>x>>y>>v;
			if(x-y+1<1)continue;
			if(y>k)continue;
			if(d*y>=v)continue;
			if(n<y)continue;
			tx[cnt]=x;
			ty[cnt]=y;
			tv[cnt]=v;
			cnt++;
	    }
	    for(int i=1;i<=cnt-1;i++){
	    	sum=0;
	    	MAX=-1;
	    	for(int j=i;j<=cnt-1;j++){
	    		if(sum+ty[j]<=n){
	    			sum+=ty[j];
	    			MAX=max(MAX,MAX-ty[j]*d+tv[j]);
				}else{
					break;
				}
			}
			ans=max(ans,MAX);
		}
		cout<<ans<<endl;
	}
	return 0;
}
