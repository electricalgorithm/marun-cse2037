#include "mbed.h"
#define WAIT_TIME_MS 1000
PwmOut pout(PC_8);
uint32_t i = 0;

int main()
{
  pout.period_us(256);

  while (true)
  {
    i += 16;
    if (i > 0XFF)
      i = 0;
    pout.pulsewidth_us(i);

    thread_sleep_for(WAIT_TIME_MS);
  }
}
