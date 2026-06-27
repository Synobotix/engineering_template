# Coding Conventions

<!--
Conventions specific to THIS project — deltas from the global guidelines.
Do not copy rules already in the global guidelines; link to them instead.
-->

## Global reference

> Base standards are defined in `DEV.md` (project root).
> This file only lists project-specific specifics.

## Naming

| Element              | Convention         | Example                     |
|----------------------|--------------------|-----------------------------|
| Component file       | PascalCase         | `UserProfile.tsx`           |
| Utility file         | camelCase          | `formatDate.ts`             |
| React hook           | camelCase + `use`  | `useAuthState.ts`           |
| Test file            | same name + `.test`| `UserProfile.test.tsx`      |
| Variable             | camelCase          | `const userEmail`           |
| Global constant      | SCREAMING_SNAKE    | `const MAX_RETRY = 3`       |
| Type / Interface     | PascalCase         | `type UserDto = …`          |

## File structure

```
src/
├── application/       # Use cases (no dependency on infrastructure)
├── domain/            # Entities, value objects, pure business rules
├── interfaces/        # Controllers, DTOs, validators
└── infrastructure/    # DB, cache, external API clients
```

## TypeScript rules

- `strict: true` required — no `any`, no `as unknown as`.
- Explicit types on all public interfaces.
- Prefer `type` over `interface` except for contract extension.
- No `enum` — use `as const` + `type`.

## React rules

- Functional components only.
- One component per file.
- Explicitly typed props (no inference on public components).
- Extract to custom hook as soon as logic exceeds ~20 lines in a component.

## Linting and formatting

| Tool       | Config                 | Command                     |
|------------|------------------------|-----------------------------|
| ESLint     | `.eslintrc.json`       | `npm run lint`              |
| Prettier   | `.prettierrc`          | `npm run format`            |
| TypeScript | `tsconfig.json`        | `npm run typecheck`         |

All three checks block CI — no merge if any of them fails.

## Dependency management

- Any new dependency must be discussed in the PR.
- `devDependencies` for anything not going to production.
- No dependency without an active maintainer (check `npm audit`).
