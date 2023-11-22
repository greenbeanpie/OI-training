#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,c,n,m;
int xl1[N],xl1y[N],ans1;
int xl2[N],ans2;
int xl3[N],ans3,mark3[N];
struct node{
	int op,a,b;
}w[N];
void check(){
	for(int i=1;i<=n;i++)xl1[i]=xl1y[i];
	for(int i=1;i<=m;i++){
		if(w[i].op<=3)xl1[w[i].a]=w[i].op;
		else if(w[i].op==4){
			int a=w[i].a,b=w[i].b;
			xl1[a]=xl1[b];
		}
		else if(w[i].op==5){
			int a=w[i].a,b=w[i].b;
			if(xl1[b]==1)xl1[a]=1;
			else if(xl1[b]==2)xl1[a]=3;
			else if(xl1[b]==3)xl1[a]=2;
		}
	}
	int f=1;
	for(int i=1;i<=n;i++){
		if(xl1[i]!=xl1y[i]){
			f=0;break;
		}
	}
	if(f==1){
		int num=0;
		for(int i=1;i<=n;i++)if(xl1y[i]==1)num++;
		ans1=min(ans1,num);
	}
}
void dfs(int x){
	if(x==n){
		check();return;
	}
	x++;
	for(int i=1;i<=3;i++){
		xl1y[x]=i;
		dfs(x);
		xl1y[x]=0;
	}
	return;
}
void solve1(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)xl1[i]=xl1y[i]=0;
	ans1=1e9;
	for(int i=1;i<=m;i++){
		char s[10];
		scanf("%s",s+1);
		if(s[1]=='U')w[i].op=1;
		if(s[1]=='T')w[i].op=2;
		if(s[1]=='F')w[i].op=3;
		if(s[1]=='+')w[i].op=4;
		if(s[1]=='-')w[i].op=5;
		if(w[i].op>=4)scanf("%d%d",&w[i].a,&w[i].b);
		else scanf("%d",&w[i].a);
	}
	dfs(0);
	printf("%d\n",ans1);
}
void solve2(){
	scanf("%d%d",&n,&m);
	ans2=0;
	for(int i=0;i<=n;i++)xl2[i]=0;
	for(int i=1;i<=m;i++){
		char s[10];
		scanf("%s",s+1);
		if(s[1]=='U')w[i].op=1;
		if(s[1]=='T')w[i].op=2;
		if(s[1]=='F')w[i].op=3;
		scanf("%d",&w[i].a);
	}
	for(int i=1;i<=m;i++){
		xl2[w[i].a]=w[i].op;
	}
	for(int i=1;i<=n;i++)if(xl2[i]==1)ans2++;
	printf("%d\n",ans2);
	return;
}
void dfs3(int x){
	if(xl3[x]>=0)return;
	if(mark3[x]==1){
		xl3[x]=0;return;
	}
	mark3[x]=1;
	dfs3(-xl3[x]);
	xl3[x]=xl3[-xl3[x]];
	return;
}
void solve3(){
	scanf("%d%d",&n,&m);
	ans3=0;
	for(int i=0;i<=n;i++)xl3[i]=mark3[i]=0;
	for(int i=1;i<=m;i++){
		char s[10];
		scanf("%s",s+1);
		if(s[1]=='U')w[i].op=1;
		if(s[1]=='+')w[i].op=4;
		if(w[i].op>=4)scanf("%d%d",&w[i].a,&w[i].b);
		else scanf("%d",&w[i].a);
	}
	for(int i=1;i<=m;i++){
		if(w[i].op==1)xl3[w[i].a]=1;
		else{
			if(xl3[w[i].b]==1)xl3[w[i].a]=1;
			else if(xl3[w[i].b]==0)xl3[w[i].a]=-w[i].b;
			else if(xl3[w[i].b]<0)xl3[w[i].a]=xl3[w[i].b];
		}
	}
	for(int i=1;i<=n;i++){
		if(xl3[i]<0)dfs3(i);
	}
	for(int i=1;i<=n;i++)if(xl3[i]==1)ans3++;
	printf("%d\n",ans3);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&t,&c);
	if(t<=2||t>6){
		while(c--)solve1();
	}
	else if(t<=4){
		while(c--)solve2();
	}
	else if(t<=6){
		while(c--)solve3();
	}
	return 0;
}