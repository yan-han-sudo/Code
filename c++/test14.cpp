#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

void printStu1(Student stu1)
{
    stu1.age = 100;
    cout<<stu1.name<<" "<<stu1.age<<" "<<stu1.score<<endl;
}

void printStu2(Student * stu2)
{
    stu2->age = 10000;
    cout<<stu2->name<<" "<<stu2->age<<" "<<stu2->score<<endl;
}

int main()
{
    Student stu;
    stu.name = "小明";
    stu.age = 18;
    stu.score = 639.5;    
    printStu1(stu);
    printStu2(&stu);
    cout<<stu.name<<" "<<stu.age<<" "<<stu.score<<endl;
    return 0;
}