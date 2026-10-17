#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

void printStu(const Student * s)
{
    cout<<s->name<<" "<<s->age<<" "<<s->score<<endl;
}

int main()
{
    Student stu = {"小明",18,190.5};
    printStu(&stu);
    return 0;
}