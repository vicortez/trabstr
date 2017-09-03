#include "processo.h"




int Processo::getPID() const
{
    return PID;
}

void Processo::setPID(int value)
{
    PID = value;
}

string Processo::getUser() const
{
    return user;
}

void Processo::setUser(const string &value)
{
    user = value;
}

float Processo::getCPU_USAGE() const
{
    return CPU_USAGE;
}

void Processo::setCPU_USAGE(float value)
{
    CPU_USAGE = value;
}

float Processo::getMem() const
{
    return mem;
}

void Processo::setMem(float value)
{
    mem = value;
}

int Processo::getCPU_MASK() const
{
    return CPU_MASK;
}

void Processo::setCPU_MASK(int value)
{
    CPU_MASK = value;
}

string Processo::getComando() const
{
    return comando;
}

void Processo::setComando(const string &value)
{
    comando = value;
}

string Processo::getEstado() const
{
    return estado;
}

void Processo::setEstado(const string &value)
{
    estado = value;
}

Processo::Processo(int _PID, string _user, string _comando, float _CPU_USAGE, float _mem)
{
    PID = _PID;
    user = _user;
    comando = _comando;
    CPU_USAGE = _CPU_USAGE;
    mem = _mem;
    CPU_MASK = 0b111;
}

Processo::Processo()
{

}
