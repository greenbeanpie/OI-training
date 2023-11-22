#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[500050];
int y[500050];
int maxc[500050];
int minc[500050];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=500005;i++){
		x[i]=-1;
		y[i]=-1;
	}
	if(c>=2&&c<=7){
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&y[i]);
		}
		bool flag1=1;
		if(x[1]>y[1]){
			int minn=y[1];
			int last=x[n];
			for(int i=1;i<=max(n,m);i++){
				if(y[i]<minn&&y[i]!=-1){
					minn=y[i];
				}
				if((x[i]<=minn&&x[i]!=-1)||(x[i]==-1&&last<=minn)){
					flag1=0;
					printf("%d",0);
					break;
				}
			}
			if(flag1){
				printf("%d",1);
			}
		}
		else if(x[1]<y[1]){
			int minn=x[1];
			int last=y[n];
			for(int i=1;i<=max(n,m);i++){
				if(x[i]<minn&&x[i]!=-1){
					minn=x[i];
				}
				if((y[i]<=minn&&y[i]!=-1)||(y[i]==-1&&last<=minn)){
					flag1=0;
					printf("%d",0);
					break;
				}
			}
			if(flag1){
				printf("%d",1);
			}
		}
		else{
			printf("%d",0);
		}
		for(int j=1;j<=q;j++){
			int xx,yy;
			int pos,to;
			scanf("%d%d",&xx,&yy);
			for(int k=1;k<=xx;k++){
				scanf("%d%d",&pos,&to);
				x[pos]=to;
			}
			for(int k=1;k<=yy;k++){
				scanf("%d%d",&pos,&to);
				y[pos]=to;
			}
			if(x[1]>y[1]){
				bool flag=1;
				int mind=y[1];
				int las=x[n];
				for(int i=1;i<=max(n,m);i++){
					if(y[i]<mind&&y[i]!=-1){
						mind=y[i];
					}
					if((x[i]<=mind&&x[i]!=-1)||(x[i]==-1&&las<=mind)){
						flag=0;
						printf("%d",0);
						break;
					}
				}
				if(flag){
					printf("%d",1);
				}
			}
			else if(x[1]<y[1]){
				bool flag=1;
				int mind=x[1];
				int las=y[n];
				for(int i=1;i<=max(n,m);i++){
					if(x[i]<mind&&x[i]!=-1){
						mind=x[i];
					}
					if((y[i]<=mind&&y[i]!=-1)||(y[i]==-1&&las<=mind)){
						flag=0;
						printf("%d",0);
						break;
					}
				}
				if(flag){
					printf("%d",1);
				}
			}
			else{
				printf("%d",0);
			}
		}
	}
	if(c==1){
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&y[i]);
		}
		if(x[1]!=y[1]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		for(int i=1;i<=q;i++){
			int xx,yy;
			int pos,to;
			cin>>xx>>yy;
			for(int j=1;j<=xx;j++){
				cin>>pos>>to;
				x[pos]=to;
			}
			for(int j=1;j<=yy;j++){
				cin>>pos>>to;
				y[pos]=to;
			}
			if(x[1]!=y[1]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
//	else if(c>=8&&c<=14){
//		scanf("%d%d",&n,&m);
//		int maxx=-1;
//		int minn=0x3f3f3f3f;
//		for(int i=1;i<=n;i++){
//			scanf("%d",&x[i]);
//			maxx=max(maxx,x[i]);
//		}
//		for(int i=1;i<=m;i++){
//			scanf("%d",&y[i]);
//			minn=min(minn,y[i]);
//		}
//		if(minn)
//	}
	return 0;
}
