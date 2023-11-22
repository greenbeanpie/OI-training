#include<bits/stdc++.h>
using namespace std;
int num[3010][30],n,m,in[3010],ax[3010];
string w[3010];
void zh(int x){
	in[x]=26,ax[x]=0;
	for(int i=0;i<m;i++){
		num[x][w[x][i]-'a']++;
		in[x]=min(in[x],w[x][i]-'a');
		ax[x]=max(ax[x],w[x][i]-'a');
	}
	return;
}
bool bj(int x,int y){
	int x_num=in[x],y_num=ax[y];
	if(y_num<x_num)
	return 0;
	if(x_num<y_num)
	return 1;
	return 0;
}
int solve(int x){
	for(int i=1;i<=n;i++){
		if(i!=x){
			if(!bj(x,i)){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		zh(i);
	}
	for(int i=1;i<=n;i++){
		cout<<solve(i);
	}
	return 0;
}
