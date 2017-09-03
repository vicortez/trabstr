#include "conjunto_processos.h"
#include "processo.h"
#include <stdlib.h>  // exit()
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <QThread>

using namespace std;

Conjunto_Processos::Conjunto_Processos()
{
    atualizarDados();
}

void Conjunto_Processos::atualizarDados()
{

    Conjunto_Processos* pointer = this;
    thread atualiza(&Conjunto_Processos::lerArquivo, pointer);
    atualiza.join();
}


void Conjunto_Processos::lerArquivo()
{

        unsigned int i;
        ifstream  meusProcessos;//ler arquivo de texto
        string processos; //texto lido do arquivo de texto
        string buffer; // buffer para separar cada linha do texto em um elemento
        Processo my_rank; // Processo atual
        system("ps -aux > meusProcessos.txt");
        meusProcessos.open("meusProcessos.txt");
        getline(meusProcessos, processos);//Pular o cabeçalho do ps


        while(meusProcessos){
            i = 0;
            getline(meusProcessos, processos);//Ler a linha do .txt
            stringstream ss(processos);
            //Laço que irá separar a linha do .txt para ser analisada em uma lista
            while(ss >> buffer){
                if(i == 0){
                    my_rank.setUser(buffer);
                    i++;
                    continue;
                }
                else if(i == 1){
                    my_rank.setPID(stoi(buffer));
                    i++;
                    continue;
                }
                else if(i == 2){
                    my_rank.setCPU_USAGE(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 3){
                    my_rank.setMem(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 7){
                    my_rank.setEstado(buffer);
                    i++;
                    continue;
                }
                else if(i == 10){
                    my_rank.setComando(buffer);
                    i++;
                    continue;
                }
                else{
                    i++;
                    continue;
                }
            }
            //Adiciona ao vetor de processos do sistema
            programas.push_back(my_rank);
         }
        //Fecha arquivo de texto
        meusProcessos.close();
        QThread::sleep(2);
    }

void Conjunto_Processos::receiveFunction(Conjunto_Processos *pointer)
{
    pointer->lerArquivo();
}

