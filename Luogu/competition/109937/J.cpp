#include <iostream>
using namespace std;
int main()
{
    int a;
    //cin >> a;
    a=2;
    if (a == 1)
    {
        cout << "34 65 98";
    }
    else{
        cout << 2 << endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<2000000;j++){
                putc('a',stdout);
            }
            putc('\0',stdout);
        }
    }
    return 0;
}