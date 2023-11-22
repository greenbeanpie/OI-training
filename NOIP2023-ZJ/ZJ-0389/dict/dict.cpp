#include<bits/stdc++.h>
using namespace std;
char a[3005];
string ma[3005],mi[3005];
bool cmp(char p,char q){
	return p>q;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",a);
		sort(a,a+m,cmp);
		for(int j=0;j<m;j++)ma[i]+=a[j],mi[i]+=a[m-j-1];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	int mini;
	string min1,min2;
	if(ma[1]<ma[2]){
		min1=ma[1];
		min2=ma[2];
		mini=1;
	}
	else{
		min1=ma[2];
		min2=ma[1];
		mini=2;
	}
	for(int i=3;i<=n;i++){
		if(ma[i]<min1){
			mini=i;
			min2=min1;
			min1=ma[i];
		}
		else min2=ma[i];
	}
	for(int i=1;i<=n;i++){
		string minn=((i==mini)?min2:min1);
		if(mi[i]<minn){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	return 0;
}