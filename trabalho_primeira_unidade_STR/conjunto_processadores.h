#ifndef CONJUNTO_PROCESSADORES_H
#define CONJUNTO_PROCESSADORES_H
#include "processador.h"
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <QThread>

using namespace std;

class Conjunto_Processadores
{
private:
    int tamanho = sysconf(_SC_NPROCESSORS_ONLN);
public:
    vector<Processador> conj_procs;
    vector<float> work;
    vector<float> tempo;
    Conjunto_Processadores();
    void configProcessadores(Conjunto_Processadores vetor);
    int getTamanho() const;
    static float usoCPU(Processador proc);
};

#endif // CONJUNTO_PROCESSADORES_H
