# CLAUDE.local.md

> Project-specific overrides for Claude Code.
> See `CLAUDE.md` for routing rules, authority, and flow semantics.

## Identity

- **Project**: engineering_template
- **Author/Maintainer**: Rémi Boivin
- **License**: See LICENSE
- **Repository purpose**: Generic C++ project template with hexagonal architecture

## Stack

- Language: C++
- Runtime: Native (CMake build system)
- Testing: (to be defined per project)
- CI: GitHub Actions
- Distribution: (to be defined per project)

## Architecture Triggers (project-specific)

In addition to `CLAUDE.md` triggers, `$architect` is required before:

- Any change to `src/domain/ports/` interfaces
- Any new adapter added under `src/infrastructure/`
- Any new use case added under `src/application/`

## Security Triggers (project-specific)

In addition to `CLAUDE.md` triggers, `$security` is required before:

- Any external I/O adapter (network, filesystem, IPC)

## Project-Specific Invariants

| ID | Invariant |
| --- | --- |
| I-P-01 | Domain layer must not depend on infrastructure or application layers |
| I-P-02 | All cross-boundary communication goes through port interfaces |
| I-P-03 | `src/domain/` contains no framework or I/O includes |

## Forbidden Areas (project-specific)

Require explicit `$architect` approval:

- `src/domain/ports/` (port interface definitions)
- `src/domain/entities/` (core domain model)
- `CMakeLists.txt` root configuration
