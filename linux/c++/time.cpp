#include<iostream>
#include<ctime>
#include<iomanip>
#include<unistd.h>
using namespace std;

class Clock
{
private:
    int m_hour;
    int m_min;
    int m_sec;
public:
    Clock(void);
    ~Clock(void);

    void tick(void)
    {
        sleep(1);
        if(60 == ++m_sec)
        {
            m_sec = 0;
            if(60 == ++m_min)
            {
                m_min = 0;
                if(24 == ++m_hour)
                {
                    m_hour = 0;
                }
            }
        }
    }

    void show(void)
    {
        cout << '\r' << setfill('0') << setw(2) << m_hour << ":" << setw(2) << m_min << ":" << setw(2) << m_sec << flush;
    }

    void run(void)
    {
        while(1)
        {
            tick();
            show();
        }
    }
};

Clock::Clock(void)
{
    time_t t = time(0);
    struct tm* pt = localtime(&t);
    m_hour = pt->tm_hour;
    m_min = pt->tm_min;
    m_sec = pt->tm_sec;
}

Clock::~Clock(void)
{
}

int main(void)
{
    Clock c;
    c.run();
    return 0;
}