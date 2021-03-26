#include "mbed.h"
#define WAIT_TIME_MS 1000
AnalogOut aout(PA_5);
uint32_t i = 0x8000;

int main()
{
  while (true)
  {
    i += 2048;
    if (i > 0xFFFF)
      i = 0x8000;
    aout.write_u16(i);

    thread_sleep_for(WAIT_TIME_MS);
  }
}
