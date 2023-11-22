//70，差不多了
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m;
string str[N];
char task1[N];
int ans[N];
int minhash[N];
int maxhash[N];
int str_to_int[N][N];       //s[i][j] 表示第i个字符串的第j个字符转化为的int

bool cmp(const int a,const int b){
	if(a > b) return b < a;
	else return a > b;
}

void subtask_1(){
    for(int i = 0;i < n;i ++) cin >> task1[i];
    int cur_min,num;
    for(int i = 0;i < n;i ++){
        if(int(task1[i] < cur_min)){
            cur_min = int(task1[i]);
            num = i;
        }
    }

    for(int i = 0;i < n;i ++){
        if(int(task1[i] == cur_min)) cout << 1;
        else cout << 0;
    }
}

void trans(string cur_string,int num){
    for(int i = 0;i < cur_string.length();i ++){
        str_to_int[num][i] = int(cur_string[i]) - 96;
    }
}

void calc_min_hash(){
	int cur_minhash;
	for(int i = 0;i < n;i ++) sort(str_to_int[i],str_to_int[i] + m);
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < m;j ++)
			cur_minhash += str_to_int[i][j] * pow(27,m - j - 1);
		minhash[i] = cur_minhash;
		cur_minhash = 0;
	}
}

void calc_max_hash(){
	for(int i = 0;i < n;i ++) sort(str_to_int[i],str_to_int[i] + m,cmp);
	
	int cur_maxhash;
	
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < m;j ++)
			cur_maxhash += str_to_int[i][j] * pow(27,m - j - 1);
		maxhash[i] = cur_maxhash;
		cur_maxhash = 0;
	}
}


void subtask_2(){
	for(int i = 0;i < n;i ++) cin >> str[i];
    for(int i = 0;i < n;i ++) trans(str[i],i); //存入str_to_int列表
    
	calc_max_hash();
    calc_min_hash();
    
    int trial = 0;
    for(int i = 0;i < n;i ++){
    	for(int j = 0;j < n;j ++){
    		if(minhash[i] <= maxhash[j]) trial ++;
		}
		if(trial == n) cout << 1;
		else cout << 0;
		trial = 0;
	}
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    if(m == 1) subtask_1();
    if(m == 2) subtask_2();
   
/*    cout << endl << endl;
    
    for(int i = 0;i < n;i ++){
    	cout << minhash[i] << " ";
	}
	
	cout << endl << endl;
	
    for(int i = 0;i < n;i ++) cout << maxhash[i] << " ";
    
    cout << endl << endl; 柚子社天下第一！
    
    for(int i = 0;i < n;i ++){
    	for(int j = 0;j < 15;j ++){
    		cout << str_to_int[i][j] << " ";
		}
		cout << endl;
	}
*/
    return 0;
}