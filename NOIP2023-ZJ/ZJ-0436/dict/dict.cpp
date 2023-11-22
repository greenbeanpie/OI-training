#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[3010];
int C[3010];
int min_c[3010][3010],maxn[3010];
bool cmp1(int a,int b){
	return a>b;
}
bool cmp2(int a,int b){
	return a<b;
}
bool pd(){
	for(int i=0;i<m;i++)
	{if(C[i]>maxn[i])return 0;
	if(C[i]<maxn[i])return 1;
	}
	return 1;
}
void get_zhi(){
for(int i=0;i<m;i++)
C[i]=int(c[i]-'a'+1);
}
void get_ans(int x){
  sort(C,C+m,cmp1);
  if(pd())
  {
  	for(int i=0;i<m;i++)
  	maxn[i]=C[i];
  }
  sort(C,C+m,cmp2);
  for(int i=0;i<m;i++)
  min_c[x][i]=C[i];
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	maxn[i]=999;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		get_zhi();
		get_ans(i);
	}
	bool w=0;
	for(int i=1;i<=n;i++)
	{
	w=0;
	for(int j=0;j<m;j++)
	{if(min_c[i][j]>maxn[j])
	{
		cout<<0;
		w=1;
		break;
	}
	if(min_c[i][j]<maxn[j]){
		cout<<1;
		w=1;
		break;
	}
	}
	if(w==0)
	cout<<1;
}

}
