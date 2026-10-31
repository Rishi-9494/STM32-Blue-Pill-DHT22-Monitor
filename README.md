# STM32 Blue Pill DHT22 Temperature and Humidity Monitor

A Wokwi simulation of an STM32 Blue Pill reading temperature and relative humidity from a DHT22 sensor and displaying the readings on a 16×2 I2C LCD.

> **Project status:** Wokwi simulation. This repository documents the simulation; it does not claim that the circuit has been tested on physical hardware.

## Simulation

[Open the project in Wokwi](https://wokwi.com/projects/477064444671060993)

## Components

- STM32 Blue Pill
- DHT22 temperature and humidity sensor
- 16×2 LCD with I2C interface

## Connections

| Component | STM32 pin |
|---|---|
| DHT22 data | PA0 |
| LCD SCL | PB6 |
| LCD SDA | PB7 |
| Sensor and LCD VCC | 3.3 V |
| Sensor and LCD GND | GND |

The circuit layout and full connection definitions are in [Simulation/diagram.json](Simulation/diagram.json).

## How it works

1. The program initializes the DHT22 sensor, I2C interface and LCD.
2. It reads temperature and humidity from the sensor.
3. If either reading is invalid, it displays `Sensor Error!`.
4. Otherwise, it displays temperature in °C and relative humidity.
5. It repeats the reading and display update every two seconds.

## Repository contents

- `Source_Code/wokwi-stm32-blue-pill.ino` — main Arduino-style program.
- `Simulation/diagram.json` — Wokwi circuit and wiring definition.
- `Simulation/wokwi-project.txt` — original Wokwi project reference.
- `libraries.txt` — libraries used by the simulation.

## Libraries

- LiquidCrystal I2C
- DHT sensor library

## Run the simulation

1. Open the [Wokwi simulation](https://wokwi.com/projects/477064444671060993).
2. Start the simulation.
3. Observe the temperature and humidity values on the LCD.

## Future improvements

- Test the circuit on a physical STM32 Blue Pill board.
- Add photographs and measured hardware results after physical testing.
- Expand the documentation with any hardware-specific setup details.
