# Compliance

<!--
Mapping between the system and applicable standards / regulations.
This document demonstrates normative coverage and traces compliance evidence.
-->

## Applicable standards and regulations

| Standard / Regulation      | Domain                   | Obligation         | Version / Date          |
|---------------------------|--------------------------|--------------------|-----------------------|
| …                         | Machine safety           | CE certification   | EN ISO 13849-1:2015    |
| …                         | Collaborative robotics   | Compliance         | ISO 10218-1/2          |
| …                         | Cybersecurity            | Compliance         | IEC 62443-4-2          |
| GDPR                      | Data protection          | Legal              | 2018                   |
| …                         | EMC                      | CE marking         | EN 61000-…             |

## Compliance matrix

| Normative requirement (clause) | Standard      | System response                       | Evidence / Doc.                  | Status |
|-------------------------------|---------------|---------------------------------------|----------------------------------|--------|
| §X.X …                        | ISO 13849     | Safety concept FS-001                 | [safety-concept.md](safety-concept.md) | ✅ |
| §Y.Y …                        | IEC 62443     | Measures T-001 to T-005              | [security.md](security.md)       | 🚧 WIP |
| Art. 25 — Privacy by Design   | GDPR          | Minimised data, encryption            | [security.md](security.md)       | ✅ |

## Compliance file (Technical File)

| Document                          | Status        | Location                              |
|-----------------------------------|---------------|---------------------------------------|
| CE Declaration of Conformity      | To produce    | `docs/safety-compliance/`             |
| HARA report                       | In progress   | [hazard-analysis.md](hazard-analysis.md) |
| FMEA report                       | In progress   | [fmea.md](fmea.md)                    |
| Safety Concept                    | In progress   | [safety-concept.md](safety-concept.md) |
| V&V test reports                  | To produce    | `docs/verification/test-reports/`     |
| User manual                       | To produce    | `docs/operations/user-manual.md`      |

## External audits and reviews

| Organisation      | Audit type         | Planned date | Result | Observations |
|-------------------|--------------------|--------------|--------|--------------|
| …                 | Pre-certification  | YYYY-MM-DD   | —      | —            |

## Reference

- Constraints: [../requirements/constraints.md](../requirements/constraints.md)
- HARA: [hazard-analysis.md](hazard-analysis.md)
- Security: [security.md](security.md)
