#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int MAXN = 1e5+7;
inline read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int c,t;
struct node{
	int l,r,v,t;
}q[MAXN];
namespace solve{
	void A(){
		while(t--){
			int n=read(),m=read(),k=read(),d=read();
			up(i,1,m){
				q[i].r=read();
				q[i].l=q[i].r-read()+1;
				q[i].v=read();
				
			}
			
		}
	}
	void B(){
		while(t--){
			int n=read(),m=read(),k=read(),d=read();
			int ans = 0;
			up(i,1,m){
				q[i].r=read();
				q[i].t=read();
				q[i].l=q[i].r-q[i].t+1;
				q[i].v=read();
				if(q[i].t<=k)ans = max(ans,ans+q[i].v-q[i].t*d);
			}
			printf("%lld\n",ans);
		}		
	}
	void mian(){
		c = read(),t = read();
		if(c==15||c==16){
			A();
		}
		if(c==17||c==18){
			B();
		}
		return ;
	}	
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	solve::mian();
	return 0;
}

