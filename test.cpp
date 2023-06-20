#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
    int operator&(){
        return a;
    }
    node &operator=(node c){
        a=c.a;
        return *this;
    }
    node &operator=(int c){
        a=c;
        return *this;
    }
    int operator+(node c){
        return a+c.a;
    }
}a;
int main(){
    a.a=1;
    a=2;
    node b;
    b=3;
    cout << a+b;
    return 0;
}