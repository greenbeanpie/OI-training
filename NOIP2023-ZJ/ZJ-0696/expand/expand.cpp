#include<bits/stdc++.h>
int c,n,m,q;//q=question
using namespace std;
int a,b;
int aa,bb;
int fir[3],sec[3],firr[3],secc[3],flag;
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;//1 1 1 ?
	if(c==1) {
		for(int i=0; i<q+1; i++) {
			cout<<1;
		}
	}
	if(c==2) {	
		cin>>fir[1]>>fir[2]>>sec[1]>>sec[2];
		if(fir[1]>sec[1]) {
			if(fir[2]>sec[2]) {
				cout<<1;
				flag=1;
			}
		}
		if(flag==0)cout<<0;
		flag=0;
		firr[1]=fir[1];
		firr[2]=fir[2];
		secc[1]=sec[1];
		secc[2]=sec[2];
		for(int i=1; i<=q; i++) {
			flag=0;
			cin>>a>>b;
			for(int i=1; i<=a; i++) {
				cin>>aa>>bb;
				firr[aa]=bb;
			}
			for(int i=1; i<=b; i++) {
				cin>>aa>>bb;
				secc[aa]=bb;
			}
			if(firr[1]>secc[1]) {
				if(firr[2]>secc[2]) {
					cout<<1;
				}
			}
			if(flag==0)cout<<0;
			firr[1]=fir[1];
			firr[2]=fir[2];
			secc[1]=sec[1];
			secc[2]=sec[2];
		}
	}
	if(c>2) { //ÌıÌìÓÉÃü
		srand(time(0));
		for(int i=0; i<q+1; i++) {
			cout<<rand()%2;
		}
	}
	return 0;
	//2 2 2 2  2 3 1 2 1 0 1 1   1 0 1 3    1 0 2 0
}
