#include "conjunto_processadores.h"

using namespace std;

int Conjunto_Processadores::getTamanho() const
{
    return tamanho;
}
//Falta agora é calcular para todas as cepus, esse método é só pra uma
float Conjunto_Processadores::usoCPU(Processador proc)
{
    float work1, work2;
    float tempo1, tempo2;
    float cpu_usage;

    //Conjunto_Processadores::configProcessadores(proc);
    work1 = Processador::cpu_work_time(proc);
    tempo1 = Processador::cpu_total_time(proc);
    sleep(2);
    work2 = Processador::cpu_work_time(proc);
    tempo2 = Processador::cpu_total_time(proc);
    proc.setCpu_usage((work2 - work1)/(tempo2 - tempo1) * 100);
    cpu_usage = proc.getCpu_usage();
    return cpu_usage;

}

Conjunto_Processadores::Conjunto_Processadores()
{
    for(int i = 0; i < tamanho; i++){
        conj_procs.push_back(Processador());
        work.push_back(0.0);
        tempo.push_back(0.0);
    }
}

void Conjunto_Processadores::configProcessadores(Conjunto_Processadores vetor)
{
    while(1){
        unsigned int cont = 0, i;
        unsigned int nproc = this->getTamanho();
        ifstream meusProcessadores;
        string processadores;
        string buffer;
        Processador p;

        system("cat /proc/stat > meusProcessadores.txt");
        meusProcessadores.open("meusProcessadores.txt");
        getline(meusProcessadores, processadores);

        while(cont < nproc){
            i = 0;
            getline(meusProcessadores, processadores);
            stringstream ss(processadores);
            while(ss >> buffer){
                if(i == 0){
                    vetor.conj_procs.at(cont).setCpu(buffer);
                    i++;
                    continue;
                }
                else if(i == 1){
                    vetor.conj_procs.at(cont).setUser(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 2){
                    vetor.conj_procs.at(cont).setNice(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 3){
                    vetor.conj_procs.at(cont).setSystem(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 4){
                    vetor.conj_procs.at(cont).setIdle(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 5){
                    vetor.conj_procs.at(cont).setIowait(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 6){
                    vetor.conj_procs.at(cont).setIrq(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 7){
                    vetor.conj_procs.at(cont).setSoftirq(stof(buffer));
                    i++;
                    continue;
                }
                else if(i == 8){
                    vetor.conj_procs.at(cont).setSteal(stof(buffer));
                    break;
                }
                else
                    break;
            }
            cont++;
        }
    }
}

