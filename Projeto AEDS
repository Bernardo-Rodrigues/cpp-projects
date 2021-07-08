/*
Projeto: Esse projeto tem o papel de organizar de maneira dinâmica a entrada e saída de médicos e pacientes em um consultorio.

Alunos: Bernardo Rodrigues(2020030010)     
*/

#include <iostream>
#include <stdlib.h> 
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct medico{
  queue <string> fila;
  vector <string> lista;
}; 

struct medico Medico;
map <string, medico> Consultorio;

void menu();
void cadastraMedico();
void cadastraPaciente();
void chamar();
void filas();

int main() {
  menu();
  
  return 0;
}
void cadastraMedico(){
  string medico;
  char op;
  
  cout << "CADASTRAR MEDICO" << endl << endl;

  do{
    cout << "Nome do médico: ";
    cin >> ws;
    getline(cin, medico);
    cout << endl;

    Consultorio.emplace(medico,Medico);

    cout << "Cadastrar outro (S/N) ?" << endl;

    do{
      cout << "Opcao: ";
      cin >> op;
      cout << endl;
      switch(op){
        case 'S': break;
        case 'N': cout << endl; menu(); break;
        default : cout << "Inválido" << endl; break;
      }
    }while(op != 'S' && op != 'N');
  }while(op == 'S');
}
void cadastraPaciente(){
  string paciente, medico;
  char op;
  int i = 1;

  cout << "CADASTRAR PACIENTE" << endl << endl;
  for (auto& x:Consultorio) {
    cout << "Médico " << i << "- " << x.first << '\n';
    i++;
  }
  cout << endl;

  do{
    cout << "Nome do paciente: ";
    cin >> ws;
    getline(cin, paciente);
    cout << "Médico: ";
    getline(cin, medico);
    cout << endl;

    if(Consultorio.find(medico) != Consultorio.end()) { 
      Consultorio[medico].fila.emplace(paciente);
      Consultorio[medico].lista.emplace_back(paciente);
    }else{
      cout << "Medico invalido!" << endl;
    }

    cout << "Cadastrar outro (S/N) ?" << endl;

    do{
      cout << "Opcao: ";
      cin >> op;
      cout << endl;
      switch(op){
        case 'S': break;
        case 'N': cout << endl; menu(); break;
        default : cout << "Inválido" << endl; break;
      }
    }while(op != 'S' && op != 'N');
  }while(op == 'S');
}
void chamar(){
  string medico;
  char op;
  int i = 1;

  cout << "CHAMAR PACIENTE" << endl << endl;
  for (auto& x:Consultorio) {
    cout << "Médico " << i << "- " << x.first << '\n';
    i++;
  }
  cout << endl;
  
  do{
    cout << "Medico: ";
    cin >> ws;
    getline(cin, medico);

    if(Consultorio.find(medico) != Consultorio.end()) {
      cout << "Paciente chamado: " << Consultorio[medico].fila.front() << endl << endl; 
      Consultorio[medico].fila.pop();
      Consultorio[medico].lista.erase(Consultorio[medico].lista.begin());
    }else{
      cout << "Medico invalido!" << endl;
    }

    cout << "Chamar outro (S/N) ?" << endl;
    
    do{
      cout << "Opcao: ";
      cin >> op;
      cout << endl;
      switch(op){
        case 'S': break;
        case 'N': cout << endl; menu(); break;
        default : cout << "Inválido" << endl; break;
      }
    }while(op != 'S' && op != 'N');
  }while(op == 'S');
}
void filas(){
  
  for (auto& x:Consultorio) {
    cout << "Fila Dr. " << x.first << ":" << '\n';
    for(int i = 0; i < x.second.lista.size(); i++){
      cout << i + 1 << "- " << x.second.lista.at(i) << endl;
    }
    cout << endl;
  }

  cout << endl << endl;
    
  system("read -p \"Pressione enter para voltar...\" saindo");
}
void menu(){
  int opcao;

  system("clear");

  cout << "O que deseja fazer?\n\n";
  cout << "1. Cadastrar medico\n"
          "2. Cadastrar paciente\n"
          "3. Chamar proximo paciente\n"
          "4. Ver filas\n"
          "5. Finalizar programa\n\n";

    do{
      cout << "Opcao: ";
      cin >> opcao;
    
      switch(opcao){
        case 1: system("clear"); cadastraMedico(); break;
        case 2: system("clear"); cadastraPaciente(); break;
        case 3: system("clear"); chamar(); break;
        case 4: system("clear"); filas(); break;
        case 5: break;
        default: cout << "Invalido!" << endl; break;
      }
    }while(opcao <1 || opcao > 5);
}
