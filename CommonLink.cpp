//
//  CommonLink.cpp
//  myproject
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#include "CommonLink.h"

List::List()
{
    
}
List::~List()
{
    
}

Node* List::create_node(int data)
{
    Node* n = new Node();
    if(n == NULL)
    {
        return NULL;
    }else{
        n->data = data;
        n->next = NULL;
        return n;
    }
}

Node* List::create_list(int* data,int N)
{
    Node* head = NULL;
    Node* p1 = NULL;
    Node* p2 = NULL;
    
    if(N == 0)
    {
        return head;
    }
    
    head = create_node(data[0]);
    
    for (int i = 0; i < N; i++) {
        if(i == 0)
        {
            p1 = head;
            continue;
        }
        p2 = create_node(data[i]);
        p1->next = p2;
        p1 = p2;
    }
    return head;
}

void List::print_list(Node *head)
{
    if (head == NULL) {
        return;
    }
    Node* p1 = head;
    while(p1 != NULL)
    {
        cout<<p1->data<<endl;
        p1 = p1->next;
    }
}

Node* List::del_node(Node *head, int num)
{
    Node* p1 = NULL;
    Node* p2 = NULL;
    if (head == NULL) {
        return head;
    }
    //定位要删除的节点
    p1 = head;
    while (p1->data != num and p1->next != NULL) {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1->data == num) {
        if(p1 == head)
        {
            head = p1->next;
        }else{
            p2->next = p1->next;
        }
        cout<<"del:"<<num<<endl;
    }
    delete p1;
    delete p2;
    return head;
}

Node* List::insert_node(Node *head, int num, Node *node)
{
    if(head == NULL)
    {
        head = node;
        node->next= NULL;
        return head;
    }
    
    Node* p1 = head;
    while (p1->data != num && p1->next != NULL) {
        p1 = p1->next;
    }
    if (p1->data == num) {
        node->next = p1->next;
        p1->next = node;
    }
    return head;
}

Node* List::inverse(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* p;
    Node* p1;
    Node* p2;
    
    p1 = NULL;
    p2=head;
    while (p2 != NULL) {
        p = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p;
    }
    head = p1;
    return head;
}

Node* List::clone(Node *head)
{
    Node *pNode = head;
    Node *pCloneHead = NULL,*pCloneNode = NULL;
    if (pNode != NULL) {
        pCloneHead = new Node();
        pCloneHead->data = pNode->data;
        pCloneHead->next = NULL;
        pCloneNode = pCloneHead;
        pNode = pNode->next;
    }
    while (pNode != NULL) {
        Node* new_node = new Node();
        new_node->data = pNode->data;
        new_node->next = NULL;
        pCloneNode->next=new_node;
        pCloneNode=pCloneNode->next;
        pNode = pNode->next;
    }
    return pCloneHead;
}

Node* List::select_sort(Node *head)
{
    Node *first = NULL;
    Node *tail = NULL;
    Node *p_min = NULL;
    Node *min = NULL;
    Node *p = NULL;
    
    while (head != NULL) {
        for (p = head,min = head;p->next != NULL; p = p->next) {
            if (p->next->data < min->data) {
                p_min = p;
                min = p->next;
            }
        }
        //first
        if (first == NULL) {
            first = min;
            tail = min;
        }else{
            tail->next = min;
            tail = min;
        }
        //second
        if (min == head) {
            head = head->next;
        }else{
            p_min->next = min->next;
        }
    }
    if (first != NULL) {
        tail->next = NULL;
    }
    head = first;
    return head;
}

Node* List::bubble_sort(Node *head)
{
    return NULL;
}