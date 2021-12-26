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

    class SkillAlreadyLearned : public Exception 
    {
        public:
            explicit SkillAlreadyLearned() = default;
    };
    class CanNotLearnSkill : public Exception 
    {
        public:
            explicit CanNotLearnSkill() = default;
    };
    class DidNotLearnSkill : public Exception 
    {
        public:
            explicit DidNotLearnSkill() = default;
    };

    class EmployeeAlreadyHired : public Exception
    {
        public:
            explicit EmployeeAlreadyHired() = default;
    };
    class EmployeeNotHired : public Exception
    {
        public:
            explicit EmployeeNotHired() = default;
    };
}

#endif /* EXCEPTIONS_H_ */