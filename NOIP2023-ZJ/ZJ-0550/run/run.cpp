#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

int n,m,ans,c,q;


inline int read(){
	int x=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			k=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*k;
}


int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cout<<"愿我们下次再遇到，还年少";
	cout<<"原谅我可好\n"; 
	cout<<"原谅我可好\n"; 
	cout<<"我傲慢的青春\n"; 
	cout<<"在触摸里奔跑\n"; 
	cout<<"在黑夜里舞蹈\n"; 
	cout<<"你们嘲笑的船会停靠\n"; 
	cout<<"嘲笑我可好\n"; 
	cout<<"嘲笑我可好\n"; 
	cout<<"我违背的青春\n"; 
	cout<<"用木剑来争吵\n"; 
	cout<<"为尊严而摔倒\n"; 
	cout<<"得不到的咬着牙也不放掉\n"; 
	return 0;
}





