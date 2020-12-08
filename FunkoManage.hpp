#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include "Funko.hpp"
//Coordenadas de la esquina de la ventana de prueba
#define XI 380
#define YI 25
//Ancho por default de la imagen
#define ANCHO 150 
#define ALTO 150
//Espacio estándar
#define ESPACIO 100
/*
Diego Reyna Reyes & Eduardo González Luna & Alex Álvaro Flores Contreras
A01657387 & A01658281 & A01653320
Escenario Situacional (aka Anatoli You VIII)*
FunkoManage.hpp
Ciudad de México, 08/12/2020
Descripción:
Este archivo contiene la clase FunkoManager, que se encarga de crear y enviar las coordenadas del mouse a los funko
*Este es un nombre para mi uso personal, por eso es extraño.
*/
using namespace std;

class FunkoManage{
    private:
        vector<Funko*> todos_funko;
    public:
        /**
         *Construye todos los funkos según el archivo
         *@param arch_config Nombre del archivo .csv con la información de los funkos
        */
        FunkoManage(string arch_congif){
            //Abrir el archivo
            ifstream arch;
            arch.open(arch_congif);
            int numFunko;//Almacena el número de Funkos
            string linea;//Almacena las líneas del archivo
            getline(arch,linea);//Obtener el número de Funkos
            numFunko=stoi(linea.c_str());//String -> int
            //Inofrmación de orden
            int numLinea=0;
            int numCol=0;
            for (int i=0;i<numFunko;i++){//Para cada uno de los funkos especificados
                getline(arch,linea);//Obtener la línea del archivo
                //Convertir a stringstream para separar por comas
                stringstream lineaSS(linea);
                string archivo;
                getline(lineaSS,archivo,',');//Obtener primer dato nombre de la imagen
                getline(lineaSS,archivo,',');//Obtener el nombre del audio
                //Actualizar el número de columna para que sea 2 columnas
                if (numCol==2){
                    numLinea++;
                    numCol=0;
                }
                //Obtener los espacios, el número de imagenes entre los bordes y la imagen actual y la posición dentro de la ventana de windows
                int x=ESPACIO*(numCol+1)+ANCHO*(numCol)+XI;
                int y=ESPACIO*(numLinea+1)+ALTO*(numLinea)+YI;
                numCol++;//Actualizar columnas
                todos_funko.push_back(new Funko(x,y,ANCHO,ALTO,archivo));//Agregar a la lista
            }
        }
        void start(){
            LPPOINT p;//Variable que almacena las coordenadas
            while (true){
                Sleep(500);//Esperar 1/2 segundo entre chequeos
                GetCursorPos(p);//Obtener la posición del mouse
                for (int i=0;i<todos_funko.size();i++){
                    todos_funko[i]->checarMouse(p->x,p->y);//Checar el mouse para todos los funko
                }
            }
        }
};