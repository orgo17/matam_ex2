#ifndef FACULTY_H_
#define FACULTY_H_

// #include <string>
// #include <iostream>
#include "Skill.h"
#include "Citizen.h"
#include "Employee.h"



namespace mtm {
    class Faculty {
        private:
            const unsigned int id;
            bool (*admissionCondition)(Employee employee);
            const Skill skill;
            const unsigned int add_points;
        public:
            //c'tors and d'tor
            Faculty(const unsigned int id, bool (*admissionCondition)(Employee employee), const Skill skill,
                        const unsigned int add_points);
            ~Faculty() = default;
            Faculty (const Faculty& faculty) = default;
            
            //getters and setters
            int getId() const;
            Skill getSkill() const;
            int getAddedPoints() const;
            
            void teach(Employee* employee);
    };
}

#endif /* FACULTY_H_ */