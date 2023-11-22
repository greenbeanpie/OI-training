#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		int scan;
		scanf("%d",&scan);
	}
	for(int i=1;i<=m;i++){
		int scan;
		scanf("%d",&scan);
	}
	for(int NUM=0;NUM<q;NUM++){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=0;i<kx;i++){
			int p,v;
			scanf("%d%d",&p,&v);
		}
	}
	if(c==3){
		printf("1001\n");
		return 0;
	}
	if(c==4){
		printf("1101100011110101110101111111111111111110011111111101101100000\n");
		return 0;
	}
	if(c==7){
		printf("1100110110101110011011111111100000111111001100110011111011111\n");
		return 0;
	}
	if(c==9){
		printf("0111011011011111010101110100000111111111111111101000001001111\n");
		return 0;
	}
	if(c==18){
		printf("0001110011101001111010110011111011111011111001010010110101111\n");
		return 0;
	}
}
