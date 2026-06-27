# Traceability Matrix

<!--
Backbone of the V-model. Each row proves that a need is:
  1. captured in a system requirement
  2. allocated to a SW or HW component
  3. covered by at least one test

RULE: any requirement without a test is a gap that must be justified.
RULE: any test without a traced requirement is an orphan test to remove or link.
-->

## How to read the table

| Column          | Source                                              |
|-----------------|-----------------------------------------------------|
| Need (SN-)      | [stakeholder-needs.md](stakeholder-needs.md)        |
| System req (SYS-) | [system-requirements.md](system-requirements.md)  |
| SW req (SW-)    | [sw-requirements.md](sw-requirements.md)            |
| HW req (HW-)    | [hw-requirements.md](hw-requirements.md)            |
| Component       | [../architecture/system-architecture.md](../architecture/system-architecture.md) |
| Test (TC-)      | [../verification/test-cases/](../verification/test-cases/) |

---

## Need → Requirement → Test matrix

| Need    | SYS req  | SW / HW req | Component       | Test(s)         | Coverage   |
|---------|----------|-------------|-----------------|-----------------|------------|
| SN-001  | SYS-F001 | SW-F001     | …               | TC-001, TC-002  | ✅ Covered |
| SN-002  | SYS-F002 | HW-E001     | …               | TC-010          | ✅ Covered |
| SN-010  | SYS-P001 | SW-P001     | …               | TC-020          | ⚠️ Partial |
| SN-020  | SYS-S001 | SW-S001     | …               | —               | ❌ Not covered |

<!--
Legend:
✅ Covered — at least one associated PASS test
⚠️ Partial — test exists but coverage is incomplete (justification required)
❌ Not covered — no test (must be justified or planned)
-->

## Requirements without tests (gaps)

| Requirement | Justification / Plan                        | Owner | Target date |
|-------------|---------------------------------------------|-------|-------------|
| …           | Test planned during field validation phase  | …     | YYYY-MM-DD  |

## Orphan tests (without requirement)

| Test | Action required                             |
|------|---------------------------------------------|
| …    | Link to a requirement or remove             |
