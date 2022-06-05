#define BOOST_TEST_MODULE MyTest
#include<list.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(first)
{
    types::dynamic_array<int> a;
    types::dynamic_array<int> b;
    for(int i = 25;i != 0;--i)
    {
        a.push_back(25 - i);
        b.push_back(i);
    }
    std::sort(a.begin(),a.end());
    std::find(a.begin(),a.end(),5);
    std::min_element(a.begin(),a.end());
    BOOST_ASSERT(true);
}
