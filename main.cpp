// Patricia Palula Aguilar
// A01732537
// Proyecto 1

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

char desifrar(char s[2][14], char clave){
    char num;
    if(clave == s[1][0])
        num = s[0][0];
    if(clave == s[1][1])
        num = s[0][1];
    if(clave == s[1][2])
        num = s[0][2];
    if(clave == s[1][3])
        num = s[0][3];
    if(clave == s[1][4])
        num = s[0][4];
    if(clave == s[1][5])
        num = s[0][5];
    if(clave == s[1][6])
        num = s[0][6];
    if(clave == s[1][7])
        num = s[0][7];
    if(clave == s[1][8])
        num = s[0][8];
    if(clave == s[1][9])
        num = s[0][9];
}

int main()
{
    string entrada, salida;
    cout << "Escribe el nombre del archivo de entrada: " ;
    cin >> entrada;
    cout << "Escribe el nombre del archivo de salida: ";
    cin >> salida;
    ifstream inputFile;
    inputFile.open("Datos.txt");
    string codigo, numC1, operC, numC2;
    char carac;
    char clave[2][14] = {{'0','1','2','3','4','5','6','7','8','9'}};
    string contra;
    for(int i = 0; i < 14; i++){
        inputFile >> carac;
        clave[1][i] = carac;
        contra += carac;
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 14; j++){
            cout << clave[i][j] << "    " ;
        }
        cout << endl;
    }
    cout << "CONTRA  " << contra << endl;
    int largoNum1, num1, decod, num;
    while(inputFile >> numC1 >> operC >> numC2){
        int largoNum1 = numC1.length();
        num1 = 0;
        for(int i = 0; i < largoNum1; i++){
            num = contra.find(numC1[i]);
            cout << "num " << num << endl;
            num1 += num * pow(10, largoNum1 - i - 1);
            cout << "num1" << " += (" << num << " * " << pow(10, largoNum1 - i - 1) << endl;
        }
        cout << numC1 << " = " << num1 << endl;
    }
    inputFile.close();
    return 0;
}
