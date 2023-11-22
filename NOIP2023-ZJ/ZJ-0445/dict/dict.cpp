#include <bits/stdc++.h>
using namespace std;
int n , m , mx[3010] , mi[3010];
char c[3010];
bool fg;
int rd(){
	int ta = 0 , tk = 1;
	char tb = getchar();
	while(tb > '9' || tb < '0'){
		if(tb == '-'){
			tk = -1;
		}
		tb = getchar();
	}
	while(tb <= '9' && tb >= '0'){
		ta = (ta << 1) + (ta << 3) + tb - 48;
		tb = getchar();
	}
	return ta * tk;
}
int main(){
	freopen("dict.in" , "r" , stdin);
	freopen("dict.out" , "w" , stdout);
	memset(mi , 0x3f , sizeof(mi));
	n = rd() , m = rd();
	for(int i = 1;i <= n;i++){
		scanf("%s" , c + 1);
		for(int j = 1;j <= m;j++){
			mx[i] = max(mx[i] , c[j] - 'a' + 1);
			mi[i] = min(mi[i] , c[j] - 'a' + 1);
		}
	}
	for(int i = 1;i <= n;i++){
		fg = true;
		for(int j = 1;j <= n;j++){
			if(i != j){
				if(mi[i] >= mx[j]){
					fg = false;
				}
			}
		}
		if(fg){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	return 0;
}