#include<string>
#include<utility>
#include<iostream>
#include<string_view>
#include<type_traits>
#include<fstream>
struct educational_institution 
{
    struct director_data
    {
        std::string full_name;
        std::string mail;
        director_data& operator=(const director_data&) = default;
        auto operator<=>(const director_data&) const = default;
    };
    enum class SHIFT_DATE
    {
        FIRST,
        FIRST_LATE,
        SECOND,
        NONE
    };
    bool is_free;
    std::string name;
    size_t count;
    director_data director;
    SHIFT_DATE shift;
    auto operator<=>(const educational_institution&) const = default;
    educational_institution& operator=(const educational_institution&)= default;
};
namespace std
{
std::string to_string(const educational_institution&);
}
template<typename T>
void save_data(T* data,size_t len,std::ofstream &ofs)
{
    ofs<<educational_institution;
}
template<typename T>
T* load_data(size_t len,std::ifstream &ifs)
{
    ifs>>educational_institution;
}

template<typename T1>
uint32_t max_count(T1 begin,T1 end)
{
    uint32_t b;
    for(auto i = begin;i!= end;++i)
    {
        if(i->count > b)
            b = i->count;           
    }
    return b;
}