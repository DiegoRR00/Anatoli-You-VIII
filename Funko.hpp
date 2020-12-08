#include <iostream>
#include <stdlib.h>
/*
Diego Reyna Reyes & Eduardo González Luna & Alex Álvaro Flores Contreras
A01657387 & A01658281 & A01653320
Escenario Situacional (aka Anatoli You VIII)*
Funko.hpp
Ciudad de México, 08/12/2020
Descripción:
Este archivo contiene la clase funko que guarda sus coordenadas y si el mouse esta dentro de las coordendas reproduce un sonido usando reproducirSonido.py
*Este es un nombre para mi uso personal, por eso es extraño.
*/
using namespace std;
class Funko{
    protected:
        int *esquinas;//Almacena las esquinas de la imagen
        string arch_audio;//Guarda el nombre del archivo de audio que se reproduce
        bool dentro;//Guarda si el mouse está dentor de la imagen

        public:
            /**
             * Inicializa un Funko
             * @param x Coordenada en x de la esquina superior izquierda
             * @param y Coordenada en y de la esquina superior derecha
             * @param ancho Ancho de la imagen
             * @param alto Alto de la imagen
             * @param nuevo_arch_audio Nombre del archivo de audio del funko
            */
            Funko(int x, int y, int ancho, int alto, string nuevo_arch_audio){
                //Crear esquinas y almacenar basándose en las coordenadas y las dimensiones de la imagen
                esquinas=new int[4];
                esquinas[0]=x;
                esquinas[1]=y;
                esquinas[2]=x+ancho;
                esquinas[3]=y+alto;
                //Guardar nombre del archivo
                arch_audio=nuevo_arch_audio;
                dentro=false; //Inicializar dentro
            }
            /**
             * Reproduce el sonido si el mouse está sobre la imagen
             * @param x Coordenada en x del cursor
             * @param y Coordenada en y del cursor
            */
            void checarMouse(int x, int y){
                if (x>=esquinas[0] && x<=esquinas[2] && y>=esquinas[1] && y<=esquinas[3]){//Si está dentro del rango
                    if (!dentro){//Si es la primera vez que se detecta el mouse 
                        string comm="python reproducirSonido.py "+arch_audio+" 3";//Comando para llamar el archivo de pygame que reproduce el audio
                        system(comm.c_str());//Enciar el comando a la consola
                        dentro=true;//Evitar que se ejcute muchas veces seguidas
                    }
                }
                else{
                    dentro=false;//El mouse no está dentro, reinicializar para la próxima
                }
            }
};