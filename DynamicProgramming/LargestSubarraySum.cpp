#include <cstdlib>
#include <iostream>
#include "array_utils.h"
using namespace std;

/*
Kadane's Algorithm to find the maximum subarray
Also print the start and end index of the max subarray
Time Complexity: O(n)
*/

// Can't deal with all negative array
int max_subarray(int *a,int n){
    int max_sofar=0;
    int max_endinghere=0;
    int indL=0,indR=0,s=0;
    for(int i=0;i<n;++i){
        max_endinghere +=a[i];
        if(max_endinghere<0){
            max_endinghere=0;
            s=i;
        }
        if(max_endinghere>max_sofar){
            max_sofar=max_endinghere;
            indL=s+1;
            indR=i;
        }
    }
    cout<<"Start index "<<indL<<" End index "<<indR<<endl;
    return max_sofar;
}

// OK with all negative array
int max_subarray_allNeg(int a[],int n){
    int max_sofar=a[0];
    int max_endinghere=a[0];
    int indL=0,indR=0,s=0;
    for(int i=1;i<n;++i){
        max_endinghere +=a[i];
        if(max_endinghere<a[i]){
            max_endinghere=a[i];
            s=i;
        }
        if(max_endinghere>max_sofar){
            max_sofar=max_endinghere;
            indL=s;
            indR=i;
        }
    }
    cout<<"Start index "<<indL<<" End index "<<indR<<endl;
    return max_sofar;
}

int main(){
    int a[]={-10,-3,-4,-1,-2,-1,-3,-5,-4,-2,-9,-10,-1};
    int b[]={-10,-3,4,-1,-2,1,3,-5,14,-2,-9,-10,-1};
    int n=sizeof(a)/sizeof(int);

    JL::print_array1d(a,n);
    cout<<"Max subarray: "<<max_subarray(a,n)<<'\n';
    cout<<"Max subarray: "<<max_subarray_allNeg(a,n)<<'\n';

    JL::print_array1d(b,n);
    cout<<"Max subarray: "<<max_subarray(b,n)<<'\n';
    cout<<"Max subarray: "<<max_subarray_allNeg(b,n)<<'\n';

}