//
//  main.cpp
//  sort
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <time.h>
#include "CommonSort.h"
#include "CommonLink.h"
#include "CommonString.h"

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    
    Sort *s = new Sort();
    const int N = 10;
    int *data = new int[N];
    for (int i =0 ; i< N; i++) {
        data[i] = (int)((1000.0*rand()/(float)RAND_MAX) + 1);
    }
    
    //clock_t start,finish;
    //s->bubble_sort<double>(data, N);
    
    //s->insert_sort(data, N);
    
    //s->select_sort(data, N);
    
    //s->quick_sort(data, 0, N);
    
    //s->merge_sort(data, N);
    
    //s->heap_sort(data, N);
    
    //s->shell_sort(data, N);
    
    //s->bucket_sort(data, N, 1000);
    
    /*
    double* a = new double[4];
    a[0] = 10.44;
    a[1] = 15.11;
    a[2] = 20.99;
    a[3] = 19.88;
    s->merge_array(a, 0, 2, 3);
    for(int i=0 ;i < N;i++)
    {
        cout<<i<<":"<<data[i]<<endl;
    }
    
    
    List* l = new List();
    Node* head = l->create_list(data, N);
    l->print_list(head);
    cout<<"-------------------"<<endl;
    //head = l->del_node(head, 675);
    head=l->select_sort(head);
    l->print_list(head);
     */
    char* pStr = "I am a boy";
    String* str = new String();
    char* temp =str->to_string(12345);
    cout<<temp<<endl;
}
