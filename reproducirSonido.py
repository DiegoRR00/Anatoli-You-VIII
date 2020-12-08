import pygame
import sys
from time import sleep
'''
Diego Reyna Reyes & Eduardo González Luna & Alex Álvaro Flores Contreras
A01657387 & A01658281 & A01653320
Escenario Situacional (aka Anatoli You VIII)*
reproducirSonido.py
Ciudad de México, 08/12/2020
Descripción:
Este script recibe dos argumentos, el nombre de un archivo .wav y el tiempo de duración. Reproduce el sonido usando pygame
*Este es un nombre para mi uso personal, por eso es extraño.
'''
pygame.init() #Iniciar pygame
sonido=pygame.mixer.Sound(sys.argv[1])#Crear objeto de sonido con el primer argumento
sonido.play()#Reproducir
sleep(float(sys.argv[2]))#Esperar el tiempo que me diga el 2o argumento
pygame.quit()#Cerrar pygame