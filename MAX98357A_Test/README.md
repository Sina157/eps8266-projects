# MAX98357A Test with ESP8266

## Overview

This project tests the MAX98357A I2S audio amplifier module by generating rapid digital pulses on three GPIO pins of an ESP8266 NodeMCU development board.

The purpose is to experiment with fast GPIO switching and observe the amplifier's response to digital signals.

## Hardware

- ESP8266 NodeMCU development board
- MAX98357A I2S audio amplifier module
- Speaker
- Jumper wires

## Pin Connections

| ESP8266 NodeMCU | MAX98357A |
|---|---|
| D3 (GPIO0) | DIN |
| D2 (GPIO4) | BCLK |
| D1 (GPIO5) | LRC |

Connect the power and ground pins according to the module's specifications.

## How It Works

The program configures GPIO0, GPIO4, and GPIO5 as outputs. Inside the main loop, it repeatedly sets all three pins HIGH and then LOW, generating rapid digital transitions.

### Why `GPIO_REG_WRITE()`?

`GPIO_REG_WRITE()` writes directly to a hardware GPIO register on the ESP8266.

The code uses two registers:

- `GPIO_OUT_W1TS_ADDRESS`: Sets the selected GPIO output bits to HIGH.
- `GPIO_OUT_W1TC_ADDRESS`: Clears the selected GPIO output bits to LOW.

This approach avoids calling `digitalWrite()` separately for each pin. It changes all three output bits in a single register operation, which is useful for experimenting with fast, closely synchronized GPIO transitions.

The expression `(1 << PIN_DIN) | (1 << PIN_BCLK) | (1 << PIN_LRC)` creates a bitmask representing the three GPIO pins.

## Important Note

This test generates rapid digital pulses; it does not implement a complete I2S audio protocol. The MAX98357A normally expects properly timed I2S data, bit clock, and word-select signals. Therefore, this test alone is not expected to produce valid audio.

![MAX98357A Test](https://github.com/Sina157/eps8266-projects/blob/main/MAX98357A_Test/V27JJQ~1.JPG)

GPIO0 is also a boot-configuration pin on the ESP8266, so external circuitry connected to it can affect startup if it pulls the pin to the wrong level.

## Purpose

This is a low-level GPIO experiment for learning about direct hardware register access and digital signal generation on the ESP8266.
