#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int c[N][N],n,m,d[N][N],ans[N],id1,id2;
bool cmp(int x,int y){
	return x > y;
}
int cmp2(int x,int y){
	//1: x < y.0 : x = y,-1 : x > y
	for(int i=1;i<=m;i++)
		if(d[x][i] != d[y][i]){
			if(d[x][i] < d[y][i]) return 1;
			else return -1;
		}
	return 0;
}
bool cmp3(int x,int y){
	for(int i=1;i<=m;i++)
		if(c[x][i] != d[y][i]) return c[x][i] < d[y][i];
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string str; cin >> str;
		for(int j=0;j<m;j++)
			d[i][j + 1] = c[i][j + 1] = str[j] - 'a';
	}
	for(int i=1;i<=n;i++){
		sort(c[i] + 1,c[i] + m + 1);
		sort(d[i] + 1,d[i] + m + 1,cmp);
	}
	//for(int i=1;i<=n;i++) cout<<c[i][1]<<" ";
	//cout<<endl;
	//for(int i=1;i<=n;i++) cout<<d[i][1]<<" ";
	//cout<<endl;
	d[0][1] = 27;
	for(int i=1;i<=n;i++){
		if(cmp2(i,id1) >= 0) id2 = id1,id1 = i;
		else if(cmp2(i,id2) > 0) id2 = i;
	}
	for(int i=1;i<=n;i++){
		int id = id1;
		if(id == i) id = id2;
		if(cmp3(i,id)) ans[i] = 1;
		else ans[i] = 0;  
	}
	for(int i=1;i<=n;i++) printf("%d",ans[i]);
	return 0;
}
