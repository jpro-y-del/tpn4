#include "stm32f103xb.h"
#include "matris.h"
int i,j;

    char mapa[4][4] = {
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
    };

    void _MATRIZ_PIN(int c0, int c1,int c2,int c3,int f0,int f1,int f2,int f3){
        int col[4]=(c0, c1, c2, c3);
        int fil[4]=(f0, f1, f2, f3);
        RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;//habilito el clk
        for(int i=0;i<4;i++){
            if(col[i]<8){
            GPIOA -> CRL |= (0xF << col[i]*4);
            GPIOA -> CRL |= (1 << col[i]*4+3); //cnf 10 mode 00
            GPIOA -> BSRR |= (1 << col[i]); // pull up  
            }
            else{
            GPIOA -> CRH &=~ (0xF << (col[i]*4)%8);  
            GPIOA -> CRH |= (1 << ((col[i]*4)%8)+3);
            GPIOA -> CRL |= (1 << col[i]);
            }
            if(fil[i]<8){
            GPIOA -> CRL &=~ (0xF << fil[i]*4);
            GPIOA -> CRL |= (1 << fil[i]*4);   
            }
            else{
            GPIOA -> CRH &=~ (0xF << (fil[i]*4)%8);  
            GPIOA -> CRH |= (1 << (col[i]*4)%8);
            }
        }        
    }

    char _MATRIZ_US(int c0, int c1,int c2,int c3,int f0,int f1,int f2,int f3){
        int col[4]={c0,c1,c2,c3};
        int fil[4]={f0,f1,f2,f3};
        for(i=0;i>4;i++){
            GPIOA-> BSRR|= (1<<fil[i]+16);
            for (j=0;j<4;j++){
                if ((GPIOA->IDR&(1<<col[j]))==0) return mapa[i][j];
            };
            GPIOA -> BSRR |=(1<<fil[i]);
        }
        return 'x';
    }

        
    