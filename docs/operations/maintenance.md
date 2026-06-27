# Maintenance

<!--
Preventive and corrective maintenance: software (updates, dependencies)
and hardware (parts, consumables, periodic inspections).
-->

## Software maintenance

### Maintenance schedule

| Frequency    | Action                                              | Owner       | Tool / Command            |
|--------------|-----------------------------------------------------|-------------|---------------------------|
| Weekly       | Check dependency security alerts                    | Ops / Dev   | `npm audit`               |
| Monthly      | Update minor dependencies                           | Dev         | `npm update`              |
| Quarterly    | Review major dependencies                           | Tech Lead   | Changelog analysis        |
| Annual       | Infrastructure review (OS, Docker, DB)              | Ops         | Update plan               |

### Backup management

| Data type           | Backup frequency | Retention | Location        | Restore verification |
|--------------------|:----------------:|:---------:|-----------------|:--------------------:|
| Database            | Daily            | 30 days   | …               | Monthly              |
| Configuration files | Each change      | Git       | Repo            | Automatic            |
| Logs                | Continuous       | 90 days   | …               | —                    |

### Update procedure

```sh
# 1. Backup
docker compose exec db pg_dump -U $DB_USER $DB_NAME > backup_$(date +%Y%m%d).sql

# 2. Update dependencies (npm example)
npm audit fix
npm update

# 3. Tests before deployment
npm test

# 4. Deployment → see deployment.md
```

## Hardware maintenance (if applicable)

### Preventive maintenance plan

| Component           | Action                    | Frequency         | Intervention criteria    |
|---------------------|--------------------------|-------------------|--------------------------|
| Fan                 | Cleaning / replacement   | … hours or … years | Abnormal noise, high temp |
| Battery / Backup    | Capacity test             | Annual            | Capacity < 80 %          |
| Sealing gaskets     | Inspection                | … years           | Cracking, hardening      |
| Connectors          | Contact cleaning          | …                 | Oxidation, intermittent contact |

### Recommended spare parts

| Part              | MPN            | Recommended qty | Supplier | Lead time      |
|-------------------|----------------|:---------------:|----------|:--------------:|
| …                 | …              | …               | …        | … weeks        |

## MTBF / MTTR targets

| Indicator | Target value | Calculation method |
|-----------|:-----------:|-------------------|
| MTBF      | … hours     | …                 |
| MTTR      | … hours     | …                 |

## End of life

- Guaranteed support duration: … years
- Secure data erasure procedure: …
- Recycling / WEEE: …

## Reference

- Runbook: [runbook.md](runbook.md)
- HW bring-up: [../verification/hw-bring-up.md](../verification/hw-bring-up.md)
