# PCB Design

<!--
PCB design rules and decisions.
Complete before launching routing — these rules must be configured in the DRC.
-->

## Stackup

| Layer   | No. | Thickness (mm) | Material    | Usage                    |
|---------|-----|----------------|-------------|--------------------------|
| Top     | 1   | 0.035          | Cu          | Signal + SMD components  |
| Prepreg | —   | 0.2            | FR4         | Insulation               |
| Inner 1 | 2   | 0.035          | Cu          | GND plane                |
| Inner 2 | 3   | 0.035          | Cu          | PWR plane                |
| Prepreg | —   | 0.2            | FR4         | Insulation               |
| Bottom  | 4   | 0.035          | Cu          | Signal                   |

**Total thickness**: … mm  
**Material Tg**: ≥ … °C

## Routing rules

| Parameter                       | Min value  | Recommended value  | Note                         |
|---------------------------------|------------|--------------------|------------------------------|
| Signal track width              | 0.1 mm     | 0.15 mm            | Per max current ≤ 500 mA     |
| Power track width               | …          | …                  | Calculate per I and ΔT       |
| Track-to-track clearance        | 0.1 mm     | 0.15 mm            | Voltage ≤ 50 V               |
| Track-to-edge clearance         | 0.3 mm     | 0.5 mm             | Milling                      |
| Via drill (signal)              | 0.3 mm     | 0.4 mm             | —                            |
| Via drill (power)               | 0.6 mm     | 0.8 mm             | —                            |
| Annular ring                    | 0.15 mm    | 0.2 mm             | —                            |

## Placement rules

| Rule                                         | Value / Note                          |
|----------------------------------------------|---------------------------------------|
| Decoupling capacitors                        | < 1 mm from VCC pin of each IC        |
| High-frequency components (> 10 MHz)         | TOP side only                         |
| Ground plane under MCU                       | Mandatory (Inner 1 layer)             |
| Analogue / digital separation                | Split ground plane between zones      |
| SMD component to board edge distance         | ≥ 3 mm                                |

## EMC constraints

| Rule                                         | Target standard |
|----------------------------------------------|-----------------|
| High-frequency current loop area             | < … mm²         |
| Differential pairs                           | Length matched ± 0.5 mm |
| Ground decoupling for external connector     | Interface via + filter |

## Manufacturing process

| Parameter             | Value       |
|-----------------------|-------------|
| Surface finish        | HASL / ENIG |
| Solder mask colour    | Green / …   |
| Silkscreen            | White        |
| Drill tolerance       | ± 0.05 mm   |
| Outer dimension tolerance | ± 0.1 mm |

## Reference

- Schematics: [hw-schematics.md](hw-schematics.md)
- Manufacturing file: [../implementation/manufacturing.md](../implementation/manufacturing.md)
- Electrical ICD: [../architecture/interfaces/electrical-icd.md](../architecture/interfaces/electrical-icd.md)
