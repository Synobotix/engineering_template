# Electrical ICD

<!--
Index of electrical interfaces between blocks/subsystems.
Each major interface may have its own ICD-XXXX file (use icd-template.md).
This file is the entry point — it lists and summarises all electrical interfaces.
-->

## Electrical interface list

| ID       | Interface                        | Producer       | Consumer       | Standard    | Detailed ICD |
|----------|----------------------------------|----------------|----------------|-------------|--------------|
| ICD-E001 | Main power supply                | PSU            | MCU            | —           | ICD-E001.md (create from [template](../../meta/templates/icd-template.md)) |
| ICD-E002 | SPI bus — sensor …               | MCU            | Sensor X       | SPI Mode 0  | ICD-E002.md (create from [template](../../meta/templates/icd-template.md)) |
| ICD-E003 | I2C bus — …                      | MCU            | …              | I2C 400kHz  | ICD-E003.md (create from [template](../../meta/templates/icd-template.md)) |
| ICD-E004 | GPIO — …                         | MCU            | …              | 3.3V LVCMOS | —            |

<!--
Create one ICD-Exxx.md file per non-trivial interface (use meta/templates/icd-template.md).
-->

## External connectors

| Connector ref | Designation       | Pinout (schematic ref) | Notes          |
|---------------|-------------------|------------------------|----------------|
| J1            | Power supply      | SCH-PWR, p. …          | …              |
| J2            | Field interface   | SCH-COM, p. …          | IP67 required  |

## Reference

- HW architecture: [../hw-architecture.md](../hw-architecture.md)
- Schematics: [../../design/hw-schematics.md](../../design/hw-schematics.md)
- ICD template: [../../meta/templates/icd-template.md](../../meta/templates/icd-template.md)
