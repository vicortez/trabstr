#ifndef PROCESSADOR_H
#define PROCESSADOR_H
#include <string>

using namespace std;

class Processador
{
private:
    string cpu;
    float user;
    float nice;
    float System;
    float idle;
    float iowait;
    float irq;
    float softirq;
    float steal;
    float cpu_usage;
public:
    Processador();
    static float cpu_work_time(Processador proc);
    static float cpu_total_time(Processador proc);
    string getCpu() const;
    void setCpu(const string &value);
    float getUser() const;
    void setUser(float value);
    float getNice() const;
    void setNice(float value);
    float getSystem() const;
    void setSystem(float value);
    float getIdle() const;
    void setIdle(float value);
    float getIowait() const;
    void setIowait(float value);
    float getIrq() const;
    void setIrq(float value);
    float getSoftirq() const;
    void setSoftirq(float value);
    float getSteal() const;
    void setSteal(float value);
    float getCpu_usage() const;
    void setCpu_usage(float value);
};

#endif // PROCESSADOR_H
