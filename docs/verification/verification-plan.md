# Verification Plan

<!--
V&V strategy: who tests what, how, when, and with what success criteria.
This document is the reference for requirements → tests coverage.
-->

## 1. Test levels

| Level          | Scope                                 | Method              | Owner         |
|----------------|---------------------------------------|---------------------|---------------|
| Unit           | Isolated function / component         | Automated (Jest)    | Dev           |
| Integration    | Interaction between modules           | Automated           | Dev / QA      |
| System         | Full system under real conditions     | Automated + Manual  | QA            |
| Acceptance     | Validates stakeholder needs           | Manual (scenarios)  | Client / PO   |
| Field          | Real deployment environment           | Manual              | Engineer      |

## 2. Verification methods

| Method      | Code | Definition                                      | Applicable to    |
|-------------|------|-------------------------------------------------|------------------|
| Test        | T    | Execution and measurement on system or component| SW + HW          |
| Analysis    | A    | Calculation, simulation, modelling              | HW (thermal…)    |
| Inspection  | I    | Code review, schematics, models                 | SW + HW          |
| Demonstration | D  | Observed operation without precise measurement  | Functional       |

## 3. Global success criteria

| Criterion                              | Target threshold      |
|----------------------------------------|-----------------------|
| Code coverage (lines)                  | ≥ 80 %                |
| Requirements coverage (traced)         | 100 %                 |
| Blocking failing tests                 | 0                     |
| Open critical anomalies                | 0                     |
| Open major anomalies                   | ≤ 5 (with resolution plan) |

## 4. Phase plan

| Phase       | Tests to perform                            | Pass gate                              |
|-------------|---------------------------------------------|----------------------------------------|
| Dev (sprint)| Automated unit + integration tests          | CI passes (0 failures)                 |
| Code Freeze | System + regression                         | ≥ 80 % coverage + 0 critical           |
| Acceptance  | User scenarios + edge cases                 | PO signs the acceptance record         |
| Delivery    | Smoke test on production environment        | Signed checklist                       |

## 5. Test environments

| Environment  | Infrastructure                   | Data                       | Access           |
|--------------|----------------------------------|----------------------------|------------------|
| Dev local    | Docker Compose                   | Seeded test data           | Dev              |
| CI           | GitHub Actions (Ubuntu runner)   | Ephemeral database         | Automated        |
| Staging      | … (cloud / on-prem)              | Realistic dataset          | QA + Dev         |
| Production   | …                                | Real data                  | Ops only         |

## 6. Tools

| Tool            | Usage                          | Version |
|-----------------|-------------------------------|---------|
| Jest            | Unit and integration tests     | …       |
| Supertest       | HTTP API tests                 | …       |
| Testing Library | React component tests          | …       |
| Codecov         | Coverage report                | —       |

## Reference

- Traceability matrix: [../requirements/traceability-matrix.md](../requirements/traceability-matrix.md)
- Test cases: [test-cases/](test-cases/)
- Reports: [test-reports/](test-reports/)
- Coverage: [coverage.md](coverage.md)
