//
//  main.cpp
//  XorDouble
//
//  Created by Shaun Choe on 9/11/13.
//  Copyright (c) 2013 Shaun Choe. All rights reserved.
//

#include <iostream>
#include <cassert>

static long long g_Key = 0;
double xorDouble(double val) {
    assert(sizeof(double) == sizeof(long long));
    union {
        double x;
        long long i;
    } convert;
    
    convert.x = val;
    convert.i ^= g_Key;
    
    return convert.x;
}


int main(int argc, const char * argv[])
{
    srand(static_cast<int>(time(NULL)));
    
    long long count = 0;
    while (1) {
        g_Key = static_cast<long long>(lrand48());
        
        const double old = lrand48() / static_cast<double>(lrand48()+1);
        const double result = xorDouble(xorDouble(old));
        
        assert(result == old);
        
        std::cout << count << " : " << old << std::endl;
        ++count;
    }
    
    return 0;
}

