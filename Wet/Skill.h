#ifndef SKILL_H_
#define SKILL_H_

#include <string>
#include <iostream>

using std::string;
using std::ostream;

namespace mtm
{
    class Skill 
    {
        private:
            const unsigned int id;
            const string name;
            unsigned int required_points;
            const unsigned int level;
        
        public:
            //c'tors and d'tor
            Skill(const unsigned int id, const string name, unsigned int required_points, const unsigned int level);
            ~Skill() = default;
            Skill(const Skill& skill) = default;
            
            //getters
            int getId() const;
            string getName() const;
            int getRequiredPoints() const;

            //overloaded operators
            Skill operator++(int);
            Skill& operator+=(int add);
            friend ostream& operator<<(ostream& os, const Skill& skill);
    };

    bool operator==(const Skill& skill_1, const Skill& skill_2);
    bool operator<(const Skill& skill_1, const Skill& skill_2);
    bool operator>(const Skill& skill_1, const Skill& skill_2);
    bool operator<=(const Skill& skill_1, const Skill& skill_2);
    bool operator>=(const Skill& skill_1, const Skill& skill_2);
    bool operator!=(const Skill& skill_1, const Skill& skill_2);
    Skill operator+(const Skill& skill ,int add);
    Skill operator+(int add, const Skill& skill);
}

#endif /* SKILL_H_ */


