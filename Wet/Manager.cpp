#include "Manager.h"
#include "exceptions.h"

#define INIT_VALUE 0

using mtm::Manager;
using std::pair;
using std::set;

namespace mtm
{
    Manager::Manager(const unsigned int id, const string first_name, const string last_name, const int birth_year):
            Citizen(id, first_name, last_name, birth_year), salary(INIT_VALUE), employees()
    {

    }

    int Manager::getSalary() const
    {
        return salary;
    }
    
    void Manager::setSalary(const int salary_to_add)
    {
        salary += salary_to_add;
        if(salary < 0){
            salary = 0;
        }
    }
    
    void Manager::addEmployee(Employee* const employee_to_add)
    {
        if(employees.find(employee_to_add) != employees.end()){
            throw mtm::EmployeeAlreadyHired();
        }
        employees.insert(employee_to_add);
    }

    void Manager::removeEmployee(unsigned int id_to_remove)
    {
        for (Employee* employee : employees)
        {
            if(employee->getId() == id_to_remove){
                employee->setSalary(-(employee->getSalary()));
                employees.erase(employee);
                return;
            }
        }
        throw mtm::EmployeeIsNotHired();
    }
    
    void Manager::removeAllEmployees()
    {
        for (Employee* employee : employees)
        {
            employee->setSalary(-(employee->getSalary()));
            employees.erase(employee);
        }
    }
    
    std::ostream& Manager::printShort(std::ostream& os) const
    {
        os << this->getFirstName() << " " << this->getLastName() << "\n";
        os << "Salary: " << salary << "\n";
        return os;
    }

    std::ostream& Manager::printLong(std::ostream& os) const
    {
        os << this->getFirstName() << " " << this->getLastName() << "\n";
        os << "id - " << this->getId() << " birth_year - " << this->getBirthYear() << "\n";
        os << "Salary: " << salary << "\n";
        os << "Employees:" << "\n";
        for (Employee* employee : employees)
        {
            employee->printShort(os);
        }
        return os;
    }

    Manager* Manager::clone() const
    {
        return new Manager(*this);
    }
}
