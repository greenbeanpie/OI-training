#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+5;

int c,n,m,q;
int x[N],y[N],cp_x[N],cp_y[N];
int kx,ky;
int px,vx,py,vy;
int sum;

void solve1(){
	if(x[1]!=y[1]) printf("1");
	else printf("0");
	
	while(q--){
		scanf("%d%d",&kx,&ky);
		memcpy(cp_x,x,sizeof(x));
		memcpy(cp_y,y,sizeof(y));
		for(int i=1;i<=kx;++i){
			scanf("%d%d",&px,&vx);
			cp_x[px]=vx;
		}
		for(int i=1;i<=ky;++i){
			scanf("%d%d",&py,&vy);
			cp_y[py]=vy;
		}
		if(cp_x[1]!=cp_y[1]) printf("1");
		else printf("0");
	}
}

void solve2(){
	if(n==1 and m==2){
		if(x[1]>max(y[1],y[2]) or x[1]<min(y[1],y[2]))
			printf("1");
		else printf("0");
	}
	if(n==2 and m==1){
		if(y[1]>max(x[1],x[2]) or y[1]<min(x[1],x[2]))
			printf("1");
		else printf("0");
	}
	if(n==2 and m==2){
		if((x[1]>y[1] and x[2]>y[2]) or (x[1]<y[1] and x[2]<y[2]))
			printf("1");
		else printf("0");
	}
	while(q--){
		scanf("%d%d",&kx,&ky);
		memcpy(cp_x,x,sizeof(x));
		memcpy(cp_y,y,sizeof(y));
		for(int i=1;i<=kx;++i){
			scanf("%d%d",&px,&vx);
			cp_x[px]=vx;
		}
		for(int i=1;i<=ky;++i){
			scanf("%d%d",&py,&vy);
			cp_y[py]=vy;
		}
		if(n==1 and m==2){
			if(cp_x[1]>max(cp_y[1],cp_y[2]) or cp_x[1]<min(cp_y[1],cp_y[2]))
				printf("1");
			else printf("0");
		}
		if(n==2 and m==1){
			if(cp_y[1]>max(cp_x[1],cp_x[2]) or cp_y[1]<min(cp_x[1],cp_x[2]))
				printf("1");
			else printf("0");
		}
		if(n==2 and m==2){
			if((cp_x[1]>cp_y[1] and cp_x[2]>cp_y[2]) or (cp_x[1]<cp_y[1] and cp_x[2]<cp_y[2]))
				printf("1");
			else printf("0");
		}
	}
}

void solve3(){
	bool flag=true;
	if(x[1]>y[1]){
		int j=2,i;
		for(i=1;i<=n;++i){
			sum=0;
			if(i==1) sum++;
			if(j>m) break;
			while(j<=m and x[i]>y[j]) j++,sum++;
			while(!sum and j>=1){
				j--;
				if(x[i]>y[j]) sum++;
			}
			if(!sum){flag=false;break;}
		}
		if(j>m){
			for(;i<=n;++i)
				if(x[i]<=y[m]){flag=false;break;}
		}
		else if(i>n){
			for(;j<=m;++j)
				if(x[n]<=y[j]){flag=false;break;}
		}
		if(flag) printf("1");
		else printf("0");
	}
	else if(x[1]<y[1]){
		int j=2,i;
		for(i=1;i<=n;++i){
			sum=0;
			if(i==1) sum++;
			if(j>m) break;
			while(j<=m and x[i]<y[j]) j++,sum++;
			while(!sum and j>=1){
				j--;
				if(x[i]>y[j]) sum++;
			}
			if(!sum){flag=false;break;}
		}
		if(j>m){
			for(;i<=n;++i)
				if(x[i]>=y[m]){flag=false;break;}
		}
		else if(i>n){
			for(;j<=m;++j)
				if(x[n]>=y[j]){flag=false;break;}
		}
		if(flag) printf("1");
		else printf("0");
	}
	else printf("0");
	
	while(q--){
		scanf("%d%d",&kx,&ky);
		memcpy(cp_x,x,sizeof(x));
		memcpy(cp_y,y,sizeof(y));
		flag=true;
		for(int i=1;i<=kx;++i){
			scanf("%d%d",&px,&vx);
			cp_x[px]=vx;
		}
		for(int i=1;i<=ky;++i){
			scanf("%d%d",&py,&vy);
			cp_y[py]=vy;
		}
		if(cp_x[1]>cp_y[1]){
			int j=2,i;
			for(i=1;i<=n;++i){
				sum=0;
				if(i==1) sum++;
				if(j>m) break;
				while(j<=m and cp_x[i]>cp_y[j]) j++,sum++;
				while(!sum and j>=1){
					j--;
					if(cp_x[i]>cp_y[j]) sum++;
				}
				if(!sum){flag=false;break;}	
			}
			if(j>m){
				for(;i<=n;++i)
					if(cp_x[i]<=cp_y[m]){flag=false;break;}
			}
			else if(i>n){
				for(;j<=m;++j)
					if(cp_x[n]<=cp_y[j]){flag=false;break;}
			}
			if(flag) printf("1");
			else printf("0");
		}
		else if(cp_x[1]<cp_y[1]){
			int j=2,i;
			for(i=1;i<=n;++i){
				sum=0;
				if(i==1) sum++;
				if(j>m) break;
				while(j<=m and cp_x[i]<cp_y[j]) j++,sum++;
				while(!sum and j>=1){
					j--;
					if(cp_x[i]>cp_y[j]) sum++;
				}
				if(!sum){flag=false;break;}
			}
			if(j>m){
				for(;i<=n;++i)
					if(cp_x[i]>=cp_y[m]){flag=false;break;}
			}
			else if(i>n){
				for(;j<=m;++j)
					if(cp_x[n]>=cp_y[j]){flag=false;break;}
			}
			if(flag) printf("1");
			else printf("0");
		}
		else printf("0");
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%d",&x[i]);
	for(int i=1;i<=m;++i) scanf("%d",&y[i]);
	
	if(n==1 and m==1) solve1();
	if(c==2) solve2();
	solve3();
	return 0;
}
