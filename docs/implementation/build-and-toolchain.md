# Build and Toolchain

<!--
Everything needed to make the build reproducible by anyone, on any authorised machine.
Golden rule: a new developer must be able to build in under 30 minutes.
-->

## Reference environment

| Tool            | Required version | Installation                          |
|-----------------|------------------|---------------------------------------|
| Node.js         | ≥ 18.x LTS       | `nvm install --lts`                   |
| npm             | ≥ 9.x            | included with Node.js                 |
| Docker          | ≥ 24.x           | [docs.docker.com](https://docs.docker.com) |
| Docker Compose  | ≥ 2.x            | included with Docker Desktop          |
| Git             | ≥ 2.x            | system package                        |

> Quick check:
> ```sh
> node -v && npm -v && docker -v && docker compose version && git --version
> ```

## Quick start (Docker)

```sh
git clone https://github.com/Synobotix/engineering_template.git && cd <!-- repo name -->
docker compose up -d
# Client : http://localhost:3000
# API    : http://localhost:5000
```

## Environment variables

| Variable          | Required | Default value  | Description                     |
|-------------------|----------|----------------|---------------------------------|
| `NODE_ENV`        | No       | `development`  | Runtime environment             |
| `DATABASE_URL`    | Yes      | —              | PostgreSQL connection URL       |
| `JWT_SECRET`      | Yes      | —              | JWT signing key                 |
| `PORT`            | No       | `5000`         | API server port                 |

Copy `.env.example` → `.env` and fill in the required values.

## Build commands

| Command                              | Usage                              |
|--------------------------------------|------------------------------------|
| `docker compose up -d`               | Start all services                 |
| `docker compose logs -f`             | Follow logs                        |
| `docker compose down`                | Stop services                      |
| `docker compose build --no-cache`    | Force rebuild                      |
| `docker compose exec server npm test`| Run backend tests                  |
| `docker compose exec client npm test`| Run frontend tests                 |

## CI pipeline

<!--
Describe pipeline steps (GitHub Actions, GitLab CI…).
Link to the configuration file.
-->

| Step       | Trigger             | Config file                    |
|------------|---------------------|-------------------------------|
| Lint       | Push / PR           | `.github/workflows/ci.yml`    |
| Tests      | Push / PR           | `.github/workflows/ci.yml`    |
| Build      | Push to `main`      | `.github/workflows/ci.yml`    |
| Deploy     | Tag `v*`            | `.github/workflows/deploy.yml`|

## Dependency management

- Use `package-lock.json` (npm) — commit it to the repo.
- Update with `npm audit fix` as priority; any dependency with a critical vulnerability blocks the merge.
- Production dependencies separated from development dependencies (`devDependencies`).

## Reference

- `DEV.md` (project root) — detailed local development guide
- `GIT.md` (project root) — Git workflow
