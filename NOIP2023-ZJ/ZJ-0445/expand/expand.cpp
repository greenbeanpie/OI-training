#include <bits/stdc++.h>
using namespace std;
int c , l[2] , q , mi , mx , d , x , nwd , nwx , t1 , t2 , t3 , t4 , a[2][500010] , ga1[500010] , ga2[500010] , gb1[500010] , gb2[500010];
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
void wk1(){
	if(1ll * (a[0][1] - a[1][1]) * (a[0][l[0]] - a[1][l[1]]) <= 0){
		putchar('0');
		return;
	}
	if(a[0][1] > a[1][1]){
		d = 0;
		x = 1;
	}else{
		d = 1;
		x = 0;
	}
	nwx = 1;
	for(int i = 1;i <= l[d];i++){
		if(a[d][i] > a[x][nwx + 1] && (nwx < l[x] || a[d][i] > a[x][l[x]])){
			while(a[d][i] > a[x][nwx + 1] && nwx < l[x]){
				nwx++;
			}
		}else{
			while(a[d][i] <= a[x][nwx] && nwx > 0){
				nwx--;
			}
			if(nwx == 0){
				nwx = -1;
				break;
			}
		}
	}
	if(nwx == l[x]){
		putchar('1');
	}else{
		putchar('0');
	}
	return;
}
int main(){
	freopen("expand.in" , "r" , stdin);
	freopen("expand.out" , "w" , stdout);
	c = rd() , l[0] = rd() , l[1] = rd() , q = rd();
	for(int i = 1;i <= l[0];i++){
		a[0][i] = rd();
	}
	for(int i = 1;i <= l[1];i++){
		a[1][i] = rd();
	}
	wk1();
	while(q--){
		t1 = rd() , t2 = rd();
		for(int i = 1;i <= t1;i++){
			t3 = rd() , t4 = rd();
			ga1[i] = t3;
			ga2[i] = a[0][t3];
			a[0][t3] = t4;
		}
		for(int i = 1;i <= t2;i++){
			t3 = rd() , t4 = rd();
			gb1[i] = t3;
			gb2[i] = a[1][t3];
			a[1][t3] = t4;
		}
		wk1();
		for(int i = 1;i <= t1;i++){
			a[0][ga1[i]] = ga2[i];
		}
		for(int i = 1;i <= t2;i++){
			a[1][gb1[i]] = gb2[i];
		}
	}
	return 0;
}