#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c) && c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int n,m;
int a[N];
int path3[5005][5005],top3[N];
struct node{
	int x,y;
	int opt;
}path1[N];
int init[N],Ans;
void dfs(int p){
	if(p==n+1){
//		for(int i=1;i<=n;i++) printf("%d ",init[i]);
//		printf("\n");
		for(int i=1;i<=n;i++) a[i]=init[i];
		for(int i=1;i<=m;i++){
			int xx=path1[i].x,yy=path1[i].y,op=path1[i].opt;
			if(op<=2) a[xx]=op;
			if(op==3) a[xx]=a[yy];
			if(op==4){
				if(a[yy]==0) a[xx]=1;
				if(a[yy]==1) a[xx]=0;
				if(a[yy]==2) a[xx]=2;
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=init[i]){
				flag=false;
				break;
			}
		}
		int cnt=0;
		if(flag){
			for(int i=1;i<=n;i++){
				if(init[i]==2) cnt++;
			}
			//printf("%d ",cnt);
			Ans=min(Ans,cnt);
		}
		return;
	}
	for(int k=0;k<=2;k++){
		int pre=init[p];
		init[p]=k;
		dfs(p+1);
		init[p]=pre;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	c=read(); T=read();
	if(c==3 || c==4){
		while(T--){
			n=read(); m=read();
			int ans=0;
			for(int i=1;i<=m;i++){
				char v=getchar();
				int p=read();
				if(v=='T') path3[p][++top3[p]]=0;
				else if(v=='F') path3[p][++top3[p]]=1;
				else path3[p][++top3[p]]=2;
			}
			for(int i=1;i<=n;i++){
				for(int k=0;k<3;k++){
					int now=k;
					for(int j=1;j<=top3[i];j++){
						if(path3[i][j]==0) now=0;
						else if(path3[i][j]==1) now=1;
						else{
							if(now==0) now=1;
							if(now==1) now=0;
							if(now==2) now=2;
						}
					}
					if(now==k && now==2) ans++;
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	
	while(T--){
		Ans=(1<<30);
		n=read(); m=read();
		for(int i=1;i<=n+1;i++) init[i]=0;
		for(int i=1;i<=m+1;i++)
			path1[i].x=path1[i].y=path1[i].opt=0;
		for(int i=1;i<=m;i++){
			char v=getchar();
			if(v=='T'){
				int p=read();
				//printf("\n%d\n",p);
				path1[i].x=p;
				path1[i].opt=0;
			}
			else if(v=='F'){
				int p=read();
				//printf("\n%d\n",p);
				path1[i].x=p;
				path1[i].opt=1;
			}
			else if(v=='U'){
				int p=read();
				//printf("\n%d\n",p);
				path1[i].x=p;
				path1[i].opt=2;
			}
			else if(v=='+'){
				int xx,yy;
				xx=read(); yy=read();
				//printf("\n%d %d\n",xx,yy);
				path1[i].x=xx;
				path1[i].y=yy;
				path1[i].opt=3;
			}
			else if(v=='-'){
				int xx,yy;
				xx=read(); yy=read();
				//printf("\n%d %d\n",xx,yy);
				path1[i].x=xx;
				path1[i].y=yy;
				path1[i].opt=4;
			}
		}
//		for(int i=1;i<=m;i++)
//			printf("%d %d %d\n",path1[i].x,path1[i].y,path1[i].opt);
//		printf("\n");
		dfs(1);
		printf("%d\n",Ans);
	}
	return 0;
}
//2 1
//10 10
//- 7 3
//- 5 3
//+ 3 7
//- 1 6
//+ 4 6
//- 8 4
//- 6 8
//+ 2 2
//- 9 9
//- 10 10


//1 3
//3 3
//- 2 1
//- 3 2
//+ 1 3
//3 3
//- 2 1
//- 3 2
//- 1 3
//2 2
//T 2
//U 2
