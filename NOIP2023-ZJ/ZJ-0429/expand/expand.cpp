#include<bits/stdc++.h>
using namespace std;
const int Maxn=100090;
int read(){
	int num=0,op=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return op*num;
}
int a[Maxn],b[Maxn],pos[Maxn];
int main(){
	int c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	if(n==1){
		for(int i=1;i<=q+1;i++) cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]>b[j]){
				pos[i]=j;
			}
		}
	}
}
