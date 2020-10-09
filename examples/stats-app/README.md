# Description

This app configures radio in continuous transmission test mode.
Default setup is:

* Freq --> 868.3 MHz,
* Power --> 5dBm,
* PRBS mode --> OQPSK-SIN-RC-100,
* payload --> 0xAA

## You can configure

### Duration

In noise-generation.c configure *APP_DURATION*.

### Set frequency and power

Go to function rf2xx_CTTM_start() and configure:

* Frequency or channel in step **4** (refer to datasheet section 7.8.2 - RF Channel selection)
* Transmission power in step **5** (refer to datasheet section 7.3.4 - TX Output power)

### Select between PRBS or CW mode

Go to function rf2xx_CTTM_start() and configure steps **8** and **9** ... Refer to datasheet appendix A and picture below.

**PRBS**

![PRBS BPSK modulation](./img/PRBS-BPSK.png)
![PRBS OQPSK modulation](./img/PRBS-OQPSK.png)

**CW**

![CW - continuous wave](./img/CW.png)