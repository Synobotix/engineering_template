# Change Management

<!--
Configuration and change management: how a change to requirements, design,
or hardware is proposed, evaluated, approved, and traced.
Without this process, documentation silently diverges from reality.
-->

## Principles

- **Baseline**: any deliverable approved at a milestone is baselined — it can only be modified through an ECR.
- **Single-source-of-truth**: documents in this repo are authoritative; a decision not traced here is not official.
- **Impact first**: every ECR is evaluated on its impact (cost, schedule, safety, compliance) before approval.

## ECR / ECO process

```
Identification → ECR submitted → Impact analysis → Decision → ECO issued → Implementation → Verification → Closure
```

| Step              | Actor             | Max delay       | Deliverable                  |
|-------------------|-------------------|:---------------:|------------------------------|
| ECR submission    | Requester         | —               | Completed ECR form           |
| Impact analysis   | Architect / QA    | 5 business days | Impact report                |
| Decision          | Project manager   | 3 business days | ECR approved / rejected      |
| Implementation    | Dev / Engineer    | Per scope       | Commits + updated docs       |
| Verification      | QA                | —               | Regression tests OK          |
| ECO closure       | Project manager   | —               | ECO archived                 |

## ECR / ECO register

| ID     | Title                           | Type  | Requester | Submission date | Impact | Status     | Associated ECO | Closing date |
|--------|---------------------------------|-------|-----------|:--------------:|--------|------------|:--------------:|:------------:|
| ECR-001| …                               | Req.  | …         | YYYY-MM-DD     | Low    | Approved   | ECO-001        | YYYY-MM-DD   |
| ECR-002| …                               | Design| …         | YYYY-MM-DD     | Medium | In progress| —              | —            |

<!--
Type: Requirement / SW Design / HW Design / Documentation / Process
Status: Submitted / Under analysis / Approved / Rejected / Implemented / Closed
-->

## Baselines

| Baseline | Milestone | Date       | Included documents                       | Frozen? |
|----------|-----------|:----------:|------------------------------------------|:-------:|
| BL-001   | M1        | YYYY-MM-DD | system-requirements.md v1.0             | ✅      |
| BL-002   | M3        | YYYY-MM-DD | + architecture/* + design/* v1.0        | ✅      |

## Document version management

- Version format: `MAJOR.MINOR` (e.g. `1.2`)
- MAJOR: structural change following an ECO
- MINOR: minor correction or addition, no design impact
- Update the document header and the Revisions section

## Reference

- Project plan: [plan.md](plan.md)
- Risks: [risk-register.md](risk-register.md)
- Doc versioning: [../meta/versioning.md](../meta/versioning.md)
