#include "Workplace.h"
#include "exceptions.h"

using mtm::Workplace;

namespace mtm
{
    Workplace::Workplace(const unsigned int id, const string name, 
                    const unsigned int workers_salary,const unsigned int managers_salary):
                    id(id), name(name), workers_salary(workers_salary), managers_salary(managers_salary), managers()
    {
        
    }
    
    int Workplace::getID() const
    {
        return id;
    }

    string Workplace::getName() const
    {
        return name;
    }

    int Workplace::getWorkersSalary() const
    {
        return workers_salary;
    }

    int Workplace::getManagersSalary() const
    {
        return managers_salary;
    }

    static Manager* findManagerById(std::set<Manager*> managers, const unsigned int manager_id)
    {
        for(Manager* manager : managers){
            if(manager->getId() == manager_id){
                return manager;
            }
        }
        return NULL;
    }

    static bool isManagerInWorkplace(std::set<Manager*> managers, const unsigned int manager_id)
    {
        if(findManagerById(managers, manager_id) != NULL){
            return true;
        }
        return false;
    }
    
    template <class Condition>
    void Workplace::hireEmployee(const Condition condition, 
                    Employee* const employee_to_hire, 
                    const unsigned int manager_id)
    {
        if(!Condition(employee_to_hire)){
            throw mtm::EmployeeNotSelected();
        }
        if(!isManagerInWorkplace(managers, manager_id)){
            throw mtm::ManagerIsNotHired();
        }
        Manager* manager_of_employee = findManagerById(managers, manager_id);
        manager_of_employee->addEmployee(employee_to_hire);
    }
}