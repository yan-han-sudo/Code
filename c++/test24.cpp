#include <iostream>
#include <string>
using namespace std;

class person
{
private:
    string m_name;
    string m_idol;
    int m_age = 18;
    bool ageRange;

public:
    void setName(string name)
    {
        m_name = name;
    }

    string getName()
    {
        return m_name;
    }

    int getAge()
    {
        if(ageRange == true)
            return m_age;
        else
            return 0;
    }

    void setIdol(string idol)
    {
        m_idol = idol;
    }

    void setAge(int age)
    {
        if(age>0&&age<150)
        {
            m_age = age;
            ageRange = true;
        }
        else
        {
            cout<<"Age setting failed!!!"<<endl;
            ageRange = false;
        }  
    }
};

int main()
{
    person per;
    per.setName("小明");
    per.setIdol("大明");
    per.setAge(170);
    cout<<per.getName()<<endl;
    cout<<per.getAge()<<endl;
    return 0;
}