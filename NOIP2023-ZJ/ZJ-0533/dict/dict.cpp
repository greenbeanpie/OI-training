#include<bits/stdc++.h>
using namespace std;

void IO(string str){
	freopen((str+".in").c_str(), "r", stdin);
	freopen((str+".out").c_str(), "w", stdout);
}

constexpr int N=3005, M=3005;
int n, m;
int cnt[N][128];

bool cmp(int x, int y){ //x<y? true: false
	int i='a', j='z';
	while(i<='z' && !cnt[x][i])  i++;
	while(j>='a' && !cnt[y][j])  j--;
	if(i<j)  return true;
	if(i>=j)  return false;
	return false;
}

bool solve(int x){
	for(int i=1; i<=n; ++i){
		if(i==x)  continue;
		if(!cmp(x, i))  return false;
	}
	return true;
}

int main(){
	IO("dict");
//	IO("dict4");
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		char s[M];
		scanf("%s", s);
		for(int j=0; j<m; ++j)  cnt[i][s[j]]++;
	}
	for(int i=1; i<=n; ++i)
		printf("%d", solve(i));
	cout<<'\n';
	return 0;
}