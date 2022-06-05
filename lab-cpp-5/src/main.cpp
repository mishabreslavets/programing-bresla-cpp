
#include <stdlib.h>
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version 4.23
 */
#include"entity.hpp"
#include"list.hpp"
#include<sstream>
#include<iostream>
int main(int argc, char *argv[])
{
    std::stringstream test;
    educational_institution t1 {.is_free = false,.name = "123" ,.count = 200,.director = {.full_name = "Name",.mail = "hateThisTest.com"},.shift = educational_institution::SHIFT_DATE::FIRST},t2;
    test << t1;
    test >> t2;
    std::cout<< (t1 == t2);
    
}