#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=2e6;
int n,m,q;
int a[N],b[N];
int ysa[N],ysb[N];
int now_maxxa,now_maxxb,now_minna,now_minnb;
void check(){
	if(n==1){
		if(a[1]!=b[1]) printf("1");
		else printf("0");
		return;
	}
	else if(n==2){
		if(a[1]>b[1]&&a[2]>b[2]) printf("1");
		else if(a[1]<b[1]&&a[2]<b[2]) printf("1");
		else printf("0");
		return;
	}
	if((a[1]-b[1])*(a[n]-b[m])<=0){
		printf("0");
		return;
	}
	else if(a[1]>b[1]){
		if(now_maxxa>now_maxxb&&now_minna>now_minnb) printf("1");
		else printf("0");
		return;
	}
	else{
		if(now_maxxa<now_maxxb&&now_minna<now_minnb) printf("1");
		else printf("0");
		return;
	}
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int idx=read();n=read(),m=read(),q=read();
	int maxxa=0,minna=1e18;
	int maxxb=0,minnb=1e18;
	for(int i=1;i<=n;i++){
		a[i]=ysa[i]=read();
		if(ysa[i]>maxxa) maxxa=ysa[i];
		if(ysa[i]<minna) minna=ysa[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=ysb[i]=read();
		if(ysb[i]>maxxb) maxxb=ysb[i];
		if(ysb[i]<minnb) minnb=ysb[i];
	}
	if(idx>=8&&idx<=14){
		int minn=1e18;
		for(int i=1;i<=m;i++) minn=min(minn,b[i]);
		if(minn>a[1]&&b[m]>maxxa) printf("1");
		else printf("0");
		for(int t=1;t<=q;t++){
			now_maxxa=0,now_maxxb=0,now_minna=1e17,now_minnb=1e17;
			int x=read(),y=read();
			for(int i=1;i<=n;i++) a[i]=ysa[i];
			for(int j=1;j<=x;j++){
				int loc=read(),kk=read();
				a[loc]=kk;
			}
			for(int i=1;i<=n;i++) now_maxxa=max(now_maxxa,a[i]),now_minna=min(now_minna,a[i]); 
			for(int i=1;i<=m;i++) b[i]=ysb[i];
			for(int j=1;j<=y;j++){
				int loc=read(),kk=read();
				b[loc]=kk;
			}
			for(int i=1;i<=m;i++) now_maxxb=max(now_maxxb,b[i]),now_minnb=min(now_minnb,b[i]); 
			if(now_minnb>a[1]&&b[m]>now_maxxa) printf("1");
			else printf("0");
		}
		return 0;
	}
	now_maxxa=maxxa,now_maxxb=maxxb,now_minna=minna,now_minnb=minnb;
	check();
	for(int t=1;t<=q;t++){
		now_maxxa=0,now_maxxb=0,now_minna=1e17,now_minnb=1e17;
		int x=read(),y=read();
		for(int i=1;i<=n;i++) a[i]=ysa[i];
		for(int j=1;j<=x;j++){
			int loc=read(),kk=read();
			a[loc]=kk;
		}
		for(int i=1;i<=n;i++) now_maxxa=max(now_maxxa,a[i]),now_minna=min(now_minna,a[i]); 
		for(int i=1;i<=m;i++) b[i]=ysb[i];
		for(int j=1;j<=y;j++){
			int loc=read(),kk=read();
			b[loc]=kk;
		}
		for(int i=1;i<=m;i++) now_maxxb=max(now_maxxb,b[i]),now_minnb=min(now_minnb,b[i]); 
		check();
	}
	return 0;
}