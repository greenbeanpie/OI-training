#include <bits/stdc++.h>
using namespace std;
mt19937 sj(738);
struct nd1{
	int lx , bh , sj;
}tt1;
struct nd2{
	int bh , sj;
}tt2 , tt3;
int c , t , n , m , as , s , t1 , t2 , qf[5] = {0 , 2 , 1 , 3} , a[100010] , b[100010] , cz[100010][3] , zh[100];
char op;
bool ud[100010];
vector <nd1> v[100010];
queue <nd2> q;
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
void dfs(int nw){
	if(nw > n){
		s = 0;
		for(int i = 1;i <= n;i++){
			b[i] = a[i];
			if(a[i] == 3){
				s++;
			}
		}
		for(int i = 1;i <= m;i++){
			if(cz[i][0] <= 3){
				b[cz[i][1]] = cz[i][0];
			}else if(cz[i][0] == 4){
				b[cz[i][1]] = b[cz[i][2]];
			}else if(cz[i][0] == 5){
				b[cz[i][1]] = qf[b[cz[i][2]]];
			}
		}
		for(int i = 1;i <= n;i++){
			if(a[i] != b[i]){
				break;
			}else if(i == n){
				as = min(as , s);
			}
		}
		return;
	}
	a[nw] = 1;
	dfs(nw + 1);
	a[nw] = 2;
	dfs(nw + 1);
	a[nw] = 3;
	dfs(nw + 1);
	return;
}
void wk1(){
	as = 1e9;
	dfs(1);
	printf("%d\n" , as);
}
void wk2(){
	as = 0;
	memset(a , 0 , sizeof(a));
	for(int i = 1;i <= m;i++){
		if(cz[i][0] == 3){
			if(!a[cz[i][1]]){
				a[cz[i][1]] = 1;
				as++;
			}
		}else{
			if(a[cz[i][1]]){
				a[cz[i][1]] = 0;
				as--;
			}	
		}
	}
	printf("%d\n" , as);
}
void wk3(){
	as = 0;
	for(int i = 1;i <= n;i++){
		v[i].clear();
	}
	memset(ud , false , sizeof(ud));
	for(int i = 1;i <= m;i++){
		tt1.sj = i;
		if(cz[i][0] == 4){
			if(cz[i][1] != cz[i][2]){
				tt1.lx = 1;
				tt1.bh = cz[i][1];
				v[cz[i][2]].emplace_back(tt1);
				tt1.lx = 2;
				tt1.bh = cz[i][2];
				v[cz[i][1]].emplace_back(tt1);
			}
		}else{
			tt1.lx = 3;
			v[cz[i][1]].emplace_back(tt1);
			tt2.sj = i;
			tt2.bh = cz[i][1];
			q.push(tt2);
		}
	}
	int l , r , md;
	while(!q.empty()){
		tt2 = q.front();
		q.pop();
		if(!tt2.sj){
			l = -1;
		}else{
			l = 0;
			r = v[tt2.bh].size() - 1;
			while(l < r){
				md = (l + r) >> 1;
				if(v[tt2.bh][md].sj > tt2.sj){
					r = md - 1;
				}else if(v[tt2.bh][md].sj < tt2.sj){
					l = md + 1;
				}else{
					l = r = md;
				}
			}
		}
		l++;
		if(l == v[tt2.bh].size() && !ud[tt2.bh]){
			as++;
			ud[tt2.bh] = true;
			tt3.bh = tt2.bh;
			tt3.sj = 0;
			q.push(tt3);
		}
		for(int i = l;i < v[tt2.bh].size();i++){
			if(v[tt2.bh][i].lx == 1){
				tt3.bh = v[tt2.bh][i].bh;
				tt3.sj = v[tt2.bh][i].sj;
				q.push(tt3);
				if(i == v[tt2.bh].size() - 1 && !ud[tt2.bh]){
					as++;
					ud[tt2.bh] = true;
					tt3.bh = tt2.bh;
					tt3.sj = 0;
					q.push(tt3);
				}
			}else{
				break;
			}
		}
	}
	printf("%d\n" , as);
}
int main(){
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out" , "w" , stdout);
	zh['T'] = 1;
	zh['F'] = 2;
	zh['U'] = 3;
	zh['+'] = 4;
	zh['-'] = 5;
	c = rd() , t = rd();
	while(t--){
		n = rd() , m = rd();
		for(int i = 1;i <= m;i++){
			op = 'G';
			while(!zh[op]){
				op = getchar();
			}
			cz[i][0] = zh[op];
			cz[i][1] = rd();
			if(zh[op] > 3){
				cz[i][2] = rd();
			}
		}
		if(c <= 2){
			wk1();
		}else if(c <= 4){
			wk2();
		}else if(c <= 6){
			wk3();
		}else{
			printf("%d\n" , sj() % n + 1);
		}
	}
	return 0;
}