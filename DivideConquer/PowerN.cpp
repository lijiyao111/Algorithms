#include <iostream>
using namespace std;

// time: O(logn)
int power(int x, int n){
    if(n==0)
        return 1;
    int tmp=power(x,n/2);
    if(n%2==0)
        return tmp*tmp;
    else
        return x*tmp*tmp;
}

int main(){
    cout<<power(5,3);
}