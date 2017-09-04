#ifndef CONJUNTO_PROCESSADORES_H
#define CONJUNTO_PROCESSADORES_H
#include "processador.h"
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include <QThread>
#include <thread>

using namespace std;

class Conjunto_Processadores
{
private:
    int tamanho;
public:
    vector<Processador> conj_procs;
    Conjunto_Processadores();
    static void configProcessadores(Processador cpu, int indice);
    int getTamanho();
    static void usoCPU(Processador proc, int indice);
    void usoGeral_CPU();
    static void receiveFunction(Conjunto_Processadores *pointer, Processador p, int indice);
    static void receiveFunction2(Conjunto_Processadores *pointer);
    void atualiza_arquivo();
};

#endif // CONJUNTO_PROCESSADORES_H
