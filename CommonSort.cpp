//
//  CommonSort.cpp
//  myproject
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#include "CommonSort.h"

Sort::Sort()
{
    
}

Sort::~Sort()
{
    
}
/*
template<typename T> void Sort::insert_sort(T *A, int N)
{
    
}
*/
template<typename T> void Sort::bubble_sort(T *data, int N)
{
    for(int i = 0;i < N - 1 ; i++)
    {
        for(int j = i + 1;j < N;j++)
        {
            if (data[i] > data[j]) {
                swap2(data[i], data[j]);
            }
        }
    }
}
/*
template<typename T> void Sort::select_sort(T *data, int N)
{
    
}

template<typename T> void Sort::merge_sort(T *data, int N)
{
    
}

template<typename T> void Sort::quick_sort(T *data, int low, int high)
{
    
}

template<typename T> void Sort::heap_sort(T *data, int N)
{
    
}

template<typename T> void Sort::shell_sort(T *data, int N)
{
    
}

template<typename T> void Sort::bucket_sort(T *data, int N)
{
    
}

template<typename T> void Sort::bin_sort(T *data, int N)
{
    
}
*/
void Sort::swap(int &a, int &b)
{	
    a = a + b;
    b = a - b;
    a = a - b;
}

void Sort::swap2(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}