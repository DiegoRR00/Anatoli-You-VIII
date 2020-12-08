import pygame
import os.path
import csv
'''
Diego Reyna Reyes & Eduardo González Luna & Alex Álvaro Flores Contreras
A01657387 & A01658281 & A01653320
Escenario Situacional (aka Anatoli You VIII)*
ventana.py
Ciudad de México, 08/12/2020
Descripción:
Este script crea una ventana simulada para realizar la prueba del código en main.cpp
*Este es un nombre para mi uso personal, por eso es extraño.
'''
#Variables del programa
size=(600,700)
fondo=(255,255,255)
letras=(0,0,0)
espacio=[100,100]
tamano=[150,150]
#Imagen que se encarga de imprimirse a si misma
class Imagen:
    #archivo: Nombre del archivo de la Imagen
    #Coordenadas: Coordenadas de la esquina superior izquierda
    def __init__(self, archivo, coordenadas):
        self.archivo=pygame.image.load(archivo) 
        self.archivo=pygame.transform.scale(self.archivo,tamano)
        self.x=coordenadas[0]
        self.y=coordenadas[1]
        #Win: Ventana donde se va a imprimir la imagen
    def print(self, win):
        win.blit(self.archivo,(self.x,self.y))


pygame.init()#Iniciar pygame
imagenes=[]#Vector para almacenar todos las imagenes
with open("config.csv") as archivo:#Abrir archivo
    lector=csv.reader(archivo,delimiter=',')#Obtener datos
    #Variables de posici+on
    counter=0
    columna=0
    fila=0
    for renglon in lector:
        if counter!=0:#Ignorar el primer renglón
            counter+=1#Aumentar counter
            if (columna==2):#Se imprimen en 2 columnas, entonces cuando es 2, se debe cambiar de fila
                fila+=1#Aukentar fila
                columna=0#Reinicar columna
            for dato in renglon:#Obtener los valores dentro de un renglón
                #Agregar imagen
                imagenes.append(Imagen(dato,[espacio[0]*(columna+1)+tamano[0]*columna,espacio[1]*(fila+1)+tamano[1]*fila]))
                break#No me importan los datos más allá del primero
            columna+=1
        else:
            counter+=1
win=pygame.display.set_mode(size) #Abrir una ventana
pygame.display.set_caption("funko.com")#Nombre de la ventana
win.fill(fondo)#Rellenar
#Imprimir simulación de interfaz
font=pygame.font.Font('freesansbold.ttf',15)
text=font.render('Simulación de interfaz',True,letras,fondo)
textRect=text.get_rect()
textRect.center=(100,50)
running=True
while running:
    pygame.time.delay(1000)#Tiempo entre actualizaciones
    pygame.display.update()#Actualizar el display
    for event in pygame.event.get():#Obtener evento para detectar que el usuario cerró la vetana
        if event.type== pygame.QUIT:
            running=False#Parar el programa
    win.fill(fondo)#Poner el fondo
    for imgObj in imagenes:#Imprimir cada una de las imagenes
        imgObj.print(win)
    win.blit(text,textRect)#Imprimir texto
pygame.quit()#Cerra pygame