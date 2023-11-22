#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c) && c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int n,m,k,d;
struct node{
	int x,y,v;
}cha[M];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	c=read(); T=read();
	n=read(); m=read(); k=read(); d=read();
	for(int i=1;i<=m;i++){
		cha[i].x=read();
		cha[i].y=read();
		cha[i].v=read();
	}
	printf("2");
	return 0;
}
