#include <memory>
#include <concepts>
#include <utility>
#include <initializer_list>
#include <span>
#pragma once
#define _inc(x) inline x const noexcept
#define _ic(x) inline x const
#define _in(x) inline x noexcept
#define _i(x) inline x
#define tn typename
namespace types
{
    template <tn T, std::integral dist = size_t>
    class dynamic_array
    {
        T *data;
        dist _l, _cap;

    public:
        _inc(T& operator[](const dist i))
        {
            return data[i];
        }
        _inc(auto begin())
        {
            return std::span<T>(data, _cap).begin();
        }
        _inc(auto end())
        {
            return std::span<T>(data, _cap).begin() + _cap;
        }
        _inc(auto cbegin())
        {
            return std::span<const T>(data, _cap).begin();
        }
        _inc(auto cend())
        {
            return std::span<const T>(data, _cap).begin() + _cap;
        }
        _inc(auto rbegin())
        {
            return std::span<T>(data, _cap).rbegin();
        }
        _inc(auto rend())
        {
            return std::span<T>(data, _cap).rbegin() + _cap;
        }
        _inc(auto crbegin())
        {
            return std::span<const T>(data, _cap).rbegin();
        }
        _inc(auto crend())
        {
            return std::span<const T>(data, _cap).rbegin() + _cap;
        }
        dynamic_array(dist size = 1) : data(new T[size]), _l(size), _cap(0) { ; }
        dynamic_array(std::initializer_list<T> l) : _cap(l.size())
        {
            _l = l.size() * 1.5;
            data = new T[_l];
            std::move(l.begin(), l.end(), data);
        }
        virtual ~dynamic_array()
        {
            if (!data)
                delete[] data;
        }
        _i(void resize(const dist len))
        {
            _l = len;
            T *b = new T[_l];
            std::move(data, data + _cap, b);
            if (!data)
                delete[] data;
            data = b;
        }
        _i(void insert(const T elem, const dist index))
        {
            if (_l < _cap + 1)
                resize((_l + 1) * 2);
            std::move(data + index, data + _cap++, data + index + 1);
            data[index] = elem;
        }
        _i(void push_back(const T elem))
        {
            insert(elem, _cap);
        }
        _i(void remove(const dist index))
        {
            std::move(data + index + 1, data + _cap, data + index);
            --_cap;
        }
        _i(void pop_back())
        {
            remove(_cap - 1);
        }
        _inc(dist len())
        {
            return _cap;        
        }
    };
}
#undef _inc
#undef _i
#undef _ic
#undef _in