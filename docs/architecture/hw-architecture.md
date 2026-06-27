# Hardware Architecture

<!--
Hardware architecture overview: block diagram, functional blocks,
power supplies, physical interfaces.
-->

## 1. General block diagram

<!--
Insert the block diagram or a link to the source file (KiCad, Altium, draw.io).
Show: main blocks, communication buses, power supplies.
-->

```
[Insert diagram here or link to source file]
```

## 2. Functional blocks

| Block           | Role                              | Main component      | Schematic ref    |
|-----------------|-----------------------------------|---------------------|------------------|
| Power supply    | Conversion and regulation         | …                   | SCH-PWR          |
| Microcontroller | Processing, supervision           | …                   | SCH-MCU          |
| Communication   | External interface (CAN, ETH, USB)| …                   | SCH-COM          |
| Sensors         | Acquisition                       | …                   | SCH-SEN          |
| Actuators       | Control                           | …                   | SCH-ACT          |

## 3. Power architecture

| Rail       | Voltage | Max current | Source     | Main load          |
|------------|---------|-------------|------------|--------------------|
| VCC_3V3    | 3.3 V   | …           | Regulator  | MCU, sensors       |
| VCC_5V     | 5 V     | …           | …          | …                  |
| VCC_BAT    | …       | …           | Battery    | …                  |

## 4. Hardware buses and interfaces

| Bus / Interface | Standard    | Data rate    | Master → Slave(s)     | Referenced ICD |
|----------------|-------------|--------------|----------------------|----------------|
| …              | SPI / I2C   | …            | MCU → sensor         | [electrical-icd.md](interfaces/electrical-icd.md) |
| …              | CAN         | 1 Mbit/s     | …                    | …              |
| …              | Ethernet    | 100 Mbit/s   | …                    | …              |

## 5. Placement / integration constraints

<!--
Mechanical and thermal rules impacting PCB layout or assembly.
-->

- Minimum distance between sensitive components and heat sources: …
- EMC guard zone: …
- Fixing constraints: see [mechanical-icd.md](interfaces/mechanical-icd.md)

## 6. Architecture decisions

- [[ADR-XXXX]] — _Microcontroller / platform selection_

## Reference

- HW requirements: [../requirements/hw-requirements.md](../requirements/hw-requirements.md)
- Detailed schematics: [../design/hw-schematics.md](../design/hw-schematics.md)
- PCB: [../design/pcb-design.md](../design/pcb-design.md)
