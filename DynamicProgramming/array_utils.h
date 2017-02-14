#include <iostream>

namespace JL{
    template <class T>
    inline void print_array1d(T a, int n){
        for(int i=0;i<n;++i){
            std::cout<<a[i]<<' ';
        }
        std::cout<<'\n';
    }

    template <class T>
    inline void print_array2d(T A, int m, int n){
        for(int i=0; i< m; ++i){
            for(int j=0; j<n; ++j){
                std::cout<< A[i*n+j]<<" ";
            }
            std::cout<<'\n';
        }
    }

}

