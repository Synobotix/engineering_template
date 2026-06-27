# Hazard Analysis — HARA

<!--
Hazard Analysis and Risk Assessment.
Recommended method: HARA (ISO 26262 / adapted ISO 13849 / ISO 8800 depending on domain).
To be performed BEFORE the safety architecture — results feed safety-concept.md.
-->

## Analysis scope

- **System analysed**: …
- **Life phases covered**: Installation / Nominal operation / Maintenance / End of life
- **Reference standards**: ISO 13849, ISO 10218, ISO 8800, … _(adapt as needed)_

---

## Hazard identification

| ID    | Operating situation | Hazard (unwanted event)      | Potential consequence   |
|-------|---------------------|------------------------------|-------------------------|
| H-001 | …                   | …                            | …                       |
| H-002 | …                   | …                            | …                       |

## Risk assessment

Evaluation criteria (adapt per standard):

| Criterion       | Levels                                            |
|-----------------|---------------------------------------------------|
| Severity (S)    | S1 Light / S2 Serious / S3 Severe / S4 Fatal      |
| Exposure (E)    | E1 Very rare / E2 Rare / E3 Occasional / E4 Frequent |
| Avoidability (A)| A1 Possible / A2 Difficult                        |

| Hazard | Severity (S) | Exposure (E) | Avoidability (A) | Initial risk level | Required level (PL/SIL) |
|--------|:------------:|:------------:|:----------------:|:------------------:|:-----------------------:|
| H-001  | S…           | E…           | A…               | …                  | PL … / SIL …            |
| H-002  | S…           | E…           | A…               | …                  | PL … / SIL …            |

## Risk reduction measures

| Hazard | Preventive measure                   | Detection measure                | Mitigation measure                |
|--------|--------------------------------------|----------------------------------|-----------------------------------|
| H-001  | …                                    | …                                | …                                 |

## Residual risks

| Hazard | Residual level  | Accepted by | Acceptance date |
|--------|:--------------:|-------------|-----------------|
| H-001  | PL … / SIL …  | …           | YYYY-MM-DD      |

## Reference

- Safety Concept: [safety-concept.md](safety-concept.md)
- FMEA: [fmea.md](fmea.md)
- Safety requirements: [../requirements/system-requirements.md](../requirements/system-requirements.md)
- Compliance: [compliance.md](compliance.md)
