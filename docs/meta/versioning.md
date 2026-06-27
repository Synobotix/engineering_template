# Versioning

<!--
Product and document versioning scheme, baseline and archiving policy.
-->

## Product versioning (Software)

Format: **`vMAJOR.MINOR.PATCH`** (Semantic Versioning — semver.org)

| Segment | Increment when…                                                   |
|---------|-------------------------------------------------------------------|
| MAJOR   | Incompatible API change / major rework                            |
| MINOR   | New backwards-compatible feature                                  |
| PATCH   | Backwards-compatible bug fix                                      |

Examples:
- `v1.0.0` — first stable release
- `v1.1.0` — new feature added
- `v1.1.1` — bug fix

### Git tags

```sh
git tag -a v1.0.0 -m "Release v1.0.0 — Customer acceptance"
git push origin v1.0.0
```

## Hardware versioning

Format: **`HW-vMAJOR.MINOR`**

| Segment | Increment when…                                                        |
|---------|------------------------------------------------------------------------|
| MAJOR   | Critical component change, stackup modification, major ECO             |
| MINOR   | Errata fix, non-structural modification                                |

CAD files and Gerbers are archived per version in `hardware/releases/HW-vX.Y/`.

## Document versioning

Format: **`MAJOR.MINOR`**

| Segment | Increment when…                                                       |
|---------|-----------------------------------------------------------------------|
| MAJOR   | Structural change (section added/removed, rebaseline)                 |
| MINOR   | Correction, minor update                                              |

Each formal document includes a revisions table at the bottom.

## Baselines

A baseline freezes a set of documents at a milestone. It is created via a Git tag.

| Baseline | Milestone | Git tag         | Included documents              |
|----------|-----------|-----------------|---------------------------------|
| BL-001   | M1        | `bl-srr-v1`     | requirements/* v1.0             |
| BL-002   | M3        | `bl-cdr-v1`     | requirements/* + architecture/* + design/* |
| BL-003   | M6        | `bl-accept-v1`  | All documents                   |

### Creating a baseline

```sh
# Tag the current commit
git tag -a bl-srr-v1 -m "Baseline SRR — system requirements v1.0"
git push origin bl-srr-v1
```

## Archiving policy

- `Obsolete` documents are kept in the repo (never deleted) — they may be required for audits.
- Large binaries (Gerbers, CAD, PDF reports) are stored in `hardware/releases/` or via Git LFS.
- Minimum retention period is **10 years** after product end of life (adapt per regulatory domain).

## Reference

- Change management: [../project/change-management.md](../project/change-management.md)
- Documentation guide: [documentation-guide.md](documentation-guide.md)
