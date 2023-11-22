#include<bits/stdc++.h>
using namespace std;

int c,t,n,m,k,d,x,y,v,ans,po,cnt;
bool r[10000010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=14||c>=22){
		while(t--){
			ans=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			while(m--){
				ans=po;cnt=0;
				scanf("%d%d%d",&x,&y,&v);
				if(x-y>=0&&y<=k&&v>d*y){
					ans+=v;
					for(int i=x-y+1;i<=x;i++){
						if(!r[i]) ans--;
						r[i]=1;
					}
					for(int i=1;i<=x;i++){
						if(r[i]) cnt++;
						else cnt=0;
					}
					if(cnt<=k) po=ans;
				}
			}
			cout<<po<<endl;
		}
	}else if(c==15||c==16){
		while(t--){
			ans=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			while(m--){
				ans=po;cnt=0;
				scanf("%d%d%d",&x,&y,&v);
				if(x-y>=0&&y<=k&&v>d*y){
					ans+=v;
					for(int i=x-y+1;i<=x;i++){
						if(!r[i]) ans--;
						r[i]=1;
					}
					for(int i=1;i<=x;i++){
						if(r[i]) cnt++;
						else cnt=0;
					}
					if(cnt<=k) po=ans;
				}
			}
			cout<<po<<endl;
		}
	}else if(c==17||c==18){
		while(t--){
			ans=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			while(m--){
				ans=po;cnt=0;
				scanf("%d%d%d",&x,&y,&v);
				if(x-y>=0&&y<=k&&v>d*y){
					ans+=v;
					for(int i=x-y+1;i<=x;i++){
						if(!r[i]) ans--;
						r[i]=1;
					}
					for(int i=1;i<=x;i++){
						if(r[i]) cnt++;
						else cnt=0;
					}
					if(cnt<=k) po=ans;
				}
			}
			cout<<po<<endl;
		}
	}else if(c==19||c==20||c==21){
		while(t--){
			ans=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			while(m--){
				ans=po;cnt=0;
				scanf("%d%d%d",&x,&y,&v);
				if(x-y>=0&&y<=k&&v>d*y){
					ans+=v;
					for(int i=x-y+1;i<=x;i++){
						if(!r[i]) ans--;
						r[i]=1;
					}
					for(int i=1;i<=x;i++){
						if(r[i]) cnt++;
						else cnt=0;
					}
					if(cnt<=k) po=ans;
				}
			}
			cout<<po<<endl;
		}
	}
	return 0;
}