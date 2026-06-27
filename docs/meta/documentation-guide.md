# Documentation Guide

<!--
This file defines the documentation conventions for this project.
Read before creating or modifying any document in docs/.
-->

## Principles

1. **Docs-as-code** — every `.md` file lives in the repo, versioned with the code. No doc in an external tool unless linked here.
2. **Single source of truth** — a fact is defined in exactly one place; elsewhere it is referenced with a relative link.
3. **Traceability** — every requirement points to its test; every test points to its requirement.
4. **Living docs** — an outdated doc is worse than no doc. If you cannot maintain a document, delete it.

## Folder structure

```
docs/
├── overview/           # Project context (charter, glossary, stakeholders)
├── requirements/       # Requirements and traceability
├── architecture/       # Architecture and decisions (ADR)
│   ├── interfaces/     # ICD — contracts between blocks
│   └── decisions/      # ADR — one decision per file
├── design/             # Detailed design
├── implementation/     # Build, BOM, manufacturing, coding conventions
├── verification/       # V&V plan, test cases, reports, coverage
├── safety-compliance/  # HARA, FMEA, safety concept, security, compliance
├── operations/         # Deployment, runbook, maintenance, user manual
├── project/            # Plan, risks, change management
└── meta/               # This guide, templates, versioning
```

## Document format

### Mandatory header (formal documents)

```markdown
# Document title

| Version | Date       | Author     | Status  |
|---------|------------|------------|---------|
| 1.0     | YYYY-MM-DD | First Last | Draft   |
```

### Status levels

| Status      | Meaning                                               |
|-------------|-------------------------------------------------------|
| Draft       | Being written — do not use as reference               |
| In Review   | Submitted for review                                  |
| Approved    | Validated — may be baselined                          |
| Baselined   | Frozen at a milestone — change via ECR only           |
| Obsolete    | Superseded — keep in archive, do not delete           |

## Writing conventions

- **Language**: English (project technical language)
- **Tone**: direct, impersonal. No "we think that…" — write facts and SHALLs.
- **Requirements**: use EARS format or SHALL. E.g.: `The system SHALL [action] when [condition].`
- **Links**: always relative (never absolute URLs to repo files).
- **Diagrams**: prefer Mermaid (inline) for simple diagrams; STEP/PDF for technical drawings.

## Available templates

| Template                    | Usage                                          | Location |
|-----------------------------|------------------------------------------------|----------|
| ADR template                | New architecture decision                      | [templates/adr-template.md](templates/adr-template.md) |
| ICD template                | New interface (elec / mech / API)              | [templates/icd-template.md](templates/icd-template.md) |
| Test case template          | New test case                                  | [templates/test-case-template.md](templates/test-case-template.md) |

## Document lifecycle

```
Need identified → Create from template → Draft → PR review → Approved → [Baseline at milestone] → Maintenance via ECR
```

## Reference

- Change management: [../project/change-management.md](../project/change-management.md)
- Versioning: [versioning.md](versioning.md)
