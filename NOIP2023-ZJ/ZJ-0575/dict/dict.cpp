#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[3005][26];
int b[3005][2];

bool bl(int p){
	for(int i = 0;i < n;i++){
		if(i==p)continue;
		if(b[p][0]>=b[i][1])return false;
	}
	return true;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	char c;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> c;
			a[i][c-'a']++;
		}
		int x = 0;
		while(!a[i][x]&& x < 26)x++;
		b[i][0]=x;
		x = 25;
		while(!a[i][x] && x >= 1)x--;
		b[i][1]=x;
	}
	for(int _i = 0;_i < n;_i++){
		if(bl(_i))cout << 1;
		else cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
}
