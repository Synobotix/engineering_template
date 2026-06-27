# Security

<!--
System cybersecurity: threat model, attack surface, hardening measures.
Recommended method: STRIDE + attack surface analysis.
Distinct from safety (functional safety) — both are required.
-->

## 1. Scope and assets to protect

| Asset                    | Value / Criticality | Consequence if compromised       |
|--------------------------|---------------------|----------------------------------|
| User data                | High                | GDPR violation, loss of trust    |
| Authentication keys      | Critical            | System takeover                  |
| Firmware / Software      | High                | Behaviour modification           |
| Network communication    | Medium              | Interception, replay             |

## 2. Threat model (STRIDE)

| ID    | Threat (STRIDE)       | Attack surface    | Vector              | Probability | Impact | Risk |
|-------|-----------------------|-------------------|---------------------|:-----------:|:------:|:----:|
| T-001 | Spoofing              | REST API          | Forged JWT          | …           | …      | …    |
| T-002 | Tampering             | Firmware update   | Unsigned OTA        | …           | …      | …    |
| T-003 | Information Disclosure| DB                | SQL Injection        | …           | …      | …    |
| T-004 | Denial of Service     | API               | Missing rate limit  | …           | …      | …    |
| T-005 | Elevation of Privilege| Auth              | IDOR, missing RBAC  | …           | …      | …    |

## 3. Implemented security measures

| Domain             | Measure                                           | Status  | Associated test |
|--------------------|---------------------------------------------------|---------|----------------|
| Authentication     | JWT + refresh token rotation                      | ✅      | TC-SEC-001     |
| Authorisation      | RBAC — server-side verification                   | ✅      | TC-SEC-002     |
| Transport          | TLS 1.3 mandatory                                 | ✅      | TC-SEC-003     |
| Secret storage     | Environment variables / Vault — no plaintext secrets | ✅   | —              |
| Injection          | Prepared queries (ORM), input validation          | ✅      | TC-SEC-004     |
| Rate limiting      | … req/min per IP + per token                      | 🚧 WIP | —              |
| Security logs      | Audit trail for sensitive actions                 | 🚧 WIP | —              |
| OTA update         | Firmware signing (if applicable)                  | …       | —              |

## 4. Vulnerability management policy

- `npm audit` run at each CI — critical CVE blocks the merge.
- Dependencies with CVE CVSS ≥ 7.0: fix within 7 days.
- Vulnerability reporting: see `SECURITY.md` at the repo root.

## 5. Security tests

| Test type          | Frequency            | Tool / Method            | Owner       |
|--------------------|----------------------|--------------------------|-------------|
| Static analysis    | Each PR              | ESLint security, SonarQube | CI         |
| Dependencies       | Each PR              | `npm audit`              | CI          |
| Application pentest| Before each release  | OWASP ZAP + manual       | QA / Sec    |
| Security code review | Pull Request       | OWASP Top 10 checklist   | Dev + Reviewer |

## Reference

- HARA: [hazard-analysis.md](hazard-analysis.md)
- Compliance: [compliance.md](compliance.md)
- Security requirements: [../requirements/system-requirements.md](../requirements/system-requirements.md)
