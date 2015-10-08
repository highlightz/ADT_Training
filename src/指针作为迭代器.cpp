// 把指针作为迭代器用于STL的find()算法来搜索普通的数组
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 100
int iarray[SIZE];
int main( )
{
    iarray[20] = 50;
    int* ip = find( iarray, iarray + SIZE, 50 );
    if ( ip == iarray + SIZE )
    {
        cout << ip << endl;  // 显示迭代器当前存储的地址值
        cout << iarray << endl;  // 显示容器首部迭代器的地址值
        cout << "50 not found in array" << endl;
    }
    else
    {
        cout << ip << endl;  // 显示迭代器当前存储的地址值
        cout << iarray << endl;  // 显示容器首部迭代器的地址值
        cout << *ip << " found in array" << endl;
    }    
    return 0;
}
