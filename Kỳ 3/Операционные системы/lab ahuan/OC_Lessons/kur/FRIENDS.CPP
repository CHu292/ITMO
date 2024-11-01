#include "friends.h"
#include<iostream>

void report(char *s){
    std::cout << s << std::endl;
    extern ListBox *ptr;
    ptr->Add(s);
}
