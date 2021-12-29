#include <iostream>
#include "../Employee.h"
#include <cassert>
#include "../exceptions.h"

using std::cout;
using mtm::Employee;
using mtm::Skill;

int main()
{
    Employee e1(1, "Yuval", "Lande", 1999);
    Employee e2(2, "Orr", "Gonen", 2010);
    Employee e3 = e1;
    assert(e3 == e1);
    assert(e2 > e1);
    assert(e1 != e2);
    assert(e1 < e2);
    assert(e1 >= e3);
    assert(e1 <= e2);
    assert(e1.getId() == 1);
    assert(e1.getFirstName() == "Yuval");
    assert(e1.getLastName() == "Lande");
    assert(e1.getBirthYear() == 1999);
    assert(e1.getSalary() == 0);
    assert(e1.getScore() == 0);
    e1.setSalary(10);
    assert(e1.getSalary() == 10);
    e2.setScore(13);
    assert(e2.getScore() == 13);
    Skill s1(1, "C++", 0, 10);
    Skill s2(2, "C", 5, 1);
    Skill s3(3, "Python", 10, 5);
    e1.setScore(10);
    try{
        e1.learnSkill(s1);
        e1.learnSkill(s3);
    }
    catch(...){
        assert(false);
    }
    try{
        e1.learnSkill(s1);
    }
    catch(mtm::Exception& e){
        assert(typeid(e).name() == typeid(mtm::SkillAlreadyLearned).name());
    }
    e1.setScore(-20);
    try{
        e1.learnSkill(s2);
    }
    catch(mtm::Exception& e){
        assert(typeid(e).name() == typeid(mtm::CanNotLearnSkill).name());
    }
    try{
        e1.forgetSkill(2);
    }
    catch(mtm::Exception& e){
        assert(typeid(e).name() == typeid(mtm::DidNotLearnSkill).name());
    }
    e1.forgetSkill(3);
    assert(!e1.hasSkill(3));
    assert(!e1.hasSkill(5));

    e2.learnSkill(s1);
    e2.learnSkill(s2);
    Employee* e4 = e2.clone();
    assert((*e4).getBirthYear() == 2010);
    assert((*e4).hasSkill(2));
    e1.printShort(cout);
    e1.printLong(cout);
    e2.printShort(cout);
    e2.printLong(cout);
    
    delete e4;
    
    return 0;
}