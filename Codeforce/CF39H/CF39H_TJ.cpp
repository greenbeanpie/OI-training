#include<bits/stdc++.h>
using namespace std;

int n;
char z[10]={'0','1','2','3','4','5','6','7','8','9'};

string turn(int x)
{
    string a="";
    while(x)a=z[x%n]+a,x/=n;
    return a;    
}

int main()
{
	ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)cout<<turn(i*j)<<' ';
		cout<<endl;
	}
	return 0;
}