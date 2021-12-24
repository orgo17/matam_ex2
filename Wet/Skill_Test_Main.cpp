#include <iostream>
#include "Skill.h"
#include <cassert>
#include "exceptions.h"

using std::cout;
using mtm::Skill;

int main() {
    Skill s1(1, "C++", 0, 10);
    Skill s2(2, "C", 5, 1);
    s2++;
    assert(s2.getRequiredPoints() == 6);
    Skill s3 = s1+1;
    assert(s3.getRequiredPoints() == 1);
    s1+=2;
    assert(s1.getRequiredPoints() == 2);
    Skill s4 = 1+s2;
    assert(s4.getRequiredPoints() == 7);
    assert(s1.getName() == "C++");
    assert(s2.getId() == 2);
    assert(s1<s2);
    assert(s1==s3);
    assert(s1!=s2);
    assert(s2>s3);
    assert(s1<=s2);
    assert(s2>=s3);
    try{
        s1+= -5;
    }
    catch(mtm::NegativePoints& e){
        cout << "Negative Points" << std::endl;
    }
    try{
        s1 + (-5);
    }
    catch(mtm::NegativePoints& e){
        cout << "Negative Points" << std::endl;
    }
    try{
        (-5) + s2;
    }
    catch(mtm::NegativePoints& e){
        cout << "Negative Points" << std::endl;
    }
    cout << s1 << std::endl;
    cout << s2 << std::endl;
    return 0;
}