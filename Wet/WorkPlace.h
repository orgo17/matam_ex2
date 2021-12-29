#ifndef WORKPLACE_H_
#define WORKPLACE_H_

#include "Employee.h"
#include "Manager.h"

using mtm::Manager;
using mtm::Employee;
using std::string;

namespace mtm
{
    class WorkPlace
    {
        private:
            const unsigned int id;
            const string name;
            const unsigned int workers_salary;
            const unsigned int managers_salary;
            set<Manager*> managers;
        public:

            //c'tors and d'tor
            WorkPlace(const unsigned int id, const string name, 
                    const unsigned int workers_salary,const unsigned int managers_salary);
            ~WorkPlace() = default;
            WorkPlace(const WorkPlace& workplace) = default;

            //getters
            int getID() const;
            string getName() const;
            int getWorkersSalary() const;
            int getManagersSalary() const;

            //employee methods
            template <class Condition>
            void hireEmployee(const Condition& condition, 
                            Employee* const employee_to_hire, 
                            const unsigned int manager_id);
            void fireEmployee(const unsigned int employee_id, const unsigned int manager_id);

            //manager methods
            void hireManager(Manager* const manager_to_hire);
            void fireManager(const unsigned int manager_id_to_fire);

            friend ostream& operator<<(ostream& os, const WorkPlace& workplace);
    };
}

#endif /* WORKPLACE_H_ */