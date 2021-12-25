#include "Employee.h"
#include "exceptions.h"

using mtm::Employee;

namespace mtm
{
    Employee::Employee(const unsigned int id, const string first_name, const string last_name, const int birth_year):
            Citizen(id, first_name, last_name, birth_year), salary(0), score(0), skill_set()
    {

    }
    
    int Employee::getSalary() const
    {
        return salary;
    }
    int Employee::getScore() const
    {
        return score;
    }
    void Employee::setSalary(const int salary_to_add)
    {
        salary += salary_to_add;
    }
    void Employee::setScore(const int score_to_add)
    {
        score += score_to_add;
    }
    
    void Employee::learnSkill(const Skill& skill_to_learn)
    {
        if(skill_set.find(skill_to_learn) != skill_set.end()){
            throw mtm::SkillAlreadyLearned();
        }
        if(score < skill_to_learn.getRequiredPoints()){
            throw mtm::CanNotLearnSkill();
        }
        skill_set.insert(skill_to_learn);
    }
    
    void Employee::forgetSkill(const unsigned int skill_id)
    {
        for (Skill skill : skill_set)
        {
            if(skill.getId() == skill_id){
                skill_set.erase(skill);
                return;
            }
        }
        throw mtm::DidNotLearnSkill();    
    }
    
    bool Employee::hasSkill(const unsigned int skill_id) const
    {
        for (Skill skill : skill_set)
        {
            if(skill.getId() == skill_id){
                return true;
            }
        }
        return false;
    }

    std::ostream& Employee::printShort(std::ostream& os) const
    {
        os << first_name << " " << last_name << "\n";
        os << "Salary: " << salary << " Score: " << score << "\n";
        return os;
    }
    std::ostream& Employee::printLong(std::ostream& os) const
    {
        os << first_name << " " << last_name << "\n";
        os << "id - " << id << " birth_year - " << birth_year << "\n";
        os << "Salary: " << salary << " Score: " << score << " Skills: \n";
        for (Skill skill : skill_set)
        {
            os << skill.getName() << "\n";
        }
        return os;
    }
    
    Employee* Employee::clone() const
    {
        return new Employee(*this);
    }
}