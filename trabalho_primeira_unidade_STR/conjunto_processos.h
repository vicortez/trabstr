#ifndef CONJUNTO_PROCESSOS_H
#define CONJUNTO_PROCESSOS_H
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include "processo.h"
class Conjunto_Processos
{
private:
    int tamanho;

public:
    vector<Processo> programas;

    Conjunto_Processos();
    void atualizarDados();
    void lerArquivo();
    static void receiveFunction(Conjunto_Processos *pointer);
    void kill_process(int);
    void pause_process(int);
    void continue_process(int);
};

#endif // CONJUNTO_PROCESSOS_H
