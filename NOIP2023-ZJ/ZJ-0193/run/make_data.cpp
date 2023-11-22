#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
	return (rand()<<15)+(rand()<<1)+(rand()<<1);
}
int main(){
	freopen("run.in","w",stdout);
	srand(GetTickCount());
	puts("1 10");
	for(int i=1;i<=10;i++){
		printf("%d %d %d %d\n",18,100,18,brand()%10+1);
		int n=18,m=100;
		for(int i=1;i<=m;i++){
			int l=brand()%n+1,r=brand()%(n-l)+l;
			printf("%d %d %d\n",r,(r-l+1),brand()%10+1);
		}
	}
	return 0;
}