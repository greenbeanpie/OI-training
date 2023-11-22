#include<bits/stdc++.h>
using namespace std;
int n;
int a[3005];
int b[3005];

int main(){
	freopen("dict4.in","r",stdin);
	scanf("%d",&n);
	freopen("dict4.ans","r",stdin);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	freopen("dict.out","r",stdin);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i){
		if(a[i]!=b[i]){
			cout<<"NOOOOO\n";
			return 0;
		}
	}
	cout<<"Yesss\n";
	return 0;
}