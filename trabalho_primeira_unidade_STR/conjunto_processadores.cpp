#include "conjunto_processadores.h"

using namespace std;
int Conjunto_Processadores::getTamanho()
{
    return tamanho;
}
//Falta agora é calcular para todas as cepus, esse método é só pra uma
void Conjunto_Processadores::usoCPU(Processador proc, int indice)
{
    float work1, work2;
    float tempo1, tempo2;
    while(1){
        configProcessadores(proc, indice);
        work1 = Processador::cpu_work_time(proc);
        tempo1 = Processador::cpu_total_time(proc);
        sleep(2);
        configProcessadores(proc, indice);
        work2 = Processador::cpu_work_time(proc);
        tempo2 = Processador::cpu_total_time(proc);
        proc.setCpu_usage((work2 - work1)/(tempo2 - tempo1) * 100);

    }

}

//Inicializa o ponteiro para iniciar a thread que vai calcular o uso da CPU
//de cada core
void Conjunto_Processadores::receiveFunction(Conjunto_Processadores *pointer, Processador p, int indice)
{
    pointer->usoCPU(p, indice);
}

//Inicializa o ponteiro pra inicializar a thread que vai atualizar o arquivo
//Com os dados da cpu
void Conjunto_Processadores::receiveFunction2(Conjunto_Processadores *pointer)
{
    pointer->atualiza_arquivo();;
}

//Atualiza arquivo de leitura a cada 1 segundo para ser lido pelas threads que atualizam a cada 2 segundos
void Conjunto_Processadores::atualiza_arquivo()
{
    while(1){
        system("cat /proc/stat > meusProcessadores.txt");
        sleep(1);
    }
}
//Fazer uma função que atualize o arquivo /proc/stat independente da leitura dele
Conjunto_Processadores::Conjunto_Processadores()
{
    tamanho = sysconf(_SC_NPROCESSORS_ONLN);
    /*
    thread atualiza_texto();
    Conjunto_Processadores *pointer = this;
    for(int i = 0; i < tamanho; i++){
        conj_procs.push_back(Processador());
        thread atualiza(&receiveFunction, pointer, conj_procs.at(i), i);
        atualiza.join();
    }
    */
}
//Atualiza os dados do processador a ser analisado o tempo
void Conjunto_Processadores::configProcessadores(Processador cpu, int indice)
{

        unsigned int i = 0;
        ifstream meusProcessadores;
        string processadores;
        string buffer;
        Processador p;

        meusProcessadores.open("meusProcessadores.txt");
        getline(meusProcessadores, processadores);//Lê o cabeçalho do arquivo
        for(int j = 0; j < indice; j++){//Pula as linhas do arquivo para chegar a linha referenta à cpu sendo analisada
            getline(meusProcessadores, processadores);
        }
        //Lê a linha do processador a ser analisado
        getline(meusProcessadores, processadores);
        stringstream ss(processadores);
        while(ss >> buffer){
            if(i == 0){
                cpu.setCpu(buffer);
                i++;
                continue;
            }
            else if(i == 1){
                cpu.setUser(stof(buffer));
                i++;
                continue;
            }
            else if(i == 2){
                cpu.setNice(stof(buffer));
                i++;
                continue;
            }
            else if(i == 3){
                cpu.setSystem(stof(buffer));
                i++;
                continue;
            }
            else if(i == 4){
                cpu.setIdle(stof(buffer));
                i++;
                continue;
            }
            else if(i == 5){
                cpu.setIowait(stof(buffer));
                i++;
                continue;
            }
            else if(i == 6){
                cpu.setIrq(stof(buffer));
                i++;
                continue;
            }
            else if(i == 7){
                cpu.setSoftirq(stof(buffer));
                i++;
                continue;
            }
            else if(i == 8){
                cpu.setSteal(stof(buffer));
                break;
            }
            else
                break;
        }
}

