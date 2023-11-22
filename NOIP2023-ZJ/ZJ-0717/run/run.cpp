#include<bits/stdc++.h>
using namespace std;


int c,t;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout); 	
	srand(time(0));
	scanf("%d%d",&c,&t);
	while(t--)
	{
		cout<<rand()%10;	
	}
	return 0;	
}
