#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	long long list1[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list1[i];
	}
	cin >> m;
	long long list2[m];
	for (int i = 0; i < m; i++)
	{
		cin >> list2[i];
	}
	int list2r[m]={0},list2n[m]={0},lastmax;
	for(int i=0;i<m;i++){
		list2r[i]=-1;
		list2n[i]=-1;
	}
	for(int i=0;i<n;i++){

		lastmax=-1;
		for(int j=0;j<m;j++){
			list2n[j]=max(list2n[j],-1);
			if(list1[i]>list2[j]){// 如果list1[i]的数大于list2[j]，那么就暂时认为list2[j]是序列中上一个连续公共最大的数
				lastmax=max(lastmax,list2r[j]);
			}
			if(list1[i]==list2[j]){
				list2n[j]=max(list2n[j],list2n[lastmax]+1);
				list2r[j]=lastmax;
			}
		}
	}
	return 0;
}