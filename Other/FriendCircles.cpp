#include <iostream>
#include "../array_utils.h"
using namespace std;

const int N=5;

int friendCircles(char friends[][N]){
    int count=0;
    for(int i=1;i<N;++i){
        bool flag=false;
        for(int j=0; j<i; ++j){
            if(friends[i][j]=='Y'){
                flag=true;
                break;
            }
        }
        if(flag==false)
            count++;
    }

    if(count==N-1)
        return N;
    else
        return 1+count;
}

int main(){
    // char input1[N][N]={{'Y','Y','N','N'},
    //                 {'Y','Y','Y','N'},
    //                 {'N','Y','Y','N'},
    //                 {'N','N','N','Y'}};

    char input1[N][N]={{'Y','N','N','N','N'},
                    {'N','Y','N','N','N'},
                    {'N','N','Y','N','N'},
                    {'N','N','N','Y','N'},
                    {'N','N','N','N','Y'}};

    JL::print_array2d(&input1[0][0], N, N);
    cout<<friendCircles(input1);

}