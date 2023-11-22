#include <iostream>
#include <vector>
#define fi first
#define se second
using namespace std;
const int N = 100005;
int n, m, x, now[N];
char op, role[N];
int read(){
    int x = 0;
    char a = getchar();
    while(a < '0' || '9' < a) a = getchar();
    while('0' <= a && a <= '9') x = (x << 1) + (x << 3) + (a ^ 48), a = getchar();
    return x;
}
char gec(){
    char a = getchar();
    while(!(a == '+' || a == '-' || 'A' <= a && a <= 'Z')) a = getchar();
    return a;
}
void write(int x){
    if(x > 9) write(x / 10);
    putchar(x | 48);
}
char change(char &a){
    if(a == 'T') return 'F';
    if(a == 'F') return 'T';
    return 'U';
}
int main(){
    //freopen("tribool1.in", "r", stdin);
    //freopen("tribool.out", "w", stdout);
    read();
    for(int t = read(); t >= 1; t --){
        n = read(), m = read();
        for(int i = 1; i <= n; ++ i) now[i] = i;
        for(int i = 1; i <= m; ++ i){
            op = gec(), x = read();
            if(op == 'T' || op == 'F' || op == 'U') now[x] = x, role[x] = op;
            else now[x] = (op == '+'? 1: -1) * now[read()];
        }
        for(int i = 1; i <= n; ++ i)
    }
    return 0;
}
