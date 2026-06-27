# ADR-0001 — Adoption of the V-model documentation structure

| Field        | Value                     |
|--------------|---------------------------|
| **ID**       | ADR-0001                  |
| **Date**     | YYYY-MM-DD                |
| **Status**   | Accepted                  |
| **Authors**  | …                         |
| **Reviewers**| …                         |

---

## Context

<!--
Pre-filled ADR example. Replace with the first real decision of the project.
-->

The project covers both software and hardware components. It is necessary to choose
a documentation structure that:
- covers the complete lifecycle (need → design → proof → operations),
- supports bidirectional traceability requirement ↔ test,
- remains maintainable by a distributed team and readable by AI tooling.

## Decision

We adopt a documentation structure inspired by the V-model, organised into
thematic domains (overview / requirements / architecture / design / implementation /
verification / safety-compliance / operations / project / meta), without numeric
prefixes on folder names.

## Rationale

- The V-model is the reference for system projects (ISO 15288) and is natively
  understood by HW and SW teams.
- The absence of numeric prefixes simplifies navigation by topic and reduces noise in
  AI tools (more readable index).
- ADRs are stored in `architecture/decisions/` to remain co-located with
  the architecture they document.

## Alternatives considered

| Option                      | Advantages                   | Disadvantages              | Reason for rejection          |
|-----------------------------|------------------------------|----------------------------|-------------------------------|
| Numbered structure (partially kept) | Obvious reading order | Noise in file names      | Kept for milestones only      |
| External wiki (Confluence)  | Feature-rich                 | Disconnected from code, manual sync | Single-source-of-truth impossible |
| Pure arc42                  | Recognised standard          | SW-oriented only           | Not adapted to HW             |

## Consequences

### Positive
- Stable and predictable folder structure from day 1.
- Toolable traceability (traceability-matrix.md).

### Watchpoints
- Discipline required not to duplicate content between domains.
- The templates in `meta/templates/` must be kept up to date.

## Related ADRs

- _None yet_

## Revisions

| Date       | Version | Author | Change      |
|------------|---------|--------|-------------|
| YYYY-MM-DD | 1.0     | …      | Creation    |
