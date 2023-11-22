#include<bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
int n,m,book[100086],ans,a[100086];
char s[100086];
//int fro[100086];
int X[100086],Y[100086];
char read_char(){
	char ch=getchar();
	while(ch!='+'&&ch!='-'&&ch!='T'&&ch!='U'&&ch!='F'){
		ch=getchar();
	}
	return ch;
}
void dfs(int now){
	if(now==n){
		int tot=0;
		for(int i=1;i<=n;i++){
			a[i]=book[i];
			if(!book[i]){
				++tot;
			}
		}
		for(int i=1;i<=m;i++){
			if(s[i]=='+'){
				a[X[i]]=a[Y[i]];
			}
			else if(s[i]=='-'){
				a[X[i]]=-a[Y[i]];
			}
			else if(s[i]=='U'){
				a[X[i]]=0;
			}
			else if(s[i]=='T'){
				a[X[i]]=1;
			}
			else if(s[i]=='F'){
				a[X[i]]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=book[i]){
				return;
			}
		}
		ans=min(ans,tot);
		return;
	}
	for(int i=-1;i<=1;i++){
		book[now+1]=i;
		dfs(now+1);
	}
}
void sub1(){
	ans=INT_MAX;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		book[i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		char ch=read_char();
		s[i]=ch;
		if(ch=='U'||ch=='F'||ch=='T'){
			scanf("%d",&x);
			X[i]=x;
			Y[i]=0;
		}
		else{
			scanf("%d%d",&x,&y);
			X[i]=x;
			Y[i]=y;
		}
	}
	dfs(0);
	printf("%d\n",ans);
}
void sub2(){
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		book[i]=0;
	}
	for(int i=1;i<=m;i++){
		int x;
		char ch=read_char();
		scanf("%d",&x);
		if(ch=='T'||ch=='F'){
			book[x]=0;
		}
		else if(ch=='U'){
			book[x]=1;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=book[i];
	}
	printf("%d\n",ans);
}
void sub3(){
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		book[i]=0;
//		fro[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		char ch=read_char();
		if(ch=='U'){
			scanf("%d",&x);
			book[x]=1;
			X[i]=x;
			Y[i]=0;
		}
		else{
			scanf("%d%d",&x,&y);
			book[x]=book[y];
			X[i]=x;
			Y[i]=y;
//			fro[y]=fro[x];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Y[j]){
				book[X[j]]=book[Y[j]];
			}
			else{
				book[X[j]]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
//		if(fro[i]!=fro[fro[i]]){
//			fro[i]=fro[fro[i]];
//		}
//		if(book[i]||book[fro[i]]){
//			++ans;
//		}
		if(book[i]){
			++ans;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	if(c==1||c==2){
		while(T--){
			sub1();
		}
	}
	else if(c==3||c==4){
		while(T--){
			sub2();
		}
	}
	else if(c==5||c==6){
		while(T--){
			sub3();
		}
	}
	return 0;
}