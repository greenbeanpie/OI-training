#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}

int c,t,n,m,k,d,x[100050],y[100050],v[100050];
long long ans,tmp;

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int i,j;
	c=read();t=read();
	while(t--){
		tmp=0;
		n=read();m=read();k=read();d=read();
		k++;
		for(i=0;i<m;i++){
			x[i]=read();y[i]=read();v[i]=read();
			if(x[i]%k>=y[i])tmp+=v[i];
		}
		tmp-=d*(n-n/k);
		ans=max(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}
