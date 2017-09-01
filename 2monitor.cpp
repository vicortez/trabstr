#include <stdlib.h>  
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <time.h>

using namespace std;

struct processador{
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
};
struct conjunto_processadores
{
	/* data */
	vector<processador> conj_procs;
	int nproc = sysconf(_SC_NPROCESSORS_ONLN);
};

//posporopr
//isso é um teste
///asaasasas

void setProcessadores(processador &my_rank, conjunto_processadores &vetor){
	unsigned int cont = 0, i;
	unsigned int nproc = sysconf(_SC_NPROCESSORS_ONLN);
	ifstream meusProcessadores;
	string processadores;
	string buffer;
	


	processadores = system("cat /proc/stat > meusProcessadores.txt");
	meusProcessadores.open("meusProcessadores.txt");
	getline(meusProcessadores, processadores);

	while(cont < nproc){
		i = 0;
		getline(meusProcessadores, processadores);
		stringstream ss(processadores);
		while(ss >> buffer){
			if(i == 0){
				my_rank.cpu = buffer;
				i++;
				continue;
			}
			else if(i == 1){
				my_rank.user = stof(buffer);
				i++;
				continue;
			}
			else if(i == 2){
				my_rank.nice = stof(buffer);
				i++;
				continue;
			}
			else if(i == 3){
				my_rank.System = stof(buffer);
				i++;
				continue;
			}
			else if(i == 4){
				my_rank.idle = stof(buffer);
				i++;
				continue;
			}
			else if(i == 5){
				my_rank.iowait = stof(buffer);
				i++;
				continue;
			}
			else if(i == 6){
				my_rank.irq = stof(buffer);
				i++;
				continue;
			}
			else if(i == 7){
				my_rank.softirq = stof(buffer);
				i++;
				continue;
			}
			else if(i == 8){
				my_rank.steal = stof(buffer);
				break;
			}
			else
				break;
		}
		cont++;
		vetor.conj_procs.push_back(my_rank);
	}
}

float cpu_work_time(processador my_rank){
	return my_rank.user + my_rank.nice + my_rank.System;
}

float cpu_total_time(processador my_rank){
	return cpu_work_time(my_rank) + my_rank.idle + my_rank.iowait + my_rank.irq + my_rank.softirq + my_rank.steal;
}
int main(void){
	processador my_rank, my_rank2;
	conjunto_processadores conj1, conj2;
	float work, tempo, cpu;
	//float cpu_percentage;
	setProcessadores(my_rank, conj1);
	sleep(2);
	setProcessadores(my_rank2, conj2);
	
	
	
	
	for (unsigned int i = 0; i < conj1.conj_procs.size(); i++)
	{
		work = cpu_work_time(conj2.conj_procs.at(i)) - cpu_work_time(conj1.conj_procs.at(i));
		tempo = cpu_total_time(conj2.conj_procs.at(i)) - cpu_total_time(conj1.conj_procs.at(i));
		cpu = work/tempo * 100;
		cout << my_rank.cpu << " : " << cpu << endl;
	}



	return 0;
}
