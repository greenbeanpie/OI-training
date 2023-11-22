#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int d(const int&l,const int&r){
	return uniform_int_distribution<>(l,r)(rnd);
}
void test(){
	int n=d(1,1000000000);
	if(!d(0,10))
		n=d(1,20);
	int m=d(1,1000);
	if(!d(0,10))
		m=d(1,20);
	int k=d(1,n);
	int x=d(1,1000000000);
	if(d(0,2))
		x=d(1,1000000000/k);
	printf("%d %d %d %d\n",n,m,k,x);
	for(int i=1; i<=m; ++i){
		int r=d(1,n);
		int l=d(1,r);
		if(r-l+1>k&&d(0,100))
			l=d(r-k+1,r);
		int v=d(1,1000000000);
		printf("%d %d %d\n",r,r-l+1,v);
	}
}
int main(){
	int t=10;
	for(printf("25 %d\n",t); t; test(),--t);
	return 0;
}