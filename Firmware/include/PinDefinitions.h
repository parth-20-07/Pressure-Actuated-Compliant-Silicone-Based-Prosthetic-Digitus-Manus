//
// Created by Workstation on 4/18/2023.
//

#ifndef FIRMWARE_PINDEFINITIONS_H
#define FIRMWARE_PINDEFINITIONS_H

#include <Arduino.h>

// GPIO PINS
#define NANO_GPIO_2 2
#define NANO_GPIO_3 3
#define NANO_GPIO_4 4
#define NANO_GPIO_5 5
#define NANO_GPIO_6 6
#define NANO_GPIO_7 7
#define NANO_GPIO_8 8
#define NANO_GPIO_9 9
#define NANO_GPIO_10 10
#define NANO_AI_0 A0
#define NANO_AI_1 A1
#define NANO_AI_2 A2
#define NANO_AI_3 A3
#define NANO_AI_6 A6
#define NANO_AI_7 A7

// COMMUNICATION PINS
#define SERIAL_TX 0
#define SERIAL_RX 1
#define SPI_MOSI 11
#define SPI_MISO 12
#define SPI_SCK 13
#define I2C_SDA A4
#define I2C_SCL A5

/* --------------------------- DISPLAY CONNECTION --------------------------- */
#define PUMP_1 NANO_GPIO_2
#define PUMP_2 NANO_GPIO_3
#define PUMP_3 NANO_GPIO_4
#define PUMP_4 NANO_GPIO_5

#endif // FIRMWARE_PINDEFINITIONS_H
