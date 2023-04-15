#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,ans=0;
struct node{
	int first,second;
}p[1000001];
bool cmp(node a,node b)
{
	return a.second<b.second;
}
int main()
{
	cin >> n;
	int t=0;
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(p[i].first>=t)
		{
			ans++;
			t=p[i].second;
		}
	cout << ans<< endl;
	return 0;
}

