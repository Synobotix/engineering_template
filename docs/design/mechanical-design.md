# Mechanical Design

<!--
Mechanical design: enclosures, chassis, assembly, materials, tolerancing.
CAD source files live in hardware/mechanical/.
-->

## CAD files

| File                                  | Tool        | Description                  |
|---------------------------------------|-------------|------------------------------|
| `hardware/mechanical/assembly.step`   | STEP AP214  | Full assembly (export)       |
| `hardware/mechanical/enclosure.f3d`   | Fusion 360  | Enclosure                    |

## Parts and assemblies

| Part ref.  | Designation           | Material       | Mass (g) | Status      |
|------------|-----------------------|----------------|----------|-------------|
| MEC-001    | Upper enclosure       | ABS / PA12     | …        | In progress |
| MEC-002    | Lower enclosure       | ABS / PA12     | …        | In progress |
| MEC-003    | Sealing gasket        | Silicone 60 Sh | …        | To specify  |

## Tolerancing

| Interface             | Parameter               | Tolerance     | Standard     |
|-----------------------|-------------------------|---------------|--------------|
| Enclosure assembly    | Fit clearance           | H7/h6         | ISO 286      |
| Screw passage         | Hole diameter           | ∅ M4 + 0.3 mm | ISO 2768-m   |

## Strength / stress analysis

<!--
Summary of mechanical checks: FEA, analytical calculation.
Link to detailed reports.
-->

| Load case                    | Max calculated stress | Material limit | Safety margin |
|------------------------------|-----------------------|----------------|---------------|
| Shock of … g for … ms        | … MPa                 | … MPa          | … %           |

## Thermal (mechanical aspects)

| Hot spot        | Heat flux | Interface          | Thermal resistance |
|-----------------|-----------|--------------------|--------------------|
| MCU (U1)        | … W       | Pad → heatsink     | … K/W              |

## Assembly process

1. …
2. …
3. Sealing verification: see [../verification/hw-bring-up.md](../verification/hw-bring-up.md)

## Reference

- Mechanical ICD: [../architecture/interfaces/mechanical-icd.md](../architecture/interfaces/mechanical-icd.md)
- HW Requirements: [../requirements/hw-requirements.md](../requirements/hw-requirements.md)
- Manufacturing file: [../implementation/manufacturing.md](../implementation/manufacturing.md)
