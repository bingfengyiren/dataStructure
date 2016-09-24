//
//  CommonString.cpp
//  myproject
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "CommonString.h"

String::String()
{
    
}
String::~String()
{
    
}

void String::loop_move(char *pStr, int steps)
{
    
}

char* String::reverse(char *pStr)
{
    const size_t length = strlen(pStr);
    char* temp = new char[length];
    strcpy(temp, pStr);
    for (int i=0; i < length/2; i++) {
        char c = temp[i];
        temp[i] = temp[length - i - 1];
        temp[length - i - 1] = c;
    }
    return temp;
}

char* String::to_string(int n)
{
    int num = 12345;
    char str[7];
    
    
    cout<<str<<endl;
}