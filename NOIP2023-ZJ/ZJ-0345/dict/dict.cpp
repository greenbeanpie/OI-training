#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005][30];
int read(){
	int ret=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(!isalpha(ch)) ch=getchar();
		while(isalpha(ch)) a[i][ch-97]++,ch=getchar();
	}
	for(int i=1;i<=n;i++){
		bool flg=1;
		for(int j=1;j<=n;j++) if(j!=i){
			int I=0,J=25;
			// while(I<25&&J>0){
				while(!a[i][I]) I++;
				while(!a[j][J]) J--;
				if(I>=J){flg=0;break;}
			// }
		}
		if(flg) putchar('1');else putchar('0');
	}
//	printf("\n%lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
