# mbed OS Functions and Usages

> Writer: Gökhan Koçmarlı
>
> **CSE2037 | Marmara University**
> This document is a API referance.
>
> Some of the text are copied from the original mbed OS API documentation. I have declare no rights in any of texts.

### Digital I/O
|                                   | Mode    | Description                                                |
| --------------------------------- | ------- | ---------------------------------------------------------- |
| **DigitalIn varName(pinNumber)**  | Digital | For declaring a pin as a digital input source.             |
| **DigitalOut varName(pinNumber)** | Digital | For declaring a pin as a digital output source.            |
| **varName.read()**                | Digital | To read the digital value of the varName's pin. (0 \|\| 1) |
| **varName.write(value)**          | Digital | To write value to the varName's pin.                       |

### Analog I/O
|                     | Mode    | Description                                                  |
| --------------------------------- | ------- | ------------------------------------------------------------ |
| **AnalogIn varName(pinNumber)**   | Analog  | For declaring a pin as a analog input source.                |
| **AnalogOut varName(pinNumber)**  | Analog  | For declaring a pin as an analog output source.              |
| **varName.read()**                | Analog  | To read the voltage value of the varName's pin [0.0-1.0].    |
| **varName.read_u16()**            | Analog  | To read the voltage value as an unsigned short in the range [0x0-0xFFFF]. |
| **varName.read_voltage()** | Analog | To read the voltage as in units of volts. Doesn't work in Simulator.|
| **varName.write(value)**          | Analog  | Set the output voltage with specifing as a percentage value (float). |
| **varName.write_u16(value)**		       | Anlog | Set the output voltage represented as a unsigned short in range [0x0, 0xFFFF] |
<div style="page-break-after: always;"></div>
### Interrupts
|                     | Mode    | Description                                                  |
| --------------------------------- | ------- | ------------------------------------------------------------ |
| **InterruptIn varName(pinNumber)**  | Interrupt  | For declaring a pin as an GPIO interrupt source.              |

1. No blocking code in ISR: avoid any call to wait, infinite while loop or blocking calls in general.
2. No printf, malloc or new in ISR: avoid any call to bulky library  functions. In particular, certain library functions (such as printf,  malloc and new) are non re-entrant, and their behavior could be  corrupted when called from an ISR.
3. For `printfs` from interrupt context, use [Event](https://os.mbed.com/docs/mbed-os/v6.6/apis/event.html) instead.
<div style="page-break-after: always;"></div>
### Timers

|                     | Mode    | Description                                                  |
| --------------------------------- | ------- | ------------------------------------------------------------ |
| **Timer varName**  | Timer  | To initalize a timer which is stopwatch-like timer for measuring precise times. |
| **varName.start()**  | Timer  | Start counting the time. |
| **varName.stop()**  | Timer  | Stop counting the time. |
| **varName.read()**  | Timer (float) | Read the value of time as sec. Deprectated since 6.0 |
| **varName.read_ms()**  | Timer (int) | Read the value of time as miliseconds. Deprectated since 6.0 |
| **varName.read_us()**  | Timer (int) | Read the value of time as microseconds. Deprectated since 6.0 |
| **varName.read_high_resolution_us()**  | Timer (us_timestamp_t)  | 64bit microseconds value. Deprectated since 6.0 |
| **Ticker varName** | Ticker | To set up a recurring interrupt; it calls a function repeatedly and at a specified rate. |
|**varName.attach()** | Ticker | Attach a function to be called by the Ticker, specifying the interval in seconds.|
|**varName.attach_us()** | Ticker | Attach a function to be called by the Ticker, specifying the interval in microseconds.|
|**varName.detach()** | Ticker | To detach the ISR. |
| **Timeout varName** | Timeout | To set up an interrupt to call a function after a specified delay. |
|**varName.attach()** | Timeout | Attach a function to be called by the Ticker, specifying the interval in seconds.|
|**varName.attach_us()** | Timeout | Attach a function to be called by the Ticker, specifying the interval in microseconds.|
|**varName.detach()** | Timeout | To detach the ISR. |
<div style="page-break-after: always;"></div>
> You can also use LowPowerTimer, LowPowerTicker,  and LowPowerTimout for better power management. You must consider that LowPower\*s has worse precision than the normal ones but the normals can not enter the deep sleep mode. Their methods are the same.

1. Timers are based on 64-bit signed microsecond counters, giving a range of over 250,000 years.
2. No printf, malloc or new in ISR: avoid any call to bulky library functions. In particular, certain library functions (such as printf, malloc and new) are not re-entrant, and their behavior could be corrupted when called from an ISR.
3. While a Timer is running, deep sleep is blocked to maintain accurate timing. If you don't need microsecond precision, consider using the LowPowerTimer or Kernel::Clock classes instead because these do not block deep sleep mode.
4. While an event is attached to a Ticker, deep sleep is blocked to maintain accurate timing. If you don't need microsecond precision, consider using the LowPowerTicker class instead because that does not block deep sleep mode.

|                     | Mode    | Description                                                  |
| --------------------------------- | ------- | ------------------------------------------------------------ |
| Watchdog &varName = Watchdog::get_instance() | Watchdog | Initalizing the watchdog timer. |
| varName.start(TIMEOUT_IN_MS) | Watchdog | Starting the watchdog timer.|
| varName.stop() | Watchdog | Stopping the watchdog timer.|
| Watchdog::get_instance().kick() | Watchdog | Refreshing the timer. |
| varName.is_running() | Watchdog | Checking if it's already running. |

1. There is only one instance in the system. Use Watchdog::get_instance() to obtain a reference. 
2. The maximum amount of time you can set as the Watchdog timeout varies depending on the target hardware. You can check the maximum value by calling Watchdog::get_instance().get_max_timeout().
<div style="page-break-after: always;"></div>

### Pulse Witdh Modulation

|                     | Mode    | Description                                                  |
| --------------------------------- | ------- | ------------------------------------------------------------ |
| **PwmOut varName(pinNumber)** | PWM | For declaring a pin as a PWM output source.              |
| **varName.write(value)**          | PWM | Setting the duty cycle in range (0.0-1.0)                         |
| **varName.write(value)**          | PWM | Read the current duty cycle.|
| **varName.period(value)**<br>varName.period_ms(value) varName.period_us(value) | PWM | Setting the PWM's period as seconds (float), milli-seconds (int) and micro-seconds (int). |
| **varName.pulsewidth(value)**<br>varName.pulsewidth_ms(value) varName.pulsewidth_us(value) | PWM | Setting the PWM's pulsewidth as seconds (float), milli-seconds (int) and micro-seconds (int) and keeping the period the same. |
| **varName.suspend()** | PWM | Suspending the PWM signal |
| **varName.resume()** | PWM | Resuming the PWM signal |

1. Set the cycle time first, and then set the duty cycle using either a relative time period via the write() function or an absolute time period using the pulsewidth() function.
2. The default period is 0.020s, and the default pulse width is 0.
<div style="page-break-after: always;"></div>