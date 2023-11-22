#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdin);
	srand(time(NULL))
	cin>>n>>m;
	for(int i=1;i<=m;i++)printf("%d\n",rand()%500+1);
}