#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Amadeus{
	int x,y,v;
	bool operator<(const Amadeus b)const{return x<b.x;}
}a[100005];
struct ZS{
	int x,y,v;
	bool operator<(const ZS b)const{return x-y<b.x-y;}
}b[100005];
int c,t;
int n,m,k,d;
int ans;
int f[100005],s[100005];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();t=read();
	if(c<=14){
		while(t--){
			memset(f,0,sizeof f);
			n=read();m=read();k=read();d=read();
			for(int i=1;i<=m;i++){
				int x=read(),y=read(),v=read();
				a[i]=(Amadeus){x,y,v};
				b[i]=(ZS){x,y,v};
			}
			sort(a+1,a+1+m);sort(b+1,b+1+m);
			for(int i=1;i<=m;i++){
				int now=a[i].x-a[i].y+1;
				int K=m,KK=m;
				for(int j=m;j>=1;j--)if(b[j].x-b[j].y+1<=now){K=j;break;}
				for(int j=K;j>=1;j--)if(k<a[i].x-(b[j].x-b[j].y+1)+1)break;
				else{
					while(b[j].x-b[j].y+1<=a[KK].x)KK--;
					int SS=0;
					for(int g=1;g<=m;g++)if(b[j].x-b[j].y+1<=a[g].x-a[g].y+1&&a[g].x<=a[i].x)SS+=a[g].v;
					f[i]=max(f[i],f[KK]+SS-(a[i].x-(b[j].x-b[j].y+1)+1)*d);
				}
				f[i]=max(f[i],f[i-1]);
			}
			printf("%lld\n",f[m]);
		}
	}
	if(c==17||c==18){
		while(t--){
			n=read();m=read();k=read();d=read();
			for(int i=1;i<=m;i++){
				int x=read(),y=read(),v=read();
				if(y<=k&&y*d<=v)ans+=v-y*d;
			}
			printf("%lld\n",ans);ans=0;
		}
	}
	return 0;
}