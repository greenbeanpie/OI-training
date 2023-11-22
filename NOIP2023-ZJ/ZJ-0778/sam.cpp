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
int n;
char s[1000005];

int cnt,last;
int I[1000005];
struct node{
	int ch[26],len,link;
}T[2000005];

int insert(int c){
	int u = ++cnt,p = last;
	T[u].len = T[p].len + 1;
	while(p != -1 && !T[p].ch[c]){
		T[p].ch[c] = u;
		p = T[p].link;
	}
	if(p == -1) return last = u;

	int q = T[p].ch[c];
	if(T[q].len == T[p].len + 1){
		T[u].link = q;
		return last = u;
	}
	int clone = ++cnt;
	T[clone] = T[q];
	T[q].link = T[u].link = clone;
	T[clone].len = T[p].len + 1;
	while(p != -1 && T[p].ch[c] == q){
		T[p].ch[c] = clone;
		p = T[p].link;
	}
	return last = u;
}

int main(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	T[0].link = -1;
	rep(i,1,n) I[i] = insert(s[i] - 'a');
	rep(u,0,cnt){
		printf("node %d len %d link %d\n",u,T[u].len,T[u].link);
		rep(c,0,25) if(T[u].ch[c]) printf("%c->%d\n",c + 'a',T[u].ch[c]);
	}
	return 0;
}
//g++ sam.cpp -o sam -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result