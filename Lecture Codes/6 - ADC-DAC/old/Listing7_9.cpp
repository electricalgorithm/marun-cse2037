//will be checked again.

#include "mbed.h"

#define ConvNum 20

Ticker HwADCTrigger;
AnalogIn   ain(p15);

float value[ConvNum];
int cnt = 0, ind;
bool adcFlag = false;

void ADC_read() { 
    value[cnt] = ain.read();
    printf("value %d: %.4f \n", cnt, value[cnt]);
    cnt++;
    if (cnt>ConvNum)
    cnt=0;
    adcFlag=true;
    }

int main(void)
{

  HwADCTrigger.attach(callback(&ADC_read), .02f);

    printf("ADC Conversion Started\n");

  while (true)
  {
    if (adcFlag)
    {
        adcFlag=false;
      HwADCTrigger.detach();
    float sum=0;      
    for (ind = 0; ind <ConvNum; ind++)
    sum+=value[ind];
  sum=sum/(float)ConvNum;
    printf("normalized: %4.4f \n", sum);
      
    }

    //the CPU goes to the deep sleep mode.
    wait_ms(osWaitForever);

  }
}


/*
For the board implementation
In mbed_app.json file below settings should be set to true in order to print
floating numbers to console "platform.minimal-printf-enable-floating-point"
*/
