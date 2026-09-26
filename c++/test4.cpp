#include <iostream>
using namespace std;

class log
{
public:
    const int error = 0;
    const int warning = 1;
    const int info = 2;
private:
    int m_logLevel = info; //默认logLevel
public:
    void setLevel(int level)
    {
        m_logLevel = level;
    }

    void Error(const char* message)
    {
        if (m_logLevel >= error)
            cout<<"[ERROR:]"<<message<<endl;
    }
    void Warn(const char* message)
    {
        if (m_logLevel >= warning)
            cout<<"[WARNING:]"<<message<<endl;
    }
    void Info(const char* message)
    {
        if (m_logLevel >= info)
            cout<<"[INFO:]"<<message<<endl;
    }

};

int main()
{
    log lg;
    lg.setLevel(lg.info);
    lg.Error("Dangerous!");
    lg.Warn("Carefull!");
    lg.Info("Safe!");
    return 0;
}