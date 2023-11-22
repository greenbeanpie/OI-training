#include <bits/stdc++.h>
using namespace std;
char str[]="TFU+-";
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int d(const int&l,const int&r){
	return uniform_int_distribution<>(l,r)(rnd);
}
void test(){
	int n=100000,m=100000;
	printf("%d %d\n",n,m);
	for(int i=1; i<=m; ++i){
		const int op=d(0,4);
		putchar(str[op]);
		if(op<3){
			printf(" %d\n",d(1,n));
			continue;
		}
		printf(" %d %d\n",d(1,n),d(1,n));
	}
}
int main(){
	int t=6;
	printf("10 %d\n",t);
	for(; t; test(),--t);
	return 0;
}