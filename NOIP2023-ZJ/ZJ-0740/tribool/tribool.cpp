#include<bits/stdc++.h>
using namespace std;
int c,t,ans=0,mans=10000;
int n,m;
char a[100010],b[20],r[20],u[3]={'T','F','U'};
char p[20];
int p1[20][2];
char change(char c){
	if(c=='U')return 'U';
	if(c=='T')return 'F';
	if(c=='F')return 'T';
}
void check1(){
	ans=0;
	for(int i=1;i<=m;i++){
		if(p[i]=='+')
			a[p1[i][0]]=a[p1[i][1]];
		if(p[i]=='-')
			a[p1[i][0]]=change(a[p1[i][1]]);
		if(p[i]=='T'||p[i]=='F'||p[i]=='U')
			a[p1[i][0]]=p[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]=='U')ans++;
		if(a[i]!=b[i])return;
	}
	mans=min(mans,ans);
	return;
}
void make(int d){
	if(d==n+1){
		for(int i=1;i<=n;i++){
			a[i]=r[i];
		}
		check1();
		return;
	}
	for(int i=0;i<3;i++){
		b[d]=u[i];
		r[d]=u[i];
		a[d]=u[i];
		make(d+1);
		a[d]=0;
		b[d]=0;
		r[d]=0;
	}
	return;
}
void check(){
	ans=0;
	cin>>n>>m;
	mans=n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(r,0,sizeof(r));
	for(int i=1;i<=m;i++){
		cin>>p[i];
		if(p[i]=='-'||p[i]=='+'){
			cin>>p1[i][0]>>p1[i][1];
		}
		else
			cin>>p1[i][0];
	}
	make(1);
	cout<<mans<<endl;
	return;
}
void check2(){
	cin>>n>>m;
	int sum=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(r,0,sizeof(r));
	for(int i=1;i<=m;i++){
		char e;
		cin>>e;
		int w;
		cin>>w;
		a[w]=e;
	}
	for(int i=1;i<=n;i++)
		if(a[i]=='U')sum++;
	cout<<sum<<endl;
	return;
}
struct pa{
	int i,j;
};
void check3(){
	cin>>n>>m;
	int sum=0;
	memset(a,0,sizeof(a));
	queue<pa>Q;
	for(int i=1;i<=m;i++){
		char e;
		cin>>e;
		if(e=='U'){
			int w;
			cin>>w;
			a[w]='U';
		}
		if(e=='+'){
			pa ty;
			scanf("%d%d",&ty.i,&ty.j);
			if(a[ty.j]=='U'){
				a[ty.i]='U';
			}
			else
				Q.push(ty);
		}
	}
	while(!Q.empty()){
		pa k=Q.front();
		Q.pop();
		if(a[k.j]=='U'){
			a[k.i]='U';
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]=='U')sum++;
	cout<<sum<<endl;
	return;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c<=2)
		while(t--)
			check();
	if(c>=3&&c<=4){
		while(t--)
			check2();
	}
	if(c>=5&&c<=6){
		while(t--)
			check3();
	}
	return 0;
}
