#include<bits/stdc++.h>
using namespace std;
const int MAXM = 3005;
char w[MAXM][MAXM];
bool c[MAXM][30];
int n,m;
bool cmp(int id){
	int t;
	for(int i = 1;i <= 26;i++){//target : a ~ z
		if(c[id][i]){
			t = i;
			break;
		}
	}
	for(int i = 1;i <= n;i++){//cmp : z ~ a
		if(i == id) continue;
		for(int j = 26;j >= 1;j--){
			if(c[i][j]){
				int x = j;
				if(x > t) break;//first one pass
				else return false;
			}
		}
	}
	return true;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		cin>>w[i];
		for(int j = 0;j < m;j++){
			c[i][w[i][j] - 'a' + 1] = true;
		}
	}
	if(n == 1){
		printf("1");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		if(cmp(i)) printf("1");
		else printf("0");
	}
	return 0;
}