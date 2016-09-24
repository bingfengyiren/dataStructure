//
//  CommonLink.hpp
//  myproject
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#ifndef CommonLink_h
#define CommonLink_h

#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct nd
{
    int data;
    struct nd* next;
}Node;

class List
{
public:
    List();
    ~List();
    
    Node* create_node(int data);
    Node* create_list(int* data,int N);
    void print_list(Node* head);
    Node* del_node(Node* head,int num);
    Node* insert_node(Node* head,int num,Node* node);
    Node* inverse(Node* head);
    Node* clone(Node* head);
    Node* select_sort(Node* head);
    // Node* insert_sort(Node* head);
    Node* bubble_sort(Node* head);
   // Node* sort_list_insert(Node* head,Node* node);
};

#endif /* CommonLink_hpp */
