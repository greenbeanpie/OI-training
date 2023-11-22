#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

#define N 100005
const int bs=1e5;
int C,T,x,y,n,m,t;
int dad[N],siz[N],vis[N];
int ans[N];
char opt;
int find(int x){
	return x==dad[x]? x:dad[x]=find(dad[x]);
}
void join(int x,int y){
	int f1=find(x),f2=find(y);
	if (f1!=f2) dad[f1]=f2,siz[f2]+=siz[f1];
}
void work1(){
	while (m--){
		cin>>opt;
		if (opt=='+'){
			scanf("%d%d",&x,&y);
			vis[x]=y;
		}else if (opt=='-'){
		    scanf("%d%d",&x,&y);
		    vis[x]=-y;
		}else {
			scanf("%d",&x);
			if (opt=='T') vis[x]=bs+1;
			else if (opt=='F') vis[x]=bs+2;
			else vis[x]=bs+3;
		}
	}
	for (int i=1 ; i<=n ; i++){
		if (vis[i]==0) continue;
		if (vis[i]>bs){
			ans[i]=vis[i]-bs;
		}else{
			join(i,vis[i]);
		}
	}
	int Ans=0;
	for (int i=1 ; i<=n ; i++){
		if (ans[i]==3){
			int f1=find(i);
			Ans+=siz[f1];
		}
	}
	printf("%d\n",Ans);
}
void work2(){
	int cnt=0;
	while (m--){
		cin>>opt;
		if (opt=='+'){
			scanf("%d%d",&x,&y);
			vis[x]=y;
		}else if (opt=='-'){
		    scanf("%d%d",&x,&y);
		    vis[x]=-y;
		}else {
			scanf("%d",&x);
			if (opt=='T') vis[x]=bs+1;
			else if (opt=='F') vis[x]=bs+2;
			else vis[x]=bs+3;
			cnt++;
		}
	}
	printf("%d\n",cnt);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	for (t=1 ; t<=T ; t++){
		scanf("%d%d",&n,&m);
		for (int i=1 ; i<=n ; i++){
			dad[i]=i;
			siz[i]=1;
			vis[i]=ans[i]=0;
		}
		
		if (C>=3 && C<=6) work1();
		else work2();
	}
	
	return 0;
}