* fSCLK_SPI master = 160Mhz => read 1 sample - 1 channel  need : 32*(1/fCLK)*10^6 = 0.2 Microsecond

* Mathematically, the Nyquist theorem can be expressed as follows:
++++++++++++++
|fs >= 2fmax |
++++++++++++++
fmax = finput = 10Khz
=> fs >= 20Khz 

choose fs = 40Khz => T = 25 microseconds.
=> fISR = 40Khz
