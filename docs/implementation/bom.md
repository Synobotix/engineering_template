# BOM — Bill of Materials

<!--
Complete product BOM for hardware.
RULE: one reference BOM here; tooling (KiCad, Altium) exports views from it.
Keep consistent with electronic schematics.
-->

## Metadata

| Field         | Value         |
|---------------|---------------|
| BOM version   | 0.1           |
| Date          | YYYY-MM-DD    |
| Project       | …             |
| Approver      | …             |

## Electronic BOM

| Qty | Schematic ref | Designation                  | Manufacturer  | MPN                   | Supplier | Supplier ref      | Alternate MPN | Notes         |
|-----|---------------|-------------------------------|---------------|----------------------|----------|-------------------|---------------|---------------|
| 1   | U1            | MCU STM32G0B1CET6             | STMicro       | STM32G0B1CET6         | Mouser   | 511-STM32G0B1CET6 | …             | LQFP-48       |
| 4   | C1–C4         | Capacitor 100nF 0402 50V      | Murata        | GRM155R71H104KA88D    | Mouser   | …                 | …             | Decoupling    |
| …   | …             | …                             | …             | …                     | …        | …                 | …             | …             |

## Mechanical BOM

| Qty | Part ref.  | Designation               | Material  | Supplier | Supplier ref | Notes            |
|-----|------------|---------------------------|-----------|----------|--------------|------------------|
| 1   | MEC-001    | Upper enclosure           | PA12      | …        | …            | Injection / SLS  |
| 4   | FIXE-001   | M3×8 socket head screw    | Inox A2   | …        | …            | ISO 4762         |

## Indicators

| Indicator                        | Value |
|----------------------------------|-------|
| Total line count                 | …     |
| Components without alternate     | …     |
| Out-of-stock components          | …     |
| Estimated NRE cost               | … €   |
| Unit cost in series (1000 pcs)   | … €   |

## Procurement policy

- Each critical component must have ≥ 1 qualified alternate.
- Maximum accepted lead time: … weeks.
- Approved suppliers: …

## Reference

- Schematics: [../design/hw-schematics.md](../design/hw-schematics.md)
- Manufacturing file: [manufacturing.md](manufacturing.md)
