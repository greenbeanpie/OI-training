#include <bits/stdc++.h>
using namespace std;
int main(){
	system("cp ../run run");
	for(int t=1; ; ++t){
		fprintf(stderr,"Case %d:\n",t);
		system("./gen>run.in");
		fprintf(stderr,"running std\n");
		if(system("time -p ./brute_force<run.in>run.ans")){
			fprintf(stderr,"std runtime error\n");
			break;
		}
		fprintf(stderr,"running program\n");
		if(system("time -p ./run")){
			fprintf(stderr,"Runtime ERROR\n");
			break;
		}
		if(system("diff -b -B run.out run.ans"))
			break;
	}
	return 0;
}