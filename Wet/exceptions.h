#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <string>

using std::string;
using std::exception;

namespace mtm
{
    class Exception : public exception
    {
        public:
            Exception() = default;
            virtual ~Exception() = default;
    };

    class NegativePoints : public Exception 
    {
        public:
            explicit NegativePoints() = default;
    };
}

#endif /* EXCEPTIONS_H_ */