#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ x=x*10+(c-48);c=getchar();}
	return x*f;
}

const int maxn=5e5+10;

int num,n,m,q;
int a[maxn],b[maxn],ans[maxn],pre1[maxn],pre2[maxn];

bool ck(){
	int op=0;
	if(a[1]>b[1]) op=1;
	if(a[1]==b[1]) return false;
	if(op==0){
		if(a[2]>=b[2]) return false;
		return true; 
	}
	if(op==1){
		if(a[2]<=b[2]) return false;
		return true;
	}
	return true;
}

bool check(){
	int op=0;
	if(a[1]>b[1]) op=1;
	if(a[1]==b[1]) return false;
	int j=1;
	for(int i=2;i<=n;i++){
		if(op==0){
			int f=1;
			while(a[i]>=b[j]&&j<=m){
				if(a[i-1]>=b[j]){f=0;break; }
				j++;	
			}	
			if(!f||j>m) return false;
		}
		else{
			int f=1;
			while(a[i]<=b[j]&&j<=m){
				if(a[i-1]<=b[j]){f=0;break; }
				j++;	
			}	
			if(!f||j>m) return false;
		}
	}
	return true;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	num=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=pre1[i]=read();
	for(int i=1;i<=m;i++) b[i]=pre2[i]=read();
	if(num>2){
		if(check()) ans[1]=1;	
	}
	else if(num==1){
		if(a[1]==b[1]) ans[1]=0;
		else ans[1]=1;
	}
	else if(num==2){
		if(ck()) ans[1]=1;
	}
	for(int i=1;i<=q;i++){
		int ki=read(),kj=read();
		for(int j=1;j<=n;j++) a[j]=pre1[j];
		for(int j=1;j<=m;j++) b[j]=pre2[j];
		for(int j=1;j<=ki;j++){
			int x=read();
			a[x]=read();
		}
		for(int j=1;j<=kj;j++){
			int x=read();
			b[x]=read();
		}
		if(num>2){
			if(check()) ans[i+1]=1;
		}
		if(num==2) if(ck()) ans[i+1]=1;
		if(num==1) if(a[1]!=b[1]) ans[i+1]=1;
	}
	for(int i=1;i<=1+q;i++){
		printf("%d",ans[i]);
	}
	return 0;
}