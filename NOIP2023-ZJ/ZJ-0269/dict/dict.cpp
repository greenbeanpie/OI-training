#include<bits/stdc++.h>
using namespace std;
int n,m,sum[26];
string st1[3010],st2[3010],ltor[3010],rtol[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		memset(sum,0,sizeof sum);
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			sum[ch-'a']++;
		}
		for(int j=0;j<26;j++)
			for(int k=1;k<=sum[j];k++)
				st1[i]=st1[i]+(char)(j+'a');
		for(int j=25;j>=0;j--)
			for(int k=1;k<=sum[j];k++)
				st2[i]=st2[i]+(char)(j+'a');
	}
	ltor[1]=st2[1];
	for(int i=2;i<=n;i++)
		if(st2[i]<ltor[i-1])ltor[i]=st2[i];
		else ltor[i]=ltor[i-1];
	rtol[n]=st2[n];
	for(int i=n-1;i>=1;i--)
		if(st2[i]<rtol[i+1])rtol[i]=st2[i];
		else rtol[i]=rtol[i+1];
	for(int i=1;i<=n;i++){
		bool pd=0;
		pd|=(i>1)&&(ltor[i-1]<st1[i]);
		pd|=(i<n)&&(rtol[i+1]<st1[i]);
		cout<<(!pd);
	}
	return 0;
}
