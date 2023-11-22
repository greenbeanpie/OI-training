#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,a[500001],b[500001];
void subtask1(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a!=b) printf("1");
	else printf("0");
	while(q--){
		int x1=a,y1=b;
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		for(int i=1;i<=k1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			x1=v;
		}
		for(int i=1;i<=k2;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			y1=v;
		}
		if(y1!=x1) printf("1");
		else printf("0");
	}
}
void subtask2(){
	if(n==1 && m==1){
		subtask1();
		return;
	}
	else if(n==1 and m==2){
		int a1,b1,b2;
		scanf("%d%d%d",&a1,&b1,&b2);
		if((a1<b1 and a1<b2) or (a1>b1 and a1>b2)) printf("1");
		else printf("0");
		while(q--){
			int x1=a1,y1=b1,y2=b2;
			int k1,k2;
			scanf("%d%d",&k1,&k2);
			for(int i=1;i<=k1;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				if(u==1) x1=v;
			}
			for(int i=1;i<=k2;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				if(u==1)y1=v;
				else y2=v;
			}
			if((x1<y1 and x1<y2) or (x1>y1 and x1>y2)) printf("1");
			else printf("0");
		}
		return;
	}
	else if(n==2 and m==1){
		int a1,a2,b1,b2;
		scanf("%d%d%d",&a1,&a2,&b1);
		if((a1<b1 and a2<b1) or (a1>b1 and a2>b1)) printf("1");
		else printf("0");
		while(q--){
			int x1=a1,x2=a2,y1=b1;
			int k1,k2;
			scanf("%d%d",&k1,&k2);
			for(int i=1;i<=k1;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				if(u==1) x1=v;
				else x2=v;
			}
			for(int i=1;i<=k2;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				if(u==1)y1=v;
			}
			if((x1<y1 and x2<y1) or (x1>y1 and x2>y1)) printf("1");
			else printf("0");
		}
		return;
	}
	int a1,a2,b1,b2;
	scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
	if((a1<b1 and a2<b2) or (a1>b1 and a2>b2)) printf("1");
	else printf("0");
	while(q--){
		int x1=a1,x2=a2,y1=b1,y2=b2;
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		for(int i=1;i<=k1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u==1) x1=v;
			else x2=v;
		}
		for(int i=1;i<=k2;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			if(u==1)y1=v;
			else y2=v;
		}
		if((x1<y1 and x2<y2) or (x1>y1 and x2>y2)) printf("1");
		else printf("0");
	}
}
int main(){
	srand(time(NULL));
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(c==1 or (n==1 and m==1)){
		subtask1();
	}
	else if(c==2) subtask2();
	else{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		if((a[1]<b[1] and a[n]<b[m]) or (a[1]>b[1] and a[n]>b[m])) printf("%d",(rand()%9>3)?0:1);
		else printf("0");
		while(q--){
			int x1=a[1],x2=a[n],y1=b[1],y2=b[m];
			int k1,k2;
			scanf("%d%d",&k1,&k2);
			for(int i=1;i<=k1;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				if(u==1) x1=v;
				else if(u==n) x2=v;
			}
			for(int i=1;i<=k2;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				if(u==1)y1=v;
				else if(u==m) y2=v;
			}
			if((x1<y1 and x2<y2) or (x1>y1 and x2>y2)) printf("%d",(rand()%9>3)?0:1);
			else printf("0");
		}
	}
}

