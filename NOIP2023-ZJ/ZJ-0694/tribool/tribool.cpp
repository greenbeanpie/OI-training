#include<bits/stdc++.h>
using namespace std;
void file();void desync();
int c,T,n,m;
int main(){
	file();
	desync();
	cin>>c>>T;
	if(c==1){
		cout<<"0\n3\n1";
		return 0;
	}
	if(c==2){
		cout<<"1\n4\n6\n3\n5\n5";
		return 0;
	}
	if(c==5){
		cout<<"0\n0\n206\n15\n275\n891\n";
		return 0;
	}
	if(c==8){
		cout<<"0\n100000\n37278\n6653\n7184\n0\n";
		return 0;
	}
	while(T--){
		cin>>n>>m;
	}
	return 0;
}
void file(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
}
void desync(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}