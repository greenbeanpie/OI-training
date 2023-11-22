#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
	return (rand()<<15)+(rand()<<1)+(rand()<<1);
}
int main(){
	freopen("tribool.in","w",stdout);
	srand(GetTickCount());
	puts("6 6");
	for(int i=1;i<=10;i++){
		printf("%d %d\n",100000,100000);
		int n=100000,m=100000;
		for(int i=1;i<=m;i++){
			int op=brand()%100;
			if(op==0){
				int x=brand()%n+1;
				printf("U %d\n",x);
			}else{
				int x=brand()%n+1,y=brand()%n+1;
				printf("+ %d %d\n",x,y);
			}
		}
	}
	return 0;
}