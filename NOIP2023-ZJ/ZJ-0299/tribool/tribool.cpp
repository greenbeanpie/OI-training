#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int n,m,ans;
int a2[N],a3[N];
struct node{
	char opt[4];
	int x,y;
}a[N];
int zzh(char c){
	if(c=='F') return 0;
	if(c=='T') return 1;
	return 2;
}
int check(){
	for(int i=1;i<=n;i++) a3[i]=a2[i];
	for(int i=1;i<=m;i++){
		if(a[i].opt[1]=='T'||a[i].opt[1]=='F'||a[i].opt[1]=='U'){
			a3[a[i].x]=zzh(a[i].opt[1]);
		}
		else if(a[i].opt[1]=='+'){
			a3[a[i].x]=a3[a[i].y];
		}
		else{
			if(a3[a[i].y]==0){
				a3[a[i].x]=1;
				continue;
			}
			if(a3[a[i].y]==1){
				a3[a[i].x]=0;
				continue;
			}
			if(a3[a[i].y]==2){
				a3[a[i].x]=2;
				continue;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a2[i]!=a3[i]){
			return -1;
		}
		sum=sum+(a2[i]==2);
	}
	return sum;
}
void dfs(int x){
	if(x==n+1){
		int xxx=check();
		if(xxx!=-1){
			ans=min(ans,xxx);
		}
		return;
	}
	for(int i=0;i<3;i++){
		a2[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c==1||c==2){
		while(t--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%s",a[i].opt+1);
				if(a[i].opt[1]=='T'||a[i].opt[1]=='F'||a[i].opt[1]=='U'){
					scanf("%d",&a[i].x);
				}
				if(a[i].opt[1]=='+'||a[i].opt[1]=='-'){
					scanf("%d%d",&a[i].x,&a[i].y);
				}
			}
			ans=0x3f3f3f;
			dfs(1);
			printf("%d\n",ans);
		}
	}
	else if(c==3||c==4){
		while(t--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%s%d",a[i].opt+1,&a[i].x);
			}
			for(int i=1;i<=n;i++){
				a2[i]=0;
			}
			for(int i=1;i<=m;i++){
				a2[a[i].x]=zzh(a[i].opt[1]);
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				ans=ans+(a2[i]==2);
			}
			printf("%d\n",ans);
		}
	}
	else{
		while(t--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%s",a[i].opt+1);
				if(a[i].opt[1]=='T'||a[i].opt[1]=='F'||a[i].opt[1]=='U'){
					scanf("%d",&a[i].x);
				}
				if(a[i].opt[1]=='+'||a[i].opt[1]=='-'){
					scanf("%d%d",&a[i].x,&a[i].y);
				}
			}
			printf("0\n");
		}
		
	}
	return 0;
}

