#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N],b[N],p[N][3];
int c,t,n,m;
char ch;
int k[N],tot;
void init(){
	for(int i = 1;i <= m;i++){
		scanf("%s",&ch);
		if(ch == 'T' || ch == 'F' || ch == 'U'){
			scanf("%d",&p[i][1]);
			p[i][0] = 0;
			if(ch == 'T') p[i][2] = 1;
			if(ch == 'F') p[i][2] = -1;
			if(ch == 'U') p[i][2] = 0;
		}
		else{
			scanf("%d%d",&p[i][1],&p[i][2]);
			if(ch == '+') p[i][0] = 1;
			else p[i][0] = -1;
		}
		//printf("%d %d %d\n",p[i][0],p[i][1],p[i][2]);
	}
}
void solve1(){
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		int ans = 100;
		for(int i = 0;i < (int)pow(3,n);i++){
			int tmp = i,tot = 1;
			while(tmp > 0){
				a[tot] = b[tot] = tmp % 3 - 1;
				tmp /= 3;tot++;
			}
			for(int j = 1;j <= m;j++){
				if(p[j][0] == 0) b[p[j][1]] = p[j][2];
				else b[p[j][1]] = p[j][0] * b[p[j][2]];
			}
			bool flag = 0;
			for(int j = 1;j <= n;j++) if(a[j] != b[j])
				flag = 1;
			if(flag == 0){
				int tmpp = 0;
				for(int j = 1;j <= n;j++) if(a[j] == 0)
					tmpp++;
				ans = min(tmpp,ans);
			}
		}
		printf("%d\n",ans);
	}
}
void solve2(){
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		int ans = 0;
		for(int i = 1;i <= n;i++) a[i] = 2;
		for(int i = 1;i <= m;i++) a[p[i][1]] = p[i][2];
		for(int i = 1;i <= n;i++) if(a[i] == 0) ans++;
		printf("%d\n",ans);
	}
}
vector<int>to[N];
int num[N];
void solve3(){
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		int ans = 0;
		for(int i = 1;i <= n;i++) a[i] = i;
		for(int i = 1;i <= m;i++){
			if(p[i][0] == 0) a[p[i][1]] = 0;
			else a[p[i][1]] = a[p[i][2]];	
		}
		for(int i = 1;i <= n;i++){
			int x = a[i];
			while(a[x] != x) x = a[x];
			a[i] = x;
		}
		memset(num,0,sizeof(num));
		for(int i = 1;i <= n;i++) num[a[i]]++;
		printf("%d\n",num[0]);
	}
}
int main(){
	//40
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c <= 2) solve1();
	else if(c <= 4) solve2();
	else solve3();
	return 0;
}