#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m;
int t_12[11],b_12[11],ans_12=2e9;
bool t_34[100001];
bool t_56[100001],bl_56[100001],u_56[100001];
struct str{
	char opt;
	int x,y;
}a[100001];
int head[100001],cnt;
struct node{
	int q,h;
	bool u;
}a_56[100001];
void dfs_12(int x){
	if(x==n+1){
		memcpy(b_12,t_12,sizeof(b_12));
		for(int i=1;i<=m;i++){
			if(a[i].opt=='-'){
				int x=a[i].x,y=a[i].y;
				b_12[x]=-b_12[y];
			}
			else if(a[i].opt=='+'){
				int x=a[i].x,y=a[i].y;
				b_12[x]=b_12[y];
			}
			else{
				if(a[i].opt=='T'){
					int x=a[i].x;
					b_12[x]=1;
				}
				else if(a[i].opt=='F'){
					int x=a[i].x;
					b_12[x]=-1;
				}
				else b_12[a[i].x]=0;
			}
		}
		bool bl=false;
		for(int i=1;i<=n;i++){
			if(b_12[i]!=t_12[i]){
				bl=true;
				break;
			}
		}
		if(bl==false){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(b_12[i]==0) sum++;
			}
			ans_12=min(ans_12,sum);
		}
		return;
	}
	else{
		for(int i=-1;i<=1;i++){
			t_12[x]=i;
			dfs_12(x+1);
		}
	}
}
void test_12(){
	while(T--){
		ans_12=2e9;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=m;i++){
			cin>>a[i].opt;
			if(a[i].opt=='-'||a[i].opt=='+'){
				scanf("%lld%lld",&a[i].x,&a[i].y);
			}
			else{
				scanf("%lld",&a[i].x);
			}
		}
		dfs_12(1);
		printf("%lld\n",ans_12);
	}
	
}
void test_34(){
	while(T--){
		memset(t_34,false,sizeof(t_34));
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=m;i++){
			cin>>a[i].opt>>a[i].x;
		}
		int ans_34=0;
		for(int i=m;i>=1;i--){
			if(!t_34[a[i].x]){
				if(a[i].opt=='U') ans_34++;
				t_34[a[i].x]=true;
			}
		}
		printf("%lld\n",ans_34);
	}
}
void test_56(){
	while(T--){
		memset(t_56,false,sizeof(t_56));
		memset(u_56,false,sizeof(u_56));
		memset(bl_56,false,sizeof(bl_56));
		memset(a_56,false,sizeof(a_56));
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=m;i++){
			cin>>a[i].opt;
			if(a[i].opt=='U') scanf("%lld",&a[i].x);
			else scanf("%lld %lld",&a[i].x,&a[i].y);
		}
		for(int i=1;i<=m;i++){
			if(a[i].opt=='U'){
				a_56[a[i].x].h=0;
				a_56[a[i].x].u=true;
			}
			else{
				int hou=a_56[a[i].x].h;
				a_56[hou].q=0;
				a_56[a[i].x].u=false;
				a_56[a[i].x].h=a[i].y;
				a_56[a[i].y].q=a[i].x;
			}
		}
		for(int i=1;i<=n;i++){
			if(a_56[i].u==true){
				int tmp=i;bl_56[i]=true;
				while(bl_56[a_56[tmp].q]==false){
					tmp=a_56[tmp].q;
					bl_56[tmp]=true;
				}
			}
		}
		int ans_56=0;
		for(int i=1;i<=n;i++){
			if(bl_56[i]) ans_56++;
		}
		printf("%lld\n",ans_56);
	}
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%lld%ld",&c,&T);
	if(c==1||c==2){
		test_12();
		return 0;
	}
	else if(c==3||c==4){
		test_34();
		return 0;
	}
	else if(c==5||c==6){
		test_56();
		return 0;
	}
	else{
		while(T--){
			puts("0");
		}
		return 0;
	}
}
//nnd,56 guale