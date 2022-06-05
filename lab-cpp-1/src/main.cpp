
#include <stdlib.h>
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version 2.43
 */
#include"entity.hpp"
#include<iostream>
#include"list.hpp"
int main(int argc, char *argv[])
{
    types::dynamic_array<educational_institution> arr2;
    for(int i = 0;i != 25;++i)
    {
        educational_institution b;
        b.count = i;
        arr2.push_back(b);
    }
    std::sort(arr2.begin(),arr2.end(),[]
    (educational_institution a,educational_institution b) -> int
    {
        return a.count < b.count; 
    });
    for(auto i:arr2)
    {
        std::cout<<' '<<i.count;
    }
}