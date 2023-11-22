#include <bits/stdc++.h>
using namespace std;
int main(){
	system("cp ../expand expand");
	for(int t=1; ; ++t){
		fprintf(stderr,"Case %d:\n",t);
		system("./gen>expand.in");
		fprintf(stderr,"running std\n");
		if(system("time -p ./brute_force<expand.in>expand.ans")){
			fprintf(stderr,"std runtime error\n");
			break;
		}
		fprintf(stderr,"running program\n");
		if(system("time -p ./expand")){
			fprintf(stderr,"runtime ERROR\n");
			break;
		}
		if(system("diff -b -B expand.out expand.ans"))
			break;
	}
	return 0;
}