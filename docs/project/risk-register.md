# Risk Register

<!--
PROJECT risks (≠ product risks which are in safety-compliance/).
Updated at each milestone review or as soon as a new risk is identified.
-->

## Assessment scale

| Probability   | Score | Definition                       |
|---------------|:-----:|----------------------------------|
| Rare          | 1     | < 10 % chance of occurring       |
| Possible      | 2     | 10 – 40 %                        |
| Probable      | 3     | 40 – 70 %                        |
| Almost certain| 4     | > 70 %                           |

| Impact        | Score | Definition                            |
|---------------|:-----:|---------------------------------------|
| Minor         | 1     | Light disruption, < 1 week            |
| Moderate      | 2     | Slip 1–4 weeks, budget ≤ 10 %         |
| Major         | 3     | Slip > 1 month, budget > 10 %         |
| Critical      | 4     | Cancellation or major rework          |

**Risk score** = Probability × Impact  
Treatment threshold: ≥ 6 → mitigation plan mandatory.

---

## Register

| ID    | Risk                                             | Category    | P | I | Score | Status      | Mitigation                                              | Owner | Review     |
|-------|--------------------------------------------------|-------------|:-:|:-:|:-----:|-------------|--------------------------------------------------------|-------|:----------:|
| R-001 | Critical component procurement delay             | Procurement | 3 | 3 | **9** | Active      | Order 3 months ahead, identify alternates             | …     | YYYY-MM-DD |
| R-002 | Key resource unavailability (leave/illness)       | HR          | 2 | 3 | **6** | Monitoring  | Shared documentation, pair on critical modules         | …     | YYYY-MM-DD |
| R-003 | Misunderstood requirement → architecture rework  | Technical   | 2 | 4 | **8** | Active      | SRR review with customer before baseline              | …     | YYYY-MM-DD |
| R-004 | Scope creep                                      | Governance  | 3 | 2 | **6** | Active      | Formal ECR process, PO signs every new requirement    | …     | YYYY-MM-DD |
| R-005 | …                                                | …           | … | … | …     | …           | …                                                      | …     | YYYY-MM-DD |

<!--
Categories: Technical / Procurement / HR / Governance / Financial / Regulatory / External
Status: Active / Monitoring / Closed / Accepted
-->

## Closed risks

| ID    | Risk                  | Closing date | Reason                   |
|-------|-----------------------|:------------:|--------------------------|
| …     | …                     | YYYY-MM-DD   | …                        |

## Reference

- Project plan: [plan.md](plan.md)
- Charter: [../overview/charter.md](../overview/charter.md)
