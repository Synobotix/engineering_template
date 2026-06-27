# Software Requirements

<!--
Software requirements derived from system requirements (SYS-*).
Allocate here only what is implemented by software.
-->

## Numbering convention

- `SW-Fxxx` — Functional
- `SW-Pxxx` — Performance
- `SW-Axxx` — Availability / Reliability
- `SW-Sxxx` — Security
- `SW-Ixxx` — Software interfaces
- `SW-Qxxx` — Quality / Maintainability

---

## Functional requirements

| ID       | Requirement (SHALL)                         | Priority | Traced SYS | Status |
|----------|---------------------------------------------|----------|------------|--------|
| SW-F001  | …                                           | Must     | SYS-F001   | Draft  |

## Performance requirements

| ID       | Requirement                                 | Target value | Condition | Traced SYS |
|----------|---------------------------------------------|--------------|-----------|------------|
| SW-P001  | …                                           | …            | …         | SYS-P001   |

## Software interface requirements

| ID       | Interface                 | Protocol / Format | Requirement             | Traced SYS |
|----------|---------------------------|-------------------|-------------------------|------------|
| SW-I001  | …                         | …                 | …                       | SYS-I001   |

## Software security requirements

| ID       | Requirement                                 | Expected mechanism | Traced SYS |
|----------|---------------------------------------------|--------------------|------------|
| SW-S001  | …                                           | …                  | SYS-S001   |

## Quality requirements

| ID       | Attribute            | Requirement                                 |
|----------|----------------------|---------------------------------------------|
| SW-Q001  | Test coverage        | ≥ 80 % of lines                             |
| SW-Q002  | Static analysis      | 0 critical errors (tool: …)                 |

## Reference

- Parent system requirements: [system-requirements.md](system-requirements.md)
- SW architecture: [../architecture/sw-architecture.md](../architecture/sw-architecture.md)
