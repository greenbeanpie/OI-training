#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='+')return 1;
		if(ch=='-')return -1;
		if(ch=='T')return 2;
		if(ch=='F')return -2;
		if(ch=='U')return 0;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}

int c,t,n,m,x[100050],v[100050],a[100050],b[100050];
bool z[100050];

int unknown(){
	int i,ans=0;
	for(i=0;i<m;i++){
		if(!z[a[i]]&&(v[i]==2||v[i]==-2||v[i]==0)){
			x[a[i]]=v[i];
			z[a[i]]=1;
			if(v[i]==0)ans++;
		}
	}
	for(i=0;i<m;i++){
		if(!z[a[i]]&&(v[i]==1||v[i]==-1)){
			if(v[i]*x[b[i]]!=2){
				x[a[i]]=0;
				ans++;
				z[a[i]]=1;
			}
		}
	}
	return ans;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i;
	c=read();t=read();
	while(t--){
		n=read();m=read();
		memset(z,0,sizeof(z));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)x[i]=2;
		for(i=m-1;i>=0;i--){
			v[i]=read();
			if(v[i]==1||v[i]==-1){
				a[i]=read();b[i]=read();
			}else{
				a[i]=read();
			}
		}
		printf("%d\n",unknown());
	}
	return 0;
}
