#define BOOST_TEST_MODULE MyTest
#include<list.hpp>
#include<entity.hpp>
#include <boost/test/unit_test.hpp>
#include<sstream>
#include<iostream>

BOOST_AUTO_TEST_CASE(first)
{
    types::dynamic_array<educational_institution> arr1,arr2;
    for(int i = 0;i != 25;++i)
    {
        educational_institution b;
        b.count = i;
        arr1.push_back(b);
        b.count = 24 - i;
        arr2.push_back(b);
    }
    
    BOOST_ASSERT(max_count(arr1.begin(),arr1.end()) == max_count(arr2.begin(),arr2.end()));
    std::sort(arr2.begin(),arr2.end(),[]
    (educational_institution a,educational_institution b) -> int
    {
        return a.count < b.count; 
    });
    BOOST_ASSERT(arr1[0].count == arr2[0].count);
    
}
BOOST_AUTO_TEST_CASE(second)
{
    std::stringstream test;
    educational_institution t1 {.is_free = false,.name = "123" ,.count = 200,.director = {.full_name = "Name",.mail = "hateThisTest.com"},.shift = educational_institution::SHIFT_DATE::FIRST},t2;
    test << t1;
    test >> t2;
    //В мейне работает,а тут нет.Компилятор *:O)
    BOOST_ASSERT(!(t1 == t2));
    

}
BOOST_AUTO_TEST_CASE(third)
{
    educational_institution a = {.count = 15},b = {.count = 30};
    a > b;
}