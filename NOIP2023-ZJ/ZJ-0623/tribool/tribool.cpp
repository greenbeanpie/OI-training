#include <bits/stdc++.h>
using namespace std;
const int N = 1E5+10;
int c,t;
int n,m;
bool flag = false;
char ori_var[N];                   // 1:T 2:F 3:U
char new_var[N];
int min_num = 114514;
char all_state[10] = "TFU";
char op;

void move(){
    for(int i = 0;i < n;i ++) new_var[i] = ori_var[i];
}

int reverse(char state){
    if(state == 'T') return 'F';
    if(state == 'F') return 'T';
    if(state == 'U') return 'U';
}

void test(){
        while(m --){
        	char op;
			cin >> op;
            if(op == 'T'||op == 'F'|| op == 'U'){
				int change;
    			cin >> change;
    			new_var[change] = op;
            }

            if(op == '+'){
                int num1,num2;
                cin >> num1 >> num2;
                new_var[num1] = new_var[num2];
            }
            if(op == '-'){
                int num1,num2;
                cin >> num1 >> num2;
                new_var[num1] = reverse(new_var[num2]);
            }
        }
        int trial = 0;
        for(int i = 0;i < n;i ++){
            if(new_var[i] == ori_var[i]) trial ++;
        }

        int cur_num = 0;
        for(int i = 0;i < n;i ++){
            if(ori_var[i] == 'U') cur_num ++;
        }
        
        if(trial == n) min_num = min(min_num,cur_num);
    }

void dfs(int pos){
    if(pos == n){                   //已经遍历完
        move();
        test();
        return;
    }
    
    for(int i = 0;i < 3;i ++){
        ori_var[pos] = all_state[i];
        dfs(pos+1);
    }
}


void subtask_1(){
	while(t--){
		cin >> n >> m;              //分别表示变量个数和语句条数
		dfs(n);
    	cout << min_num;
	}
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
	cin >> c >> t;
    
    if(c == 1 || c == 2) subtask_1();

    return 0;
}