#include <bits/stdc++.h>
using namespace std;
int main(){
	for(int t=1; ; ++t){
		fprintf(stderr,"Case %d:\n",t);
		system("./gen>tribool.in");
		fprintf(stderr,"running program\n");
		if(system("time -p ./tribool")){
			fprintf(stderr,"runtime ERROR\n");
			break;
		}
	}
	return 0;
}