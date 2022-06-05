#define BOOST_TEST_MODULE MyTest
#include<list.hpp>
#include<entity.hpp>
#include <boost/test/unit_test.hpp>

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
    types::dynamic_array<educational_institution> arr1  ,arr2;
    arr1.push_back({true,"123",123,{"",""},educational_institution::SHIFT_DATE::FIRST});
    std::ofstream ofs("1");
    save_data(&arr1[0],arr1.len(),ofs);
    ofs.close();
    std::ifstream ifs("1");
    std::unique_ptr<educational_institution> ptr (load_data<educational_institution>(arr1.len(),ifs));
    arr2.push_back(*ptr);
    ifs.close();
    BOOST_ASSERT(arr1[0].count == arr2[0].count);
}
BOOST_AUTO_TEST_CASE(third)
{
    educational_institution a = {.count = 15},b = {.count = 30},c {.count = 15};
    BOOST_ASSERT(a == c);
    BOOST_ASSERT(a != b);
}