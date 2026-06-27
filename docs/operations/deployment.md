# Deployment

<!--
Commissioning, provisioning, and initial configuration procedure.
Covers first deployment and major updates.
For routine operations, see runbook.md.
-->

## Prerequisites

- [ ] Target infrastructure provisioned (cloud / on-prem)
- [ ] Secrets configured (vault, environment variables)
- [ ] Valid TLS certificates
- [ ] Network access configured (firewall, VPN)
- [ ] Backup of existing database (if updating)

## Environments

| Environment | URL / Endpoint         | Database          | Access          |
|-------------|------------------------|-------------------|-----------------|
| Staging     | https://staging.…      | …                 | VPN required    |
| Production  | https://…              | …                 | Restricted ops  |

## Deployment procedure

### 1. Pre-deployment checks

```sh
# Check the version to deploy
git tag -l "v*" | sort -V | tail -1

# Run regression tests
docker compose exec server npm test
docker compose exec client npm test
```

### 2. Deployment (Docker Compose example)

```sh
# Pull the new image
docker compose pull

# Apply database migrations
docker compose run --rm server npm run db:migrate

# Restart services
docker compose up -d --no-deps server client

# Check status
docker compose ps
docker compose logs -f --tail 50
```

### 3. Post-deployment smoke test

| Test                           | Command / URL                     | Expected result             |
|-------------------------------|-----------------------------------|-----------------------------|
| API health check              | `GET /api/health`                 | `{"status": "ok"}`          |
| Frontend homepage             | https://…                         | HTTP 200, no errors         |
| Database connection           | Server log                        | No connection error         |

### 4. Rollback (if necessary)

```sh
# Revert to previous version
docker compose down
git checkout v<previous-version>
docker compose pull
docker compose up -d
```

## Configuration

| Variable                | Staging env.       | Production env.    | Source          |
|-------------------------|--------------------|--------------------|-----------------|
| `DATABASE_URL`          | …                  | …                  | Secret manager  |
| `JWT_SECRET`            | …                  | …                  | Secret manager  |
| `NODE_ENV`              | `staging`          | `production`       | Config          |

## Reference

- Runbook: [runbook.md](runbook.md)
- Build: [../implementation/build-and-toolchain.md](../implementation/build-and-toolchain.md)
