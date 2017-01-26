#include <iostream>

using namespace std;

/*
Normal recursive method, very slow when n is large
*/
int fib(int n){
    if(n==1||n==2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

/*
Dynamic programming bottom up
*/
int fib_botup(int n){
    /*
    Or can use an array to store values
    */
    if(n==1||n==2){
        return 1;
    }
    int fibn_1=1;
    int fibn_2=1;
    int out;
    for(int i=3;i<=n;++i){
        out=fibn_1+fibn_2;
        fibn_2=fibn_1;
        fibn_1=out;
    }
    return out;
}


/*
Dynamic programming top down, also called Memoization
When top down, usually an extra table is required to store the status/value
of the recursive variable.
*/

const int MAX=2000;
const int NIL=-1;

int lookup[MAX];

void _initialize(){
    for(int i=0;i<MAX;++i){
        lookup[i]=NIL;
    }
}

int fib_topdown(int n){
    if(lookup[n-1] != NIL){
        return lookup[n-1];
    }
    else{
        if(n==1||n==2){
            lookup[n-1]=1;
            return lookup[n-1];
        }
        lookup[n-1]= fib(n-1)+fib(n-2);
        return lookup[n-1];
    }
}

int main(){
    _initialize();
    int n=20;
    cout<<"Hello! n="<<n<<endl;
    cout<<"Normal recursive "<<fib(n)<<'\n';
    cout<<"DP Bottom up "<<fib_botup(n)<<'\n';
    cout<<"DP Top down "<<fib_topdown(n)<<'\n';

}