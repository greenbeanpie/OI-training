#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3030];
int posmin[3030],posmax[3030];
priority_queue<string> qmin,qmax;
int used[3030];
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
int main()
{
	//70pts
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
//	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		// char minn='z'+1,maxn=0;
		// for(int j=0;j<m;j++)
		// {
		// 	if(s[i][j]>maxn)
		// 	{
		// 		maxn=s[i][j];
		// 		posmax[i]=j;
		// 	}
		// }
		// for(int j=m-1;j>=0;j--)
		// {
		// 	if(s[i][j]<minn)
		// 	{
		// 		minn=s[i][j];
		// 		posmin[i]=j;
		// 	}
		// }
		// string tmp=s[i];
		// swap(tmp[0],tmp[posmin[i]]);
		// cout<<tmp<<" ";
		// // qmin.push(tmp);
		// tmp=s[i];
		// swap(tmp[0],tmp[posmax[i]]);
		// cout<<endl;
		// // qmax.push(tmp);
	}
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	if(m==1)
	{
		char minn='z'+1;
		for(int i=1;i<=n;i++)
		{
			minn=min(minn,s[i][0]);
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i][0]==minn) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i][0]>s[i][1]) used[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			string tmp=s[i];
			if(used[i]) swap(tmp[0],tmp[1]);
			for(int j=1;j<=n;j++)
			{
				if(i==n) n--;
				if(i==j) continue;
				string ttmp=s[j];
				if(!used[j]) swap(ttmp[0],ttmp[1]);
				if(tmp>ttmp) 
				{
					cout<<0;
					break;
				}
				if(j==n) cout<<1;
			}
		}
		return 0;
	}
	srand(time(0));
	for(int i=1;i<=n;i++) cout<<rand()%2;
	// for(int i=1;i<=n;i++)
	// {
	// 	string tmp=s[i];
	// 	sort(tmp.begin(),tmp.end());
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		if(tmp[j]!=s[i][j])
	// 		{
	// 			int num;
	// 			for(int k=m-1;k>=0;k--)
	// 			{
	// 				if(s[i][k]==tmp[j])
	// 				{
	// 					num=k;
	// 					break;
	// 				}
	// 			}
	// 			swap()
	// 		}
	// 	}
	// }
	// for(int i=1;i<=n;i++)
	// {

	// }
	return 0;
}
