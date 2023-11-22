#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (j);i <= (k);i++)
#define per(i,j,k) for(int i = (j);i >= (k);i--)
#define ll long long
#define pii pair<int,int>
#define SZ(S) (int)S.size()
#define mkp make_pair
#define uint unsigned int
using namespace std;

template <class P>
void chkmax(P &x,P y){
	if(x < y) x = y;
}

template <class Q>
void chkmin(Q &x,Q y){
	if(x > y) x = y;
}
int c1,c2;
char str[2][3005];
ll ans[2][2333333];

void checkA(){
	system("./Agen");
	system("./A");
	system("./A2");
	freopen("dict.out","r",stdin);
	scanf("%s",str[0] + 1);
	freopen("dict.ans","r",stdin);
	scanf("%s",str[1] + 1);
	c1 = strlen(str[0] + 1);
	c2 = strlen(str[1] + 1);
	assert(c1 == c2);
	rep(k,1,c1) assert(str[0][k] == str[1][k]);
}

void checkB(){
	c1 = c2 = 0;
	system("./Bgen");
	system("./B");
	system("./B2");
	freopen("tribool.out","r",stdin);
	while(scanf("%lld",&ans[0][++c1]) == 1);
	freopen("tribool.ans","r",stdin);
	while(scanf("%lld",&ans[1][++c2]) == 1);
	assert(c1 == c2);
	rep(k,1,c1) assert(ans[0][k] == ans[1][k]);
}
int ssum = 0;

void checkC(){
	system("./Cgen");
	system("./C");
	system("./C2");
	freopen("expand.out","r",stdin);
	scanf("%s",str[0] + 1);
	freopen("expand.ans","r",stdin);
	scanf("%s",str[1] + 1);
	c1 = strlen(str[0] + 1);
	c2 = strlen(str[1] + 1);
	assert(c1 == c2);
	rep(k,1,c1){
		assert(str[0][k] == str[1][k]);	
		ssum += str[0][k] - '0';
	}
}

void checkD(){
	c1 = c2 = 0;
	system("./Dgen");
	system("./D");
	system("./D2");
	freopen("run.out","r",stdin);
	while(scanf("%lld",&ans[0][++c1]) == 1);
	freopen("run.ans","r",stdin);
	while(scanf("%lld",&ans[1][++c2]) == 1);
	assert(c1 == c2);
	rep(k,1,c1) assert(ans[0][k] == ans[1][k]);
}

int main(){
	rep(p,1,10000){
		checkA();
		checkB();
		checkC();
		checkD();
		cerr << p << " ";
	}
//	rep(p,1,100) checkC();
	cerr << ssum << endl;
	return 0;
}
//g++ Com.cpp -o Com -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result