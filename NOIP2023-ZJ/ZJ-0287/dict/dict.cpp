#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
int a[N][26];
int b[N][2];
char str[N];
int n,m;
bool check(int x){
	for(int i = 1;i <= n;i++)if(i != x)
		if(b[i][1] <= b[x][0]) return false;
	return true;
}
int main(){
	//100
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%s",str+1);
		for(int j = 1;j <= m;j++) a[i][str[j]-'a'+1]++;
		for(int j = 1;j <= 26;j++) if(a[i][j] > 0 && b[i][0] == 0)
			b[i][0] = j;
		for(int j = 26;j >= 1;j--) if(a[i][j] > 0 && b[i][1] == 0)
			b[i][1] = j;
		//printf("%d %d\n",b[i][0],b[i][1]);
	}
	if(n == 1){
		printf("1\n");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		if(check(i)) putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}