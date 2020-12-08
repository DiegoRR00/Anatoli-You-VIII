#include <windows.h>
#include <iostream>
using namespace std;
int main(){
    LPPOINT p;//Variable que almacena las coordenadas
    for (int i=0;i<10;i++){
        Sleep(2000);
        GetCursorPos(p);
        cout<<p->x<<" "<<p->y<<endl;
    }
}