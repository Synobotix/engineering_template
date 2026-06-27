# FMEA — Failure Mode and Effects Analysis

<!--
Failure Mode and Effects Analysis.
Can be performed at system (SFMEA), design (DFMEA), or process (PFMEA) level.
Fed by the HARA results.
-->

## Scope

- **Type**: DFMEA / PFMEA _(delete whichever does not apply)_
- **System analysed**: …
- **Criticality index (RPN)**: Severity × Occurrence × Detectability (each rated 1–10)

---

## FMEA table

| ID    | Element / Function | Failure mode        | Effect(s) | Cause(s) | S | O | D | RPN | Preventive actions | Owner | Due date    | RPN after action |
|-------|--------------------|--------------------|-----------| ---------|:-:|:-:|:-:|:---:|---------------------|-------|-------------|:----------------:|
| FM-001| …                  | …                  | …         | …        | … | … | … | …   | …                   | …     | YYYY-MM-DD  | …                |
| FM-002| …                  | …                  | …         | …        | … | … | … | …   | …                   | …     | YYYY-MM-DD  | …                |

<!--
Legend:
S = Severity (1-10): 10 = failure causing serious injury
O = Occurrence (1-10): 10 = very frequent failure
D = Detectability (1-10): 10 = undetectable failure
RPN = Risk Priority Number = S × O × D (max 1000)

Treatment thresholds (adapt as needed):
- RPN ≥ 200: corrective action MANDATORY
- RPN 100-199: corrective action RECOMMENDED
- RPN < 100: monitoring
-->

## Critical risk summary (RPN ≥ 200)

| ID    | Failure mode        | Initial RPN | Required action               | Target RPN |
|-------|---------------------|:-----------:|-------------------------------|:----------:|
| FM-…  | …                   | …           | …                             | …          |

## Action plan

| Action             | Owner       | Target date | Status   | Evidence / Result |
|--------------------|-------------|-------------|----------|-------------------|
| …                  | …           | YYYY-MM-DD  | Open     | …                 |

## Reference

- HARA: [hazard-analysis.md](hazard-analysis.md)
- Safety Concept: [safety-concept.md](safety-concept.md)
- Verification plan: [../verification/verification-plan.md](../verification/verification-plan.md)
