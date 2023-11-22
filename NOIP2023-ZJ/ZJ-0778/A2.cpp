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
int n,m;
char s[3005][3005],p[3005],q[3005];

int cmp(){//check if p is smaller than q
	rep(i,1,m){
		if(p[i] == q[i]) continue;
		return p[i] < q[i];
	}
	return 0;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.ans","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",s[i] + 1);

	rep(i,1,n){
		rep(j,1,m) p[j] = s[i][j];
		sort(p + 1,p + m + 1);

		int flg = 1;
		rep(k,1,n){
			if(i == k) continue;
			rep(j,1,m) q[j] = s[k][j];
			sort(q + 1,q + m + 1);reverse(q + 1,q + m + 1);
			if(!cmp()){
				flg = 0;
				break;
			}
		}
		printf("%d",flg);
	}
	printf("\n");
	return 0;
}
//g++ A2.cpp -o A2 -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result