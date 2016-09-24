//
//  CommonSort.h
//  myproject
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#ifndef CommonSort_h
#define CommonSort_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct node
{
    T key;
    struct node* next;
};

class Sort
{
public:
    Sort();
    ~Sort();
    template<typename T> void bubble_sort(T* data,int N);
    template<typename T> void insert_sort(T* data,int N);
    template<typename T> void select_sort(T* data,int N);
    template<typename T> void merge_sort(T* data,int N);
    template<typename T> void quick_sort(T* data,int low, int high);
    template<typename T> void heap_sort(T* data,int N);
    template<typename T> void shell_sort(T* data,int N);
    template<typename T> void bucket_sort(T* data,int N, int bucket_size);
    
private:
    template<typename T> void swap(T& a,T& b);
    template<typename T> void merge_array(T* data,int first,int mid,int last);
    template<typename T> void mergeSort(T* data,int first,int last);
    template<typename T> void swap2(T& a,T& b);
    template<typename T> void build_heap(T* data,int N);
    template<typename T> void heap_adjust(T* data,int node, int N);
};



Sort::Sort()
{
    
}

Sort::~Sort()
{
    
}

template<typename T>
void Sort::insert_sort(T *data, int N)
{
    for (int i = 1; i < N; i++)
    {
        if(data[i - 1] > data[i])
        {
            T temp = data[i];
            int j= i;
            while(j > 0 && data[j - 1] > temp )
            {
                data[j] = data[j - 1];
                j--;
            }
            data[j] = temp;
        }
    }
}

template<typename T>
void Sort::bubble_sort(T *data, int N)
{
    for(int i = 0;i < N - 1 ; i++)
    {
        for(int j = i + 1;j < N;j++)
        {
            if (data[i] > data[j]) {
                swap<T>(data[i], data[j]);
            }
        }
    }
}

template<typename T>
void Sort::select_sort(T *data, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int pos = i;
        for(int j = i + 1;j < N; j++)
        {
            if(data[j] < data[pos])
            {
                pos = j;
            }
        }
        if(pos != i) swap<T>(data[i], data[pos]);
    }
}
 
template<typename T>
void Sort::merge_sort(T *data, int N)
{
    mergeSort(data, 0, N - 1);
}

template<typename T>
void Sort::quick_sort(T *data, int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int left = low;
    int right = high;
    T split = data[low];
    while(left < right)
    {
        while (left < right && data[right] >= split) right--;
        data[left] = data[right];
        
        while (left < right && data[left] <= split) left++;
        data[right] = data[left];
    }
    data[left] = split;
    quick_sort(data, low , left - 1);
    quick_sort(data, right + 1, high);
}

/*
 ref:http://blog.csdn.net/xiaoxiaoxuewen/article/details/7570621/
 */
 template<typename T>
 void Sort::heap_sort(T *data, int N)
 {
     build_heap(data, N);
     for (int i = N; i >= 0; i--) {
         swap(data[0], data[i]);
         heap_adjust(data, 0, i - 1);
     }
 }

/*
 ref:http://www.cnblogs.com/jingmoxukong/p/4303279.html
 */
 template<typename T>
 void Sort::shell_sort(T *data, int N)
 {
     int gap = N/2;
     while(gap >= 1)
     {
         //把距离为gap的元素编为一组，扫描所有组
         for (int i = gap; i < N; i++) {
             int j = i - gap;
             T temp = data[i];
             
             while (j >= 0 && data[j] > temp) {
                 data[j + gap] = data[j];
                 j = j - gap;
             }
             
             if (j != i - gap) {
                 data[j + gap] = temp;
             }
         }
         gap /= 2;
     }
 }

/*
 time:O(n)
 space:O(n + m)
 stable:yes
 ref:http://hxraid.iteye.com/blog/647759
 apply:适合元素范围并不大的情况
 */
 template<typename T>
 void Sort::bucket_sort(T *data, int N, int bucket_size)
 {
     typedef node<T> Node;
     Node** bucket_table = new Node*[bucket_size];
     //Node** bucket_table = (Node **)malloc(bucket_size*sizeof(Node*));
     for (int i = 0; i < bucket_size; i++) {
         //bucket_table[i] = (Node*)malloc(sizeof(Node));
         bucket_table[i] = new Node();
         bucket_table[i]->key = 0;
         bucket_table[i]->next = NULL;
     }
     for(int i = 0;i < N ;i++)
     {
         //Node* nd = (Node*)malloc(sizeof(Node));
         Node* nd = new Node();
         nd->key = data[i];
         nd->next = NULL;
         //映射函数计算桶号
         int index = data[i]/bucket_size;
         //初始化P为桶中数据链表的头指针
         Node* p = bucket_table[index];
         if (p->key == 0) {
             bucket_table[index]->next = nd;
             (bucket_table[index]->key)++;
         }else{
             while (p->next!=NULL&&p->next->key <= nd->key) {
                 p = p->next;
             }
             nd->next = p->next;
             p->next = nd;
             (bucket_table[index]->key)++;
         }
     }
     int t = 0;
     for (int i=0; i < bucket_size; i++) {
         for(Node* k=bucket_table[i]->next; k != NULL; k = k->next)
         {
             data[t++] = k->key;
         }
     }
     for (int i = 0 ; i < bucket_size; i++) {
         delete[] bucket_table[i];
     }
     delete[] bucket_table;
 }


/*********************private********************************/
 template <typename T>
 void Sort::swap(T &a, T &b)
 {
    a = a + b;
    b = a - b;
    a = a - b;
 }

 template <typename T>
 void Sort::swap2(T &a, T &b)
 {
    a ^= b;
    b ^= a;
    a ^= b;
 }

/*
template<typename T>
void Sort::merge_array(T *data, int first, int mid, int last)
{
    int i = first, j = mid + 1;
    int k = 0;
    T* temp = new T[last - first + 1];
    while (i <= mid && j <= last) {
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        }else{
            temp[k++] = data[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = data[i++];
    }
    while (j <= last) {
        temp[k++] = data[j++];
    }
    for (int i = 0; i <= k; i++) {
        data[first + i] = temp[i];
    }
    delete[] temp;
}
*/

template<typename T>
void Sort::merge_array(T *data, int first, int mid, int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;
    T* L = new T[n1];
    T* R = new T[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = data[first + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = data[mid + i + 1];
    }
    int i,j,k;
    for (i=0, j=0, k=mid;k <= last; k++) {
        if (L[i] <= R[j]) {
            data[k] = L[i++];
        }else
        {
            data[k] = R[j++];
        }
    }
    while (i < n1) {
        data[k++] = L[i++];
    }
    while (j < n2) {
        data[k++] = R[j++];
    }
    delete[] L;
    delete[] R;
}

template<typename T>
void Sort::mergeSort(T *data, int first, int last)
{
    int mid = (int)(first + last)/2;
    if (first < last) {
        mergeSort(data, first, mid); //左边有序
        mergeSort(data, mid + 1, last); //右边有序
        merge_array(data, first, mid, last); //两边有序合并
    }
}

template<typename T>
void Sort::build_heap(T *data, int N)
{
    for (int i = N/2; i >= 0; i--) {
        heap_adjust(data, i, N);
    }
}

template<typename T>
void Sort::heap_adjust(T *data, int node, int N)
{
    int lchild = 2*node;
    int rchild = 2*node + 1;
    int max = node;
    if (node <= N/2) {
        if (lchild <= N && data[lchild] > data[max]) {
            max = lchild;
        }
        if (rchild <= N && data[rchild] > data[max]) {
            max = rchild;
        }
        if (max != node) {
            swap(data[node], data[max]);
            heap_adjust(data, max, N);
        }
    }
}
#endif /* CommonSort_h */
