#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int d(const int&l,const int&r){
	return uniform_int_distribution<>(l,r)(rnd);
}
int main(){
	int max_v=1000000000,sum=250000;
	if(!d(0,2))
		max_v=d(1,20);
	if(!d(0,2))
		sum=d(1,200);
	int n=d(1,2000);
	if(!d(0,2))
		n=d(1,20);
	int m=d(1,2000);
	if(!d(0,2))
		m=d(1,20);
	int q=d(0,60);
	printf("20 %d %d %d\n",n,m,q);
	int r=d(1,d(1,max_v));
	int l=d(d(1,max_v),max_v);
	if(d(0,1)){
		for(int i=1; i<n; ++i)
			printf("%d ",d(1,r));
		printf("%d\n",d(1,r));
		for(int i=1; i<m; ++i)
			printf("%d ",d(l,max_v));
		printf("%d\n",d(l,max_v));
	}
	else{
		for(int i=1; i<n; ++i)
			printf("%d ",d(l,max_v));
		printf("%d\n",d(l,max_v));
		for(int i=1; i<m; ++i)
			printf("%d ",d(1,r));
		printf("%d\n",d(1,r));
	}
	for(int i=1; i<=q; ++i){
		int kx=min(d(0,sum/q+1),n),ky=min(d(0,sum/q+1),m);
		printf("%d %d\n",kx,ky);
		for(; kx; --kx)
			printf("%d %d\n",d(1,n),d(1,max_v));
		for(; ky; --ky)
			printf("%d %d\n",d(1,n),d(1,max_v));
	}
	return 0;
}