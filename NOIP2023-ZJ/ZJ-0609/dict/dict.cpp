#include<bits/stdc++.h>
#define MAXN 3010
#define INF 0x3f3f3f3f
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
int n,m;
int w[MAXN][MAXN];
void solve_1(){
	printf("1");
	return;
}
void solve_2_4(){
	int flag,Min = INF;
	for(int i = 1;i <= n;++i){
		flag = Min > w[i][1] ? i : flag;
		Min = min(Min,w[i][1]);
	}
	for(int i = 1;i <= n;++i){
		if(i == flag){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	return;
}
void solve_5_7(){
	int w_max[20][5],w_min[20][5];
	for(int i = 1;i <= n;++i){
		if(w[i][1] < w[i][2]){
			w_min[i][1] = w[i][1],w_min[i][2] = w[i][2];
			w_max[i][1] = w[i][2],w_max[i][2] = w[i][1];
		}
		else{
			w_min[i][1] = w[i][2],w_min[i][2] = w[i][1];
			w_max[i][1] = w[i][1],w_max[i][2] = w[i][2];
		}
	}
	for(int i = 1;i <= n;++i){
		int flag = 1;
		for(int j = 1;j <= n;++j){
			if(i == j){
				continue;
			}
			if(w_min[i][1] == w_max[j][1]){
				if(w_min[i][2] >= w_max[j][2]){
					flag = 0;
					break;
				}
			}
			else if(w_min[i][1] > w_max[j][1]){
				flag = 0; 
				break;
			}
		}
		printf("%d",flag);
	}
	return;
}
inline bool cmp(int x,int y){
	return x < y;
}
inline void solve_8(){
	for(int i = 1;i <= n;++i){
		sort(w[i],w[i] + m,cmp);
	}
	for(int i = 1;i <= n;i++){
		int flag = 1;
		int l = 1,r = m;
		for(int j = 1;j <= n;j++){
			if(i == j)  continue;
			if(w[i][l] > w[j][r]){
				flag = 0;
				break;
			}
			if(w[i][l] == w[j][r]){
				l++,r--;
				j--;
			}
		}
		l = 1,r = m;
		printf("%d",flag);
	}
}
int main(){
	 freopen("dict4.in","r",stdin);
	 freopen("dict.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			char p;
			scanf("%c ",&p);
			w[i][j] = p - 'a' + 1;
		}
	}
	if(n == 1){
		solve_1();
		return 0;
	}	if(m == 1){
		solve_2_4();
		return 0;
	}
	if(m == 2){
		solve_5_7();
		return 0;
	}
	else{
		solve_8();
		return 0;
	}
	return 0;
}

//AFO

