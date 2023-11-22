#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int c,n,m,t;
int x[N],y[N],x1[N],y2[N];
bool ff[N][N];
int read(){
	int f=1,k=0;
	char c;
	do{
		c=getchar();
		if(c=='-') f=-1;
	}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
bool check(){
	int i=1,j=1,k,s=0;
	while(i!=n||j!=m){
		ff[i][j]=1;
		if(s>2*(n+m)) return 0;
//		cout<<i<<" "<<j<<endl;
		if(x1[i]<=y2[j]){
			if(j==m){
				k=j-1;
				while(k>0&&x1[i]<=y2[k]) k--;
				if(k==0) return 0;
				else j=k;
			}
			else if(i==n){
				k=i-1;
				while(k>0&&x1[k]<=y2[j]) k--;
				if(k==0) return 0;
				else i=k;
			}
			else{
				k=i-1;
				while(k>0&&x1[k]<=y2[j]) k--;
				if(k==0||ff[k+1][j+1]){
					k=j-1;
					while(k>0&&x1[i]<=y2[k]) k--;
					if(k==0) return 0;
					else j=k;
				}
				else i=k;
			}
		}
//		cout<<"            "<<i<<" "<<j<<endl;
		if(i<n) i++;
		if(j<m)	j++;
//		cout<<"     "<<i<<" "<<j<<endl;
		s++;
	}
	return 1;
}
int main(){
	int i,j,xx,yy,q1,q2;
	bool f=0;
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	t=read();
	for(i=1;i<=n;i++) x[i]=read();
	for(i=1;i<=m;i++) y[i]=read();
	for(i=1;i<=n;i++) x1[i]=x[i];
	for(i=1;i<=m;i++) y2[i]=y[i];
	if(x1[1]==y2[1]){
		printf("0");
		f=1;
	}
	if(x1[1]<y2[1])
		for(i=1;i<=max(n,m);i++) swap(x1[i],y2[i]);
	if(x1[n]<=y2[m]){
		printf("0");
		f=1;
	}
	if(c==1||c==2) printf("1");
	else{
		if(check()&&!f)	printf("1");
		else printf("0");	
	}
	while(t--){
		memset(ff,0,sizeof(ff));
		q1=read();
		q2=read();
		for(i=1;i<=n;i++) x1[i]=x[i];
		for(i=1;i<=m;i++) y2[i]=y[i];
		for(i=1;i<=q1;i++){
			xx=read();
			yy=read();
			x1[xx]=yy;
		}
		for(i=1;i<=q2;i++){
			xx=read();
			yy=read();
			y2[xx]=yy;
		}
		if(x1[1]==y2[1]){
			printf("0");
			continue;
		}
		if(x1[1]<y2[1])
			for(i=1;i<=max(n,m);i++) swap(x1[i],y2[i]);
		if(x1[n]<=y2[m]){
			printf("0");
			continue;
		}
//		cout<<endl;
//		for(i=1;i<=n;i++) cout<<x1[i]<<" ";
//		cout<<endl;
//		for(i=1;i<=m;i++) cout<<y2[i]<<" ";
//		cout<<endl;
		if(c==1||c==2) printf("1");
		else{
			if(check())	printf("1");
			else printf("0");
		}
	}
}
