# Manufacturing

<!--
Manufacturing file — everything a subcontractor needs to produce the hardware.
List deliverable files and production / assembly instructions.
-->

## PCB manufacturing deliverables

| File                             | Format          | Description                        |
|----------------------------------|-----------------|------------------------------------|
| `gerbers/top_copper.gbr`         | Gerber RS-274X  | Top copper layer                   |
| `gerbers/bottom_copper.gbr`      | Gerber RS-274X  | Bottom copper layer                |
| `gerbers/top_solder_mask.gbr`    | Gerber          | Top solder mask                    |
| `gerbers/top_silk.gbr`           | Gerber          | Top silkscreen                     |
| `gerbers/drill.drl`              | Excellon        | Drill file                         |
| `gerbers/board_outline.gbr`      | Gerber          | Board outline                      |
| `assembly/bom_assembly.csv`      | CSV             | BOM for Pick & Place               |
| `assembly/cpl.csv`               | CSV             | Component centroids (CPL)          |
| `assembly/assembly_drawing.pdf`  | PDF             | Annotated assembly drawing         |

## PCB manufacturing specifications

| Parameter                   | Specified value          |
|-----------------------------|--------------------------|
| Number of layers            | 4                        |
| Board thickness             | 1.6 mm                   |
| Material                    | FR4 Tg ≥ 150°C           |
| Surface finish              | ENIG                     |
| Solder mask colour          | Green                    |
| Min. track width            | 0.1 mm                   |
| Min. clearance              | 0.1 mm                   |
| Min. via drill              | 0.3 mm                   |
| Impedance control           | 50 Ω ± 10 % (if applicable) |

## Assembly instructions

### Assembly order

1. Board cleaning (IPA)
2. Solder paste application (stencil)
3. SMD component placement (automated Pick & Place)
4. Convection reflow oven (profile: …)
5. Automated Optical Inspection (AOI)
6. Through-hole component soldering (if applicable)
7. Residual flux cleaning
8. Visual inspection + In-Circuit Test (ICT) if planned

### Test points

| TP Ref. | Signal        | Expected value  | Note             |
|---------|---------------|-----------------|------------------|
| TP1     | VCC_3V3       | 3.3 V ± 2 %     | Voltage measure  |
| TP2     | GND           | 0 V             | Reference        |
| TP3     | …             | …               | …                |

## Final inspection procedure

- [ ] Visual inspection of assembled PCB
- [ ] Electrical continuity test
- [ ] Progressive power-up (current limiting)
- [ ] Power rail verification
- [ ] Initial firmware programming
- [ ] Basic functional test (see [../verification/hw-bring-up.md](../verification/hw-bring-up.md))

## Reference

- BOM: [bom.md](bom.md)
- PCB design: [../design/pcb-design.md](../design/pcb-design.md)
- Bring-up: [../verification/hw-bring-up.md](../verification/hw-bring-up.md)
