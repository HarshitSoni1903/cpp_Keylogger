#ifndef HELPER_H
#define HELPER_H

#include<ctime>
#include<string>
#include<sstream>

namespace Helper{

    template <class T>
    std::string ToString(const t &);

    struct DateTime
    {
        DateTime()
        {
            time_t ms;
            time(&ms);

            struct tm *info = localtime(ms);

            D = info->tm_mday;
            m = info->tm_mon + 1;
            y = 1900 + info->tm_year;
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }

        DateTime(int D, int m , int y, int M, int H, int S) : D(D), m(m), y(y), M(M), H(H), S(S){}
        DateTime(int D, int m , int y): D(D), m(m), y(y), M(0), H(0), S(0){}

        DateTime Now() const
        {
            return DateTime();
        }

        int D, m, y, M, H, S;

        std::string GetDateString() const{
            return std::string( D < 10 ? "0":"") + ToString(D) +
            std::string( m < 10 ? ".0":".") + ToString(m) +
             "." +  ToString(y);
        }

        std::string GetTimeString() const{
            return std::string( H < 10 ? "0":"") + ToString(H) +
            std::string( M < 10 ? ":0":":") + ToString(M) + ":" +
            std::string( S < 10 ? ":0":":") + ToString(S);
        }

        std::string GetDateTimeString() const{
            return GetDateString() + " " + GetTimeString();
        }
    };
template<class T>
std::string ToString(const T &e){
    std::ostringstream s;
    s << e;
    return s.str();
}
}

#endif // HELPER_H
