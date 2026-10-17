#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

// int main()
// {
//     Student s1;
//     s1.name = "月月";
//     s1.age = 18;
//     s1.score = 639.5;
//     cout<<s1.name<<endl;
//     return 0;
// }

// int main()
// {
//     Student stuArr[3] = 
//     {
//         {"小明",18,30},
//         {"小红",17,31},
//         {"小刚",16,32}
//     };
//     for(int i=0;i<3;i++)
//     {
//         cout<<stuArr[i].name<<" "
//             <<stuArr[i].age<<" "
//             <<stuArr[i].score<<endl;
//     }
//     return 0;
// }

int main()
{
    Student stu = {"小明",18,100};
    Student * p = &stu;
    cout<<p->name<<" "<<p->age<<" "<<p->score<<endl;
    return 0;
}