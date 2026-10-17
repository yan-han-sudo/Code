#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

struct Teacher
{
    int id;
    string name;
    int age;
    Student stu;
};

int main()
{
    Teacher tea;
    tea.id = 1000;
    tea.name = "大明";
    tea.age = 42;
    tea.stu.name = "小明";
    tea.stu.age = 18;
    tea.stu.score = 180.3;
    cout<<tea.id<<" "<<tea.name<<" "<<tea.age<<endl
        <<tea.stu.name<<" "<<tea.stu.age<<" "<<tea.stu.score<<endl;
    return 0;
}