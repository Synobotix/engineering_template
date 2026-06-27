# HW Schematics

<!--
This document references the electronic schematics and documents sizing calculations
that are not deducible from the schematic alone.
Source files (KiCad, Altium, Eagle…) live in the repo under hardware/schematics/.
-->

## Source file locations

| File                                  | Tool   | Description                  |
|---------------------------------------|--------|------------------------------|
| `hardware/schematics/main.kicad_sch`  | KiCad  | Main schematic               |
| `hardware/schematics/power.kicad_sch` | KiCad  | Power supply                 |

## Schematic sheets

| Sheet   | Title                    | Main content                 |
|---------|--------------------------|------------------------------|
| SCH-TOP | Top-level                | Connectors, overview         |
| SCH-PWR | Power supply             | Regulators, filtering        |
| SCH-MCU | Microcontroller          | MCU and close peripherals    |
| SCH-COM | Communication            | External interfaces          |
| SCH-SEN | Sensors                  | Acquisition chain            |

## Sizing calculations

<!--
Document here non-trivial calculations (decoupling capacitors, pull-up/down resistors,
thermal sizing, sense resistor calculation…).
-->

### [Calculation name — e.g. LED current limiting resistor]

**Objective**: …  
**Parameters**:
- V_supply = … V
- V_forward = … V
- I_forward = … mA

**Calculation**:  
R = (V_supply − V_forward) / I_forward = … Ω → chosen standard value: … Ω

**Margin**: … %

---

### [Calculation name — e.g. MCU decoupling capacitor]

…

## Important schematic notes

<!--
Constraints not visible on the schematic: non-standard component choices,
errata workarounds, critical placement rules.
-->

| Reference | Note                                              | Impact if ignored        |
|-----------|--------------------------------------------------|--------------------------|
| U1        | Errata rev. A: pin X must not be connected to GND | Short circuit             |
| C12       | Place < 1 mm from MCU VCC pin                    | Power supply noise        |

## Reference

- HW Architecture: [../architecture/hw-architecture.md](../architecture/hw-architecture.md)
- PCB: [pcb-design.md](pcb-design.md)
- BOM: [../implementation/bom.md](../implementation/bom.md)
