#include <bits/stdc++.h>
using namespace std;
int n,m;
char ch[5005][5];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch[i]+1;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n<=26&&m==1){
		char c='z';
		for(int i=1;i<=n;i++){
			if(ch[i][1]<c) c=ch[i][1];
		}
		//cout<<c;
		for(int i=1;i<=n;i++){
			//cout<<ch[i][1];
			if(ch[i][1]==c) cout<<1;
			else cout<<0;	
		}
		return 0;
	}
	if(n<=15&&m==2){
		char c[5]="zzzz";
		for(int i=1;i<=n;i++){
			if(ch[i][1]<c[1] || (ch[i][1]==c[1]&&ch[i][2]<c[2]) ){
				c[1]=ch[i][1];
				c[2]=ch[i][2];
			}
		}
		//cout<<c[1]<<c[2];
		for(int i=1;i<=n;i++){
			if(ch[i][1]==c[1]&&ch[i][2]==c[2]) cout<<1;
			else if(ch[i][2]<c[1]) cout<<1;
			else cout<<0;
		}
		return 0;
	}

//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<ch[i][j];
//		}
//		cout<<endl;
//	}
	return 0;
}
/*
15 2
zx
qn
wn
nd
pl
pd
vm
ff
mh
ql
yv
md
ji
oc
fa

000101000001011
*/
