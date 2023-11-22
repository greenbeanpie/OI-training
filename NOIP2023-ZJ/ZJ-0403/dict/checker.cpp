#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main()
{
	freopen("dict4.ans","r",stdin); cin>>s1;
	freopen("dict.out","r",stdin); cin>>s2;
	for(int i=0;i<s1.size();i++)
	if(s1[i] != s2[i]) cout<<i<<endl;
	return 0;
}