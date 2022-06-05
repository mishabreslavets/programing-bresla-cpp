#include "entity.hpp"
namespace std
{
std::string to_string(const educational_institution& ei)
{
    using namespace std::literals;
    using SHIFT_DATA = educational_institution::SHIFT_DATE;
    auto f = [](SHIFT_DATA shift) -> std::string_view
    {
        switch (shift)
        {
        case SHIFT_DATA::FIRST:
        return std::string_view("first");
        break;
        case SHIFT_DATA::FIRST_LATE:
        return std::string_view("first late");
        break;
        case SHIFT_DATA::SECOND:
        return std::string_view("second");
        break;
        case SHIFT_DATA::NONE:
        return std::string_view("none");
        break;
        default:
        return "";
        break;
        }
    };
    return " "s + ((ei.is_free == true)?"true ":"false ") + ei.name.data() + " " +ei.director.full_name.data() + " " + ei.director.mail.data() + f(ei.shift).data();
}
}
std::ostream& operator<<(std::ostream& os, const types::dynamic_array<educational_institution>& arr)
{
    for(auto i:arr)
    {
        os<<i.is_free<<i.name<<i.count<<i.director.full_name<<i.director.mail<<(short&)i.shift;
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const educational_institution& i)
{
    os<<i.is_free<<' '<<i.name<<' '<<i.count<<' '<<i.director.full_name<<' '<<i.director.mail<<' '<<(short)i.shift;
    return os;
}
std::istream& operator>>(std::istream& is,educational_institution& i)
{
    is>>i.is_free>>i.name>>i.count>>i.director.full_name>>i.director.mail>>(short&)i.shift;
    return is;
}