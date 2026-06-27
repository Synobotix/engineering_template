# Mechanical ICD

<!--
Mechanical interfaces between subsystems or between the system and its environment.
Includes: envelopes, fixing points, loads, tolerances, contact materials.
-->

## Mechanical interface list

| ID       | Interface                        | Block A         | Block B         | Nature              |
|----------|----------------------------------|-----------------|-----------------|---------------------|
| ICD-M001 | Enclosure ↔ structure fixing     | Enclosure       | Customer chassis | M4 screws × 4 points |
| ICD-M002 | Cable entry                      | Enclosure       | Connector J2    | PG9 cable gland     |
| ICD-M003 | Thermal interface                | MCU / Component | Heatsink        | Thermal pad …       |

## Envelope dimensions

| Axis | Max dimension | Measurement reference | Note |
|------|--------------|----------------------|------|
| L    | … mm         | Front face           | …    |
| W    | … mm         | Left face            | …    |
| H    | … mm         | Bottom face          | …    |

## Fixing points

| ID     | Position (x, y, z) | Hole       | Tightening torque | Admissible load |
|--------|-------------------|------------|-------------------|-----------------|
| FIX-01 | …                 | M4 ∅ 4.3  | … N·m             | … N             |

## Tolerances

| Interface  | Parameter             | Tolerance       | Reference standard |
|------------|-----------------------|-----------------|--------------------|
| ICD-M001   | Fixing pitch          | ± 0.1 mm        | ISO 2768-m         |
| ICD-M003   | Surface flatness      | 0.05 mm         | …                  |

## Reference

- HW architecture: [../hw-architecture.md](../hw-architecture.md)
- Mechanical design: [../../design/mechanical-design.md](../../design/mechanical-design.md)
- HW requirements: [../../requirements/hw-requirements.md](../../requirements/hw-requirements.md)
