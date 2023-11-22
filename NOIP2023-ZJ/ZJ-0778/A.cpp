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
int n,m,cnt;
int buc[3005][35];
char s[3005],Mn[3005],se[3005];
int idx;

int cmp(char *p,char *q){//check if p is larger than q
	rep(i,1,m){
		if(p[i] == q[i]) continue;
		return p[i] > q[i];
	}
	return 0;
}

int main(){	
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	idx = -1;
	Mn[1] = 124;
	se[1] = 124;
	rep(i,1,n){
		scanf("%s",s + 1);
		rep(j,1,m) buc[i][s[j] - 'a']++;

		cnt = 0;
		per(c,25,0){
			rep(k,1,buc[i][c]) s[++cnt] = c + 'a';
		}

		if(cmp(Mn,s)){
			rep(j,1,m){
				se[j] = Mn[j];
				Mn[j] = s[j];
			}
			idx = i;
		}else if(cmp(se,s)){
			rep(j,1,m) se[j] = s[j];
		}
	}
//	printf("idx=%d\n",idx);
//	rep(i,1,m) printf("%c",Mn[i]);
//	printf("\n");
//	rep(i,1,m) printf("%c",se[i]);
//	printf("\n");

	rep(i,1,n){
		cnt = 0;
		rep(c,0,25){
			rep(k,1,buc[i][c]) s[++cnt] = c + 'a';
		}

		if(i != idx) printf("%d",cmp(Mn,s));
		else printf("%d",cmp(se,s));
	}
	printf("\n");
	return 0;
}
//g++ A.cpp -o A -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result -fsanitize=address,undefined