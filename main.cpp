#include <tuple>
#include <utility>
#include <iostream>

#define LOG if (::logger::m_level == ::logger::level::VERBOSE) std::puts(__PRETTY_FUNCTION__);

namespace logger
{
    enum class level
    {
        NONE = 0, VERBOSE = 1
    };
    static ::logger::level m_level = ::logger::level::NONE;
}

// https://stackoverflow.com/a/6894436/2794395
template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type print(std::tuple<Tp...> &t)
{
    LOG;
}

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type print(std::tuple<Tp...> &t)
{
    LOG;
    std::cout << std::get<I>(t) << std::endl;
    print<I + 1, Tp...>(t);
}

int main()
{
    LOG;
    typedef std::tuple<int, float, double> T;
    T t = std::make_tuple(2, 3.14159F, 2345.678);

    print(t);
}