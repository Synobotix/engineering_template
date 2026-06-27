# Safety Concept

<!--
System safety architecture — responds to hazards identified in the HARA.
Defines safety mechanisms, their allocation, and sufficiency evidence.
Document to produce BEFORE detailed design.
-->

## 1. Required safety level summary

| Safety function       | Covered hazard(s)   | Required level | Standard    |
|-----------------------|---------------------|:--------------:|-------------|
| …                     | H-001, H-002        | PL d / SIL 2   | ISO 13849   |
| …                     | H-003               | PL c / SIL 1   | ISO 13849   |

## 2. Safety functions

<!--
For each safety function identified in the HARA:
-->

### FS-001 — [Safety function name]

| Field                | Value                                  |
|----------------------|----------------------------------------|
| **Description**      | …                                      |
| **Trigger**          | …                                      |
| **Safety action**    | Controlled stop / Safe state / …       |
| **Required level**   | PL … / SIL …                           |
| **Hazard(s)**        | H-001                                  |

**Implementation mechanisms**:
- Hardware mechanism: …
- Software mechanism: …
- Redundant channel: …

**Diagnostic Coverage (DC)**: … %  
**Maximum reaction time (SRT)**: … ms

---

## 3. Safety architecture

<!--
Block diagram showing safety channels, voting elements (1oo2, 2oo3…),
watchdogs, self-tests.
-->

```
[Insert safety architecture diagram]
```

## 4. Responsibility allocation

| Mechanism            | SW | HW | External | Justification          |
|----------------------|:--:|:--:|:--------:|------------------------|
| Watchdog             | □  | ✓  | □        | Independent from SW    |
| Voltage monitoring   | □  | ✓  | □        | …                      |
| Input validation     | ✓  | □  | □        | …                      |
| Start-up test        | ✓  | □  | □        | Power-On Self-Test     |

## 5. Safety architecture validation

| Safety requirement   | Verifying mechanism | Test(s) | Status |
|----------------------|---------------------|---------|--------|
| FS-001               | …                   | TC-S001 | …      |

## Reference

- HARA: [hazard-analysis.md](hazard-analysis.md)
- FMEA: [fmea.md](fmea.md)
- Compliance: [compliance.md](compliance.md)
- System architecture: [../architecture/system-architecture.md](../architecture/system-architecture.md)
