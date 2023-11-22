#include<bits/stdc++.h>
int ceshi,shuliang,fst,snd,ans,coushude,a[114514];
char zifu;
using namespace std;
int main() {
	cin>>ceshi>>shuliang;
	//3 3 3 3 T 2 T 1 t 3 U 2 U 3 U 1 T 2 U 2 T 2
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	srand(time(0));
	cin>>fst>>snd;
	for(int i=0; i<shuliang; i++) {
		cout<<rand()%fst+1;
	}


	return 0;
}
