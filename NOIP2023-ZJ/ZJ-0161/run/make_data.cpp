#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
mt19937 rd(GetTickCount());
int main(){
	freopen("run.in","w",stdout);
	int c=18;
	printf("%d %d\n",c,1);
	int N=50,M=5,K=rd()%20+1,D=rd()%5+1;
	printf("%d %d %d %d\n",N,M,K,D);
	int Lst=0;
	for(int i=1;i<=M;i++){
		int L=Lst+1,R=Lst+rd()%10+1;
		printf("%d %d %d\n",R,R-L+1,rd()%10+1);
		Lst=R;
	}
	
}