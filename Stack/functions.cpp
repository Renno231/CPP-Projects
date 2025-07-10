/*
Name: Renno231
Status: Completed
Description: This file contains useful functions used to perform routine tasks.
    
*/

#include "functions.h"

void rand_string(std::string *str){

    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(MAXSTRSIZE);

    for (int i = 0; i < MAXSTRSIZE; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

     *str = tmp_s;  
    
    return;
}

void rand_int(int *n){
    int r = rand()%MAX_INT_LENGTH;
    int nn = 0;
    for (int i = 0; i < r; i++){
        nn += rand()%r;
    }
    *n = nn;
}