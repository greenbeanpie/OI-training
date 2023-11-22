#include<bits/stdc++.h>
using namespace std;
const int N1=15,N2=1e5+100;
struct node{
	int op,i,j;
	//op==3 xi <- xj
	//op==4 xi <- !xj
	//op==0 xi <- T	0
	//op==2 xi <- F	2
	//op==1 xi <- U	1
}a[N2];
int n,m;
int arr[N2];
void solve2(){
	memset(arr,0,sizeof(arr));
	for (int i=1;i<=m;++i){
		if (a[i].op==1) arr[a[i].i]=a[i].op;
		if (a[i].op==3){
			arr[a[i].i]=arr[a[i].j];
		}
	}
	for (int i=1;i<=m;++i){
		if (a[i].op==3){
			if (arr[a[i].j]==1)	
				arr[a[i].i]=arr[a[i].j];
		}
	}
	int sum=0;
	for (int i=1;i<=n;++i){
		if (arr[i]==1) ++sum;
	}
	printf("%d\n",sum);
}
void solve1(){
	memset(arr,0,sizeof(arr));
	for (int i=1;i<=m;++i){
		arr[a[i].i]=a[i].op;
	}
	int sum=0;
	for (int i=1;i<=n;++i){
		if (arr[i]==1) ++sum;
	}
	printf("%d\n",sum);
}
int c[N1],b[N1],ans;
bool check(){
	for (int i=1;i<=n;++i){
		b[i]=c[i];
	}
	for (int i=1;i<=m;++i){
		if (a[i].op<3){
			b[a[i].i]=a[i].op;
		}
		else{
			if (a[i].op==3){
				b[a[i].i]=b[a[i].j];
			}
			else if (a[i].op==4){
				b[a[i].i]=2-b[a[i].j];
			}
		}
	}
	for (int i=1;i<=n;++i){
		if (c[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}
void dfs(int x,int sum){
	if (x==n+1){
		if (sum<ans&&check()){
			ans=sum;
		}
		return;
	}
	for (int i=0;i<=2;++i){
		c[x]=i;
		dfs(x+1,sum+(i==1?1:0));
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while (T--){
		ans=0x7f7f7f7f;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;++i){
			char c[10];
			scanf("%s%d",c,&a[i].i);
			if (c[0]=='+'){
				scanf("%d",&a[i].j);
				a[i].op=3;
			}
			else if (c[0]=='-'){
				scanf("%d",&a[i].j);
				a[i].op=4;
			}
			else{
				if (c[0]=='T') a[i].op=0;
				else if (c[0]=='F') a[i].op=2;
				else if (c[0]=='U') a[i].op=1;
			}
		}
		if (n<=10){
			dfs(1,0);
			printf("%d\n",ans);
		}
		else if (C==3||C==4){
			solve1();
		}
		else if (C==5||C==6){
			solve2();
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
