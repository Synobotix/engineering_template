# Runbook

<!--
Daily operations, monitoring, and incident response.
A runbook must be usable by someone new to the system.
Each procedure: context → symptoms → diagnosis → resolution → verification.
-->

## On-call contacts

| Role          | Name | Contact         | Availability    |
|---------------|------|-----------------|-----------------|
| Primary ops   | …    | …               | 24/7            |
| Dev on-call   | …    | …               | Business hours  |
| Escalation    | …    | …               | If ops absent   |

## Monitoring

| Metric                | Source / Dashboard | Alert threshold | Action if exceeded         |
|-----------------------|-------------------|-----------------|----------------------------|
| Server CPU            | …                 | > 80 % for 5 min| Investigate, scale if needed |
| Memory                | …                 | > 85 %          | Investigate memory leak    |
| API latency P99       | …                 | > 2 s           | P2 incident                |
| HTTP 5xx errors       | …                 | > 1 %           | P1 incident                |
| Disk space            | …                 | > 80 %          | Log cleanup / extension    |

## Common procedures

### Restart a service

```sh
docker compose restart <service>     # server | client | db
docker compose logs -f <service>     # verify startup
```

### View logs

```sh
docker compose logs -f server --tail 200
# Filter errors:
docker compose logs server 2>&1 | grep -i error
```

### Run a database migration

```sh
# ALWAYS back up first
docker compose exec db pg_dump -U $DB_USER $DB_NAME > backup_$(date +%Y%m%d).sql

docker compose exec server npm run db:migrate
```

### Deployment rollback

> See [deployment.md](deployment.md) — Rollback section.

## Incident management

### Classification

| Priority | Criterion                                       | Response SLA | Resolution SLA |
|:--------:|-------------------------------------------------|:------------:|:--------------:|
| P1       | System inaccessible / data loss                 | 15 min       | 4 h            |
| P2       | Major feature degraded                          | 30 min       | 8 h            |
| P3       | Minor feature affected                          | 4 h          | 48 h           |

### Incident procedure

1. Detect and qualify (P1/P2/P3)
2. Notify stakeholders
3. Diagnose — use [troubleshooting.md](troubleshooting.md)
4. Mitigate (rollback if necessary)
5. Resolve and verify
6. Write a post-mortem (P1/P2 incidents)

## Reference

- Deployment: [deployment.md](deployment.md)
- Troubleshooting: [troubleshooting.md](troubleshooting.md)
- Maintenance: [maintenance.md](maintenance.md)
