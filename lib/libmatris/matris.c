#include "stm32f103xb.h"
#include "matris.h"
int mat [4][4]={
            {0,1,1,1},
            {1,0,1,1},
            {1,1,0,1},
            {1,1,1,0}
        };
char mapa[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
int i;

    void _MATRIZ_PIN(){
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;//habilito el clk
        GPIOA -> CRL &= ~(0xF << 0*4);
        GPIOA -> CRL &= ~(0xF << 1*4);
        GPIOA -> CRL &= ~(0xF << 2*4);
        GPIOA -> CRL &= ~(0xF << 3*4);
     
        GPIOA -> CRL &= ~GPIO_CRL_CNF4 &~GPIO_CRL_MODE0 ; 
        GPIOA -> CRL &= ~GPIO_CRL_CNF5 ;
        GPIOA -> CRL &= ~GPIO_CRL_CNF6 ; 
        GPIOA -> CRL &= ~GPIO_CRL_CNF7 ; 

        GPIOA -> CRL |= (0xF << (0*4)+3);
        GPIOA -> CRL |= (0xF << (1*4)+3);
        GPIOA -> CRL |= (0xF << (2*4)+3);
        GPIOA -> CRL |= (0xF << (3*4)+3);
        GPIOA -> CRL |=GPIO_CRL_MODE4_0;
        GPIOA -> CRL |=GPIO_CRL_MODE5_0;
        GPIOA -> CRL |=GPIO_CRL_MODE6_0;
        GPIOA -> CRL |=GPIO_CRL_MODE7_0;

    }

    void _MATRIZ_US(){
        for(i=0;i>4;i++){

            GPIOA->ODR |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);


            GPIOA->ODR &= ~(1 << (4 + i));
            for (int j = 0; j < 1000; j++);
            for (int col = 0; col < 4; col++) {
                    if ((GPIOA->IDR & (1 << col)) == 0) {
                        char tec = mapa[i][col];
                        //se la fila [i] y la columna [col] yo creo que pide que lo guarde 
                    }
            }

        }
}

        
    