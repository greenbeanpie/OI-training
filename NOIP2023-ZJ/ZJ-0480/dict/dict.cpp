#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	string s;
	int id;
}q[6060];
bool cmp(node x,node y){
	return x.s<y.s||(x.s==y.s&&x.id>y.id);
}
int cnt[6060];
string ss;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
//	cout<<n<<"***"<<m<<endl;
	
	for (int i=1;i<=n;i++){getchar();
		for (int j=0;j<26;j++)
		cnt[j]=0;
		for (int j=0;j<m;j++)
		cnt[getchar()-'a']++;
		for (int j=0;j<26;j++)
		while(cnt[j]--)q[i].s.push_back(j+'a');
		for (int j=0;j<m;j++)
		q[i+n].s.push_back(q[i].s[m-1-j]);
		q[i].id=i;
	}
//	cout<<"*****\n";
	sort(q+1,q+2*n+1,cmp);
	for (int i=1;i<=n;i++)
	cnt[i]=0;
	for (int i=1;i<=2*n;i++)
	if (q[i].id) cnt[q[i].id]=1;
	else break;
	for (int i=1;i<=n;i++)
	printf("%d",cnt[i]);
	printf("\n");//cout<<endl;
}