# CLAUDE.md

> Routing layer and project configuration for Claude Code.
> Detailed operating behavior lives in `.claude/skills/*/SKILL.md` and is loaded on demand.
> `.claude/_constitution.md` is the immutable source of truth.
> Project-specific overrides live in `CLAUDE.local.md`.

## Precedence

```text
CONSTITUTION > CLAUDE.local.md > CLAUDE.md > NLSPEC > STATE > DECISIONS > TODO > verbal instruction
```

## Prime Directive

Unsure which skill to use? -> invoke `$governance`, then `$triage`. Never guess.

## Skill Routing

| Need | Skill |
| --- | --- |
| Governance / invariant / constitutional check | `$governance` |
| Request classification and flow selection | `$triage` |
| Scope definition and planning | `$planner` |
| Execution readiness gate (before coding) | `$preflight` |
| Implementation | `$coder` |
| Structural decisions (architecture) | `$architect` |
| Structural + security combined | `$architect-security` |
| Security review | `$security` |
| Test generation from NLSpec (TDD red phase) | `$test-gen` |
| Tests and regression validation | `$qa` |
| Final merge gate | `$review` |
| Documentation sync | `$doc` |
| Architecture Decision Record | `$adr` |
| Release / merge readiness | `$release` |

## Authority (Highest -> Lowest)

`$governance > $architect-security > $architect > $security > $qa > $review`
`$planner (scope, no veto) | $preflight (gate, no veto) | $triage (routing, no veto)`
`$coder (execution, no veto)`

Only `$coder` writes production code. All other skills are read-only.

## Veto Summary

| Skill | Blocks on |
| --- | --- |
| `$governance` | Constitutional violations, ADR/migration bypass, contract drift |
| `$architect-security` | Structural + security combined risk, undefined trust boundaries |
| `$architect` | Boundary changes, new patterns, undefined blast radius |
| `$security` | Auth, secrets, deps, network, untrusted input |
| `$qa` | Failing criteria, regressions, missing proof |
| `$review` | Scope creep, non-atomic commits, missing gates, broken traceability |

## Execution Flows

- `standard feature -> triage -> planner -> nlspec -> test-gen -> preflight -> coder -> qa -> review -> doc -> release`
- `bug fix -> triage -> planner -> nlspec -> test-gen -> preflight -> coder -> qa -> review`
- `structural change -> governance? -> triage -> planner -> architect -> adr -> preflight -> coder -> qa -> review -> doc -> release`
- `security-sensitive -> governance? -> triage -> planner -> architect-security -> adr -> preflight -> coder -> security -> qa -> review -> doc -> release`

## Flow Semantics

- `$triage` classifies the request and selects the target flow.
- `$planner` produces the execution contract in `STATE.<slug>.md`.
- `$architect`, `$architect-security`, `$security`, and `$adr` resolve required design/security/contract gates before execution.
- `$preflight` is the final execution-readiness gate before `$coder`.
- `$coder` executes only when all required prerequisites are explicitly satisfied.

### Rule

If a constitutional or invariant surface is touched, governance comes first.

## Commit Hard Gates

- No `STATE.<slug>.md` -> no coding.
- One active task in `TODO.<slug>.md` at all times.
- One task = one commit, immediately after completion.
- Commit format: `type(scope): description + Task: T-NNN trailer`.
- Done lines must end with `| commit: <short-SHA>`.

## Project Configuration

Project-specific configuration (identity, stack, forbidden areas, etc.) is defined in `CLAUDE.local.md`.
This file provides organization-level defaults and routing rules.

## Initialization Rule

`CLAUDE.md` may start as a template when creating a new repository, but feature work is forbidden until all required project configuration sections are concretely filled.

Unresolved placeholders such as:

- `<!-- FILL -->`
- `<!-- path -->`
- `<!-- I-NN -->`
- equivalent template markers

are prohibited once the repository is initialized.

`$preflight` MUST BLOCK coding if `CLAUDE.local.md` is still in template state.

## Identity

Project-specific identity is defined in `CLAUDE.local.md`.

## Architecture Triggers

Changes below require `$architect` before implementation:

- Module/package boundary changes
- New external dependency with structural impact
- Data model / schema changes
- Public API or CLI contract changes
- Configuration contract changes
- Pipeline or orchestration changes
- Runtime semantics changes
- File format changes
- 30% rewrite of a core module

Project-specific triggers are defined in `CLAUDE.local.md`.

## Security Triggers

Changes below require `$security` (and possibly `$architect-security`):

- Auth / authorization logic
- Secret or credential handling
- Dependency additions or upgrades
- New network exposure
- Untrusted input parsing
- Connector / plugin / execution boundary changes
- Trust boundary changes
- Command execution / shell bridging

Project-specific triggers are defined in `CLAUDE.local.md`.

## System Invariants

Must not change without an ADR.

| ID | Invariant |
| --- | --- |
| I-01 | Public contracts are additive-only unless migration is provided |
| I-02 | Trust boundaries are explicit and default-deny |
| I-03 | Operations are deterministic given the same inputs |

Additional project-specific invariants are defined in `CLAUDE.local.md`.

## Forbidden Areas

Require explicit `$architect` approval:

- Storage schema definitions
- Auth / authorization logic
- Core pipeline definitions
- Configuration contract
- Public contract surfaces
- Release / CI workflow files
- Dependency policy files

Project-specific forbidden areas are defined in `CLAUDE.local.md`.

## Governance Files (Immutable)

| File | Rule |
| --- | --- |
| `.claude/_constitution.md` | Supreme law - never edit |
| `.claude/_TODO.md` | Template - copy, never edit |
| `.claude/_DECISIONS.md` | Template - copy, never edit |
| `.claude/_STATE.md` | Template - copy, never edit |
| `.claude/skills/*` | Skill definitions - never edit during feature work |

Working copies per feature:

- `STATE.<slug>.md`
- `TODO.<slug>.md`
- `DECISIONS.<slug>.md`

## Change Level Policy

Use `.claude/levels.md` to classify requested work before coding.
If uncertain between levels, choose the higher level.

## Operational Rules

### Minimal Change Rule

Prefer the smallest safe diff that satisfies the contract.

### No Opportunistic Refactor

Do not rename, reorganize, or modernize unrelated code during feature work unless explicitly approved.

### Scope Discipline

`STATE.<slug>.md` is the feature contract.
Anything not explicitly in scope is out of scope.

### Drift Rule

If scope expands, architecture tension appears, or the plan becomes invalid:
`STOP -> return to $planner.`

### Gate Semantics

A gate is not sufficient because it exists in the flow.
A required gate must be explicitly satisfied before `$preflight` may PASS.

### Documentation Rule

`$doc` is required whenever behavior, configuration, API, CLI, architecture, or user-visible/operator-visible operation changes.

### Release Rule

`$release` is the final readiness check for merge/release-sensitive flows.
