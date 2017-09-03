#ifndef PROCESSO_H
#define PROCESSO_H
#include <string>

using namespace std;

class Processo
{
private:
    int PID;
    string user;
    string comando;
    float CPU_USAGE, mem;
    int CPU_MASK;
    string estado;
public:
    Processo(int _PID, string _user, string _comando, float _CPU_USAGE, float _mem);
    Processo();



    int getPID() const;
    void setPID(int value);
    string getUser() const;
    void setUser(const string &value);
    float getCPU_USAGE() const;
    void setCPU_USAGE(float value);
    float getMem() const;
    void setMem(float value);
    int getCPU_MASK() const;
    void setCPU_MASK(int value);
    string getComando() const;
    void setComando(const string &value);
    string getEstado() const;
    void setEstado(const string &value);
};

#endif // PROCESSO_H
