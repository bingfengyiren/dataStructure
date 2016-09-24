//
//  CommonString.h
//  myproject
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#ifndef CommonString_h
#define CommonString_h

#include <string>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    String();
    ~String();
    
    //将一个字符串循环右移n位
    void loop_move(char* pStr,int steps);
    //字符串的反转
    char* reverse(char* pStr);
    //convert int to char
    char* to_string(int n);
};

#endif /* CommonString_h */
