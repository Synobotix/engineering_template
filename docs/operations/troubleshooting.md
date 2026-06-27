# Troubleshooting

<!--
Diagnostic guide — structure: symptom → diagnosis → resolution → verification.
Each entry must be actionable by someone new to the system.
-->

## Problem index

| Symptom                             | Section                      |
|-------------------------------------|------------------------------|
| Application does not start          | [→](#application-does-not-start) |
| Database connection error           | [→](#database-connection-error) |
| API returns 5xx errors              | [→](#api-returns-5xx-errors) |
| Frontend does not load              | [→](#frontend-does-not-load) |
| Degraded performance                | [→](#degraded-performance) |

---

## Application does not start

**Symptoms**: Server stops immediately at startup; logs show a fatal error.

**Diagnosis**:
```sh
docker compose logs server --tail 50
docker compose ps
```

**Common causes and resolutions**:

| Cause                          | Log indicator               | Resolution                             |
|-------------------------------|-----------------------------|-----------------------------------------|
| Missing environment variable  | `Missing env: DATABASE_URL` | Check `.env`, restart                  |
| Port already in use           | `EADDRINUSE :::5000`        | `lsof -i :5000` then `kill -9 <PID>`  |
| Database unreachable          | `Connection refused`        | See next section                       |

---

## Database connection error

**Symptoms**: `Connection refused` or `ECONNREFUSED` error in logs.

**Diagnosis**:
```sh
docker compose ps db
docker compose logs db --tail 50
```

**Resolution**:
```sh
# If DB container is not running:
docker compose up -d db

# If DB is running but unreachable:
docker compose restart db

# Check DATABASE_URL in .env:
echo $DATABASE_URL
```

---

## API returns 5xx errors

**Symptoms**: API requests return HTTP 500/502/503.

**Diagnosis**:
```sh
docker compose logs server -f --tail 100
# Find stack trace
docker compose logs server 2>&1 | grep -A 10 "Error"
```

**Resolution**:
1. Identify the error code and stack trace in the logs.
2. Check dependencies (DB, external services).
3. If undetermined → rollback to the previous stable version.

---

## Frontend does not load

**Symptoms**: Blank page, error in browser console.

**Diagnosis**:
- Open DevTools (F12) → Console + Network
- Check API is accessible: `curl http://localhost:5000/api/health`

**Common causes**:

| Cause                     | Resolution                                 |
|--------------------------|---------------------------------------------|
| Frontend build failed     | `docker compose logs client`               |
| API proxy misconfigured   | Check `REACT_APP_API_URL` in `.env`        |
| Browser cache             | Ctrl+Shift+R (hard refresh)                |

---

## Degraded performance

**Symptoms**: High API latency (P99 > 2 s), CPU > 80 %.

**Diagnosis**:
```sh
docker stats                               # Real-time resources
docker compose logs server | grep slow     # Slow queries (if logged)
```

**Actions**:
1. Identify the request or service causing the issue.
2. Check database indexes.
3. Increase container resource allocation if needed.
4. Open a ticket if the issue persists.

---

## Reference

- Runbook: [runbook.md](runbook.md)
- Deployment / Rollback: [deployment.md](deployment.md)
- Application error codes: [user-manual.md](user-manual.md#error-codes)
