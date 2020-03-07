// Patricia Palula Aguilar
// A01732537
// Proyecto 1

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int descifrarNum(string clave, string numCif){
  int largoNumCif = numCif.length();
  int numDes = 0, multiplicando;
  for(int i = 0; i < largoNumCif; i++){
    multiplicando = clave.find(numCif[i]);
    numDes += multiplicando * pow(10, largoNumCif - i - 1);
  }
  return numDes;
}

int resultadoOpe(string clave, string &oper, int num1, int num2){
  int resultado;
  int posicion = clave.find(oper);
  switch(posicion){
    case 10:
      resultado = num1 + num2;
      oper = "+";
      return resultado;
    break;
    case 11:
      resultado = num1 - num2;
      oper = "-";
      return resultado;
    break;
    case 12:
      resultado = num1 * num2;
      oper = "*";
      return resultado;
    break;
    case 13:
      resultado = num1 / num2;
      oper = "/";
      return resultado;
    break;
  }
  return 0;
}

int main()
{
    string entrada, salida;
    cout << "Escribe el nombre del archivo de entrada: " ;
    cin >> entrada;
    cout << "Escribe el nombre del archivo de salida: ";
    cin >> salida;
    ifstream inputFile;
    inputFile.open(entrada);
    ofstream outputFile;
    outputFile.open(salida);
    char carac;
    string clave;
    for(int i = 0; i < 14; i++){
        inputFile >> carac;
        clave += carac;
    }
    int numDesci1, numDesci2, resulOpe;
    string numC1, operC, numC2;
    while(inputFile >> numC1 >> operC >> numC2){
      numDesci1 = descifrarNum(clave, numC1);
      numDesci2 = descifrarNum(clave, numC2);
      resulOpe = resultadoOpe( clave, operC, numDesci1, numDesci2);
      outputFile << "(" <<numDesci1 << ") " << operC << " (" << numDesci2 << ") " << " = " <<resulOpe << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
