#include "stm32f103xb.h"
#include "matris.h"
int eng[6];

extern char tec;

int main(void) {
    _MATRIZ_PIN();

    while (1) {
        _MATRIZ_US(); 
          for(int i=0;i<6;i++){
            eng[i] = tec;
          }
    }
}