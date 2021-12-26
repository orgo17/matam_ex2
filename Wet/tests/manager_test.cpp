#include <iostream>
// #include "../Employee.h"
#include <cassert>
#include "../exceptions.h"
#include "../Manager.h"

using std::cout;
using mtm::Employee;
// using mtm::Skill;
using mtm::Manager;
using std::endl;

int main()
{
    Employee e1(1, "John", "Williams", 2002);
    Employee e2(2, "Alex", "Martinez", 2000);
    Manager m1(1,"Robert", "stark", 1980);
    m1.addEmployee(&e1);
    m1.addEmployee(&e2);
    try{
        m1.addEmployee(&e1);
    }
    catch(mtm::Exception& e){
        assert(typeid(e).name() == typeid(mtm::EmployeeAlreadyHired).name());
    }
    m1.removeEmployee(e1.getId());
    try{
        m1.removeEmployee(e1.getId());
    }
    catch(mtm::Exception& e){
        assert(typeid(e).name() == typeid(mtm::EmployeeNotHired).name());
    }
    cout << "Short_Print" << endl;
    m1.printShort(cout);
    cout << "Long Print" << endl;
    m1.printLong(cout);
    return 0;
}