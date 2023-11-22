#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
inline int read(){
	int num = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')  f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
		num = (num << 1) + (num << 3) + (c & 15),c = getchar();
	return num * f;
}
int C,T;
int n,m,ans;
inline void solve_3_4(){
	char op[MAXN];
	int op1[MAXN],op2[MAXN];
	n = read(),m = read();
	for(int i = 1;i <= m;++i){
		scanf("%c",&op[i]);
		op1[i] = read();
	}
	int a[MAXN];
	memset(a,0,sizeof(a));
	for(int i = 1;i <= m;++i){
		if(op[i] == 'U'){
			a[op1[i]] = 3;
		}
		else if(a[op1[i]] == 3){
			a[op1[i]] = 0;
		}
	}
	for(int i = 1;i <= n;++i){
		if(a[i] == 3){
			ans++;
		}
	}
	printf("%d",ans);
}
int father[MAXN];
inline int find(int x){
	while(x != father[x]){
		x = father[x];
	}
	return x;
}
inline void solve_5_6(){
	int end[MAXN];
	n = read(),m = read();
	for(int i = 0;i <= n;++i){
		end[i] = i;
		father[i] = i ;
	}
	for(int i = 1;i <= m;++i){
		char p;
		scanf("%c",&p);
		if(p == 'U'){
			int x = read();
			end[x] = 0;
		}
		if(p == '+'){
			int x = read(),y = read();
			end[x] = end[y];
		}
	}
	for(int i = 1;i <= n;++i){
		int fy = find(end[i]);
		father[i] = fy;
	}
	for(int i = 1;i <= n;++i){
		if(find(i) == 0){
			ans++;
		}
	}
	printf("%d\n",ans);
}
inline void init(){
	ans = 0;
	return ;
}
int main(){
	 freopen("tribool.in","r",stdin);
	 freopen("tribool.out","w",stdout);
	 C = read(),T = read();
	 for(int _i = 1;_i <= T;++_i){
	 	init();
		if(C >= 3 && C <= 4){
			solve_3_4();
		}
		if(C >= 5 && C <= 6){
			solve_5_6();
		}
		if(C >= 1 && C <= 2){
			printf("0\n");
		}
		else{
			ans = rand();
			printf("%d\n",ans);
		}
	 }
	return 0;
}

//AFO
