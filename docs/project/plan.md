# Project Plan

<!--
Project planning: phases, milestones, deliverable breakdown.
This document is a living document — update at each milestone review.
-->

## Project phases

| Phase | Name                     | Start      | End        | Closing milestone |
|:-----:|--------------------------|:----------:|:----------:|-------------------|
| 0     | Scoping                  | YYYY-MM-DD | YYYY-MM-DD | M0 — Signed Charter |
| 1     | Requirements             | YYYY-MM-DD | YYYY-MM-DD | M1 — SRR (System Requirements Review) |
| 2     | Architecture             | YYYY-MM-DD | YYYY-MM-DD | M2 — PDR (Preliminary Design Review) |
| 3     | Detailed design          | YYYY-MM-DD | YYYY-MM-DD | M3 — CDR (Critical Design Review) |
| 4     | Implementation           | YYYY-MM-DD | YYYY-MM-DD | M4 — Code + PCB Freeze |
| 5     | Integration & test       | YYYY-MM-DD | YYYY-MM-DD | M5 — TRR (Test Readiness Review) |
| 6     | Validation & delivery    | YYYY-MM-DD | YYYY-MM-DD | M6 — Acceptance |

## Detailed milestones

| ID | Milestone                       | Target date | Pass criteria                                     | Status |
|:--:|---------------------------------|:-----------:|---------------------------------------------------|:------:|
| M0 | Signed Charter                  | YYYY-MM-DD  | Charter approved by all stakeholders              | ⏳     |
| M1 | System Requirements Review      | YYYY-MM-DD  | Requirements baselined, traceability-matrix complete | ⏳  |
| M2 | Preliminary Design Review       | YYYY-MM-DD  | Architecture validated, ICD v1 issued             | ⏳     |
| M3 | Critical Design Review          | YYYY-MM-DD  | Detailed design complete, FMEA validated          | ⏳     |
| M4 | Code + PCB Freeze               | YYYY-MM-DD  | 0 open critical bugs, Gerbers delivered           | ⏳     |
| M5 | Test Readiness Review           | YYYY-MM-DD  | V&V plan approved, test environment ready         | ⏳     |
| M6 | Acceptance                      | YYYY-MM-DD  | All acceptance tests PASS, record signed          | ⏳     |

## Resources

| Role            | Name | FTE allocated | Phase(s) involved |
|-----------------|------|:------------:|--------------------|
| Project manager | …    | 0.3          | All                |
| Architect       | …    | 1.0          | 1 → 3              |
| SW Developer    | …    | 1.0          | 3 → 5              |
| HW Engineer     | …    | 1.0          | 2 → 5              |
| QA              | …    | 0.5          | 5 → 6              |

## External dependencies

| Dependency                           | Supplier    | Required by  | Impact if delayed |
|--------------------------------------|-------------|:------------:|-------------------|
| Critical components (lead time)      | …           | YYYY-MM-DD   | M4 delay          |
| Third-party certification            | …           | YYYY-MM-DD   | M6 delay          |

## Reference

- Risks: [risk-register.md](risk-register.md)
- Change management: [change-management.md](change-management.md)
- Charter: [../overview/charter.md](../overview/charter.md)
