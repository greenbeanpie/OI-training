#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;
il int read(){
	char c=getchar();
	int ret=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
struct Chal{
	int x,y,v;
	bool operator<(const Chal &b)const{
		if(x!=b.x)return x<b.x;
		return y<b.y;
	}
}ch[100005];
int c,t,n,m,k,d;
namespace algo2{ //O(n*k+m)
	const ll NINF=LLONG_MIN+1e9;
	ll dp[2][100005];
	il void run(){
//		cout<<"Line "<<__LINE__<<endl;
		sort(ch+1,ch+m+1);
		re(i,0,100004){
			dp[0][i]=dp[1][i]=NINF;
		}
		int cur_ch=1;
//		cout<<"Line "<<__LINE__<<endl;
		dp[0][0]=0;
		re(day,1,n){
			re(cont,0,k){
				dp[day&1][cont]=NINF;
			}
			re(j,0,k){
				dp[day&1][0]=max(dp[day&1][0],dp[day-1&1][j]);
			}
//			printf("dp[%d][%d]=%lld\n",day,0,dp[day&1][0]);
//			cout<<"Line "<<__LINE__<<endl;
			ll vsum=0;
			while(ch[cur_ch].x<day)cur_ch++;
//			cout<<"Line "<<__LINE__<<endl;
			re(cont,1,k){
				dp[day&1][cont]=max(NINF,dp[day-1&1][cont-1]-d);
//				cout<<"Line "<<__LINE__<<endl;
				while(ch[cur_ch].x==day&&ch[cur_ch].y<=cont){
//					cout<<"Line "<<__LINE__<<endl;
//					printf("cur_ch=%d\n",cur_ch);
					vsum+=ch[cur_ch].v;
					cur_ch++;
				}
//				cout<<"Line "<<__LINE__<<endl;
				dp[day&1][cont]+=vsum;
//				printf("dp[%d][%d]=%lld\n",day,cont,dp[day&1][cont]);
			}
//			cout<<"Line "<<__LINE__<<endl;
		}
//		cout<<"Line "<<__LINE__<<endl;
		ll ans=NINF;
		re(cont,0,k){
			ans=max(ans,dp[n&1][cont]);
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	re(round,1,t){
		n=read(),m=read(),k=read(),d=read();
		re(i,1,m){
			ch[i].x=read(),ch[i].y=read(),ch[i].v=read();
		}
		algo2::run();
	}
	return 0;
}
