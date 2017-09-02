#include "processador.h"

string Processador::getCpu() const
{
    return cpu;
}

void Processador::setCpu(const string &value)
{
    cpu = value;
}

float Processador::getUser() const
{
    return user;
}

void Processador::setUser(float value)
{
    user = value;
}

float Processador::getNice() const
{
    return nice;
}

void Processador::setNice(float value)
{
    nice = value;
}

float Processador::getSystem() const
{
    return System;
}

void Processador::setSystem(float value)
{
    System = value;
}

float Processador::getIdle() const
{
    return idle;
}

void Processador::setIdle(float value)
{
    idle = value;
}

float Processador::getIowait() const
{
    return iowait;
}

void Processador::setIowait(float value)
{
    iowait = value;
}

float Processador::getIrq() const
{
    return irq;
}

void Processador::setIrq(float value)
{
    irq = value;
}

float Processador::getSoftirq() const
{
    return softirq;
}

void Processador::setSoftirq(float value)
{
    softirq = value;
}

float Processador::getSteal() const
{
    return steal;
}

void Processador::setSteal(float value)
{
    steal = value;
}

float Processador::getCpu_usage() const
{
    return cpu_usage;
}

void Processador::setCpu_usage(float value)
{
    cpu_usage = value;
}

Processador::Processador()
{
    cpu = "";
    user = 0;
    nice = 0;
    System = 0;
    idle = 0;
    iowait = 0;
    irq = 0;
    softirq = 0;
    steal = 0;
    cpu_usage = 0;
}

float Processador::cpu_work_time(Processador proc)
{
    return proc.user + proc.nice + proc.System;
}

float Processador::cpu_total_time(Processador proc)
{
    return cpu_work_time(proc) + proc.idle + proc.iowait + proc.irq + proc.softirq + proc.steal;
}

