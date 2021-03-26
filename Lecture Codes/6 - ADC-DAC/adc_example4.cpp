#include "mbed.h"

#define ConvNum 20

InterruptIn button(p5);
Ticker HwADCTrigger;
AnalogIn   ain(p15);

float value[ConvNum];
int cnt = 0;
char cond=0;    

void ADC_read(){ 
    extern int cnt;
    extern char cond;
    
    if (cnt<ConvNum){
	    value[cnt] = ain.read();
	    printf("value %d: %.4f \n", cnt, value[cnt]);    
	    cnt++;
    }  else   cond=1;
}

void start_conversion(){
    HwADCTrigger.attach(callback(&ADC_read), .03f);  
    cnt=0;
}

int main(void){
    float sum;
    int ind;
    extern char cond;

    button.rise(callback(&start_conversion));

  while (true){
    if (cond == 1){
	    HwADCTrigger.detach();
	    cond=0;
	    sum=0;    
	    for (ind = 0; ind < ConvNum; ind++)  sum+=value[ind];
	    sum/=ConvNum;
  	    printf("average : %4.4f \n", sum);
    }
    wait_us(1);
  }
}
