//NOIP2023���ͣ�rp++
//jmyzq & yzt
//����ȫ���綼�����㣬��Ҳ����
//Ϊ��ս�������������ϵ���ҫ
//T�����ݲ�Ҫ���ǳ�ʼ��
//freopen�ǵü��
//���鲻Ҫ��̫��MLE���ؿ�������
//���ֵ��Ҫ��ֵ̫С
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+5;
int n,m;
string s1[3010],s2[3010],s;
char c[3010][3010];
string ans;
bool k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		sort(c[i]+1,c[i]+1+m);
		for(int j=1;j<=m;++j)
		{
			s=c[i][j];
			s1[i]+=s;
		}
		sort(c[i]+1,c[i]+1+m,cmp);
		for(int j=1;j<=m;++j)
		{
			s=c[i][j];
			s2[i]+=s;
		}
	}
	for(int i=1;i<=n;++i)
	{
		k=1;
		for(int j=1;j<=n;++j)
		{
			if(i==j) continue;
			if(s1[i]>s2[j]) k=0;
		}
		if(k==1) ans+="1";
		else ans+="0";
	}
	cout<<ans<<"\n";
	return 0;
}
