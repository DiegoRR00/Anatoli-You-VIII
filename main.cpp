#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include "FunkoManage.hpp"
/*
Diego Reyna Reyes & Eduardo González Luna & Alex Álvaro Flores Contreras
A01657387 & A01658281 & A01653320
Escenario Situacional (aka Anatoli You VIII)*
main.cpp
Ciudad de México, 08/12/2020
Descripción:
Este programa crea un funko manager con el archivo config.csv e inicia el chequeo del mouse
*Este es un nombre para mi uso personal, por eso es extraño.
*/
using namespace std;
//https://stackoverflow.com/questions/8832326/how-can-i-execute-a-command-line-command-from-a-c-program
int main()
{
    FunkoManage fm("config.csv");//crear un Funko manager
    fm.start();//Iniciar el chequeo
}