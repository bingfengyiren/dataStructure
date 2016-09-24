//
//  CommonHash.hpp
//  myproject
//
//  Created by cuiming on 16/9/16.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#ifndef CommonHash_h
#define CommonHash_h

#include <stdio.h>
#include <iostream>
#include <string>
/*
 *常见的hash函数
 1、除法散列法
 2、平方散列法
 3、裴波那切散列法
 *冲突解决办法
 1、开放地址法
    h ：= (h(key)+d) mod m
    m:为哈希表的长度
    d：产生冲突时候的增量序列
        线性探测再散列：d为1，2，3...,m -1
        二次探测散列：1，-1，2，-2，4，-4...,m/2*m/2
        伪随机散列：伪随机数列
 2、再哈希法
 3、链地址法
 4、建立公共溢出区
 */

using namespace std;

struct yk_hash_key{
    struct yk_struct_key *next;
};

struct yk_hash_counter_entry{
    unsigned int hit_count;
    unsigned int entry_count;
    yk_hash_key * keys;
};

class Hash
{
public:
    Hash();
    ~Hash();
    
    void hash_init();
    
};

Hash::Hash()
{
    
}

Hash::~Hash()
{
    
}

void Hash::hash_init()
{
    int i;
    int backet_len = 131313;
    int hash_call_count = 0;
    hlist = (yk_hash_counter_entry*)malloc(sizeof(yk_hash_counter_entry)*backet_len);
    if (nullptr == hlist) {
        perror("malloc in hash_init");
        return;
    }
}

#endif /* CommonHash_hpp */
