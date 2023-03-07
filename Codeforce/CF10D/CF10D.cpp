#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> m;// 关于为什么这里把list1和list2的输入顺序换了就能过了 我的评价是：6
	long long list2[m];
	for (int i = 0; i < m; i++)
	{
		cin >> list2[i];
	}
	cin >> n;
	long long list1[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list1[i];
	}
	int list2r[m]={0},list2n[m]={0},lastmaxn,lastmaxr,maxinumn=0,maxinumr=-1;
	for(int i=0;i<m;i++){
		list2r[i]=-1;
		list2n[i]=0;
	}
	for(int i=0;i<n;i++){

		lastmaxr=-1;
		lastmaxn=0;
		for(int j=0;j<m;j++){
			if(list1[i]>list2[j]&&lastmaxn<list2n[j]&&list2n[j]!=0){
				lastmaxn=list2n[j];
				lastmaxr=j;
			}
			if(list1[i]==list2[j]){
				list2n[j]=lastmaxn+1;
				list2r[j]=lastmaxr;
				if(maxinumn<lastmaxn+1){
					maxinumn=lastmaxn+1;
					maxinumr=j;
				}
			}
		}
	}
	int tempr=maxinumr;
	stack<int> public_max;
	while(tempr!=-1){
		public_max.push(list2[tempr]);
		tempr=list2r[tempr];
	}
	cout << maxinumn << endl;
	while(!public_max.empty()){
		cout << public_max.top() << " ";
		public_max.pop();
	}
	return 0;
}