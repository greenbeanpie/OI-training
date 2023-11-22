#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	char c[3003];
}z[3003];
int n,m,t[2],e,i,j;
char p[2][3003];
bool cmp(char A,char B){return A!=B?A<B:false;}
void work(int x,int s){
	for(int i=0;i<m;i++)  p[s][i]=z[x].c[m-1-i];
	t[s]=x;
}
bool check(int x,int s){
	for(int i=0;i<m;i++)
		if(z[x].c[m-1-i]!=p[s][i])  return z[x].c[m-1-i]<p[s][i];
	return false;
}
bool CHECK(int x,int s){
	for(int i=0;i<m;i++)
		if(z[x].c[i]!=p[s][i])  return z[x].c[i]<p[s][i];
	return false;
}
int main(){
	freopen("dict.in","r",stdin),freopen("dict.out","w",stdout);
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
		scanf("%s",z[i].c),sort(z[i].c,z[i].c+m,cmp);
		if(t[0]==0)  work(i,0);
		else if(check(i,0)){
			for(j=0;j<m;j++)  p[1][j]=p[0][j];
			work(i,0);
		}else if(t[1]==0)  work(i,1);
		else if(check(i,1))  work(i,1);
	}
	if(n==1)  return printf("1"),0;
	for(i=1;i<=n;i++){
		if(i==t[0]){
			if(CHECK(i,1))  printf("1");
			else  printf("0");
		}else{
			if(CHECK(i,0))  printf("1");
			else  printf("0");
		}
	}
	return 0;
}
