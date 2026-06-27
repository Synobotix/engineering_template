# Coverage

<!--
Coverage dashboard: requirements → tests and code coverage.
Update at each milestone or sprint review.
-->

## Requirements → tests coverage

| Domain            | Total requirements | Covered | Partial | Not covered | % coverage |
|-------------------|:-----------------:|:-------:|:-------:|:-----------:|:----------:|
| Functional (SW)   | …                 | …       | …       | …           | …%         |
| Performance       | …                 | …       | …       | …           | …%         |
| Security          | …                 | …       | …       | …           | …%         |
| HW / System       | …                 | …       | …       | …           | …%         |
| **Total**         | **…**             | **…**   | **…**   | **…**       | **…%**     |

> Target: 100 % of requirements covered. Any gap must be justified below.

## Code coverage (SW)

| Module / Package    | Lines | Branches | Functions | CI report  |
|--------------------|:-----:|:--------:|:---------:|-----------|
| `src/domain/`      | …%    | …%       | …%        | [link]()  |
| `src/application/` | …%    | …%       | …%        | [link]()  |
| `src/interfaces/`  | …%    | …%       | …%        | [link]()  |
| **Global**         | **…%**| **…%**   | **…%**    | [link]()  |

> Minimum threshold: **80 % lines**, **70 % branches**. CI fails below these thresholds.

## Uncovered requirements — justifications

| Requirement | Reason for non-coverage               | Resolution plan              | Owner | Due date    |
|-------------|---------------------------------------|------------------------------|-------|-------------|
| SYS-F…      | Field validation only                 | Manual test in pilot phase   | …     | YYYY-MM-DD  |
| SW-P…       | Load environment not available        | Benchmark planned            | …     | YYYY-MM-DD  |

## Open blocking anomalies

| Anomaly ID  | Impacted requirement | Severity | Status | Owner |
|-------------|----------------------|----------|--------|-------|
| BUG-…       | …                    | Critical | Open   | …     |

## Snapshot history

| Date       | Requirements coverage | Code coverage (lines) | Milestone     |
|------------|:--------------------:|:---------------------:|---------------|
| YYYY-MM-DD | …%                   | …%                    | Sprint review |

## Reference

- Traceability matrix: [../requirements/traceability-matrix.md](../requirements/traceability-matrix.md)
- Verification plan: [verification-plan.md](verification-plan.md)
- Test cases: [test-cases/](test-cases/)
