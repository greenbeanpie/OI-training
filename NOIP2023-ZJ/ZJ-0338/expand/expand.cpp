#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int c,n,m,q;
int a[N],b[N],vx[N],vy[N];
bool f[3100][3100];
int px[N],py[N];
bool res[N];
bool ur;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	if((a[1]==b[1])||(a[1]-b[1]>0?a[n]-b[m]<=0:a[n]-b[m]>=0)){
//		cout<<"dibodibo";
		res[0]=0;
	}else{
		if(a[1]<b[1]){
			ur=1;
		}else{
			ur=0;
		}
		f[1][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ur?a[i]<b[j]:a[i]>b[j]){
					f[i][j]=f[i][j]||f[i-1][j]||f[i][j-1];
				}
			}
		}
		res[0]=f[n][m];
	}
	int dibo=0;
	int kx,ky;
	while(q){
		q--;
		scanf("%d%d",&kx,&ky);
		for(int i=0;i<kx;i++){
			scanf("%d%d",&px[i],&vx[i]);
//			a[px[i]]=vx[i];
			swap(a[px[i]],vx[i]);
		}
		for(int i=0;i<ky;i++){
			scanf("%d%d",&py[i],&vy[i]);
//			b[py[i]]=vy[i];
			swap(b[py[i]],vy[i]);
		}
		if(a[1]==b[1]||a[n]==b[m]){
			res[++dibo]=0;
			for(int i=0;i<kx;i++){
				swap(a[px[i]],vx[i]);
			}
			for(int i=0;i<ky;i++){
				swap(b[py[i]],vy[i]);
			}
			continue;
		}
		if(a[1]<b[1]){
			if(a[n]>b[m]){
				res[++dibo]=0;
				for(int i=0;i<kx;i++){
					swap(a[px[i]],vx[i]);
				}
				for(int i=0;i<ky;i++){
					swap(b[py[i]],vy[i]);
				}
//				cout<<"dibodibo";
				continue;
			}
			ur=1;
		}else{
			if(a[n]<b[m]){
//				cout<<"dibodibo";
				res[++dibo]=0;
				for(int i=0;i<kx;i++){
					swap(a[px[i]],vx[i]);
				}
				for(int i=0;i<ky;i++){
					swap(b[py[i]],vy[i]);
				}
				continue;
			}
			ur=0;
		}
		memset(f,0,sizeof(f));
		f[1][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ur?a[i]<b[j]:a[i]>b[j]){
					f[i][j]=f[i][j]||f[i-1][j]||f[i][j-1];
				}
			}
		}
		res[++dibo]=f[n][m];
		for(int i=0;i<kx;i++){
			swap(a[px[i]],vx[i]);
		}
		for(int i=0;i<ky;i++){
			swap(b[py[i]],vy[i]);
		}
	}
	for(int i=0;i<=dibo;i++)cout<<res[i];
}
