//Esse código tem como separar a string em uma lista(prefiro java ou python para isso)


#include <stdlib.h>  // exit() 
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//Objeto para tratar os processos como objetos
struct processo{
	int PID;
	string user;
	string comando;
	float CPU;
	float mem;
};
int main(void){
	unsigned int i;
	ifstream  meusProcessos;//ler arquivo de texto
	string processos; //texto lido do arquivo de texto
	string buffer; // buffer para separar cada linha do texto em um elemento
	vector<processo> programas; //vector que vai receber os objetos processos
	processo my_rank; // Processo atual


	processos = system("ps -aux > meusProcessos.txt");//comando que irá escrever o comando no .txt
	meusProcessos.open("meusProcessos.txt");
	getline(meusProcessos, processos);//Pular o cabeçalho do ps
	
	
	while(meusProcessos){
		i = 0;
		getline(meusProcessos, processos);//Ler a linha do .txt
		stringstream ss(processos);
		//Laço que irá separar a linha do .txt para ser analisada em uma lista
		while(ss >> buffer){
			if(i == 0){
				my_rank.user = buffer;
				i++;
				continue;
			}
			else if(i == 1){
				my_rank.PID = stoi(buffer);
				i++;
				continue;
			}
			else if(i == 2){
				my_rank.CPU = stof(buffer);
				i++;
				continue;
			}
			else if(i == 3){
				my_rank.mem = stof(buffer);
				i++;
				continue;
			}
			else if(i == 10){
				my_rank.comando = buffer;
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
	/*
	i = 0;
	while(i < programas.size()){
		cout << programas.at(i).CPU << endl;;
		i++;
	}
	*/
	//Fecha arquivo de texto
	meusProcessos.close();
	return 0;
}