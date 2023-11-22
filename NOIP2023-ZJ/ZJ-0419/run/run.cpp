#include <iostream>
using namespace std;
int c,t,n,m,k,d;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;++i)
		{
			int x,y,v;
			cin>>x>>y>>v;
		}
		cout<<m+k+d-n<<endl;
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
