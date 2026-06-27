# ICD — [Interface name]

| Field            | Value                                            |
|------------------|--------------------------------------------------|
| **ID**           | ICD-XXXX                                         |
| **Date**         | YYYY-MM-DD                                       |
| **Version**      | 0.1                                              |
| **Type**         | API / Electrical / Mechanical / Protocol / Mixed |
| **Producer**     | Subsystem / Issuing team                         |
| **Consumer**     | Subsystem / Receiving team                       |
| **Status**       | Draft / Baselined / Deprecated                   |

---

## 1. Purpose

<!--
Describe in 2-3 sentences the role of this interface:
- what it carries (data, energy, mechanical signal…)
- who uses it and in what context
-->

## 2. References

| Document              | Version | Link / location |
|-----------------------|---------|-----------------|
| Source requirement    | —       | [REQ-XXXX](../../requirements/system-requirements.md) |
| Parent architecture   | —       | [system-architecture.md](../../architecture/system-architecture.md) |

## 3. Interface definition

### 3.1 Signals / Parameters / Endpoints

<!--
Adapt the table to the interface type:
- REST API → method, path, payload, return code
- Electrical → signal name, type, logic level, max current, connector, pin
- Mechanical → fixing point, material, tolerance, admissible load
-->

| ID       | Name        | Direction       | Type / Format | Nominal value | Limits        | Description             |
|----------|-------------|-----------------|---------------|---------------|---------------|-------------------------|
| SIG-001  | …           | Prod → Cons     | …             | …             | min … max …   | …                       |

### 3.2 Protocol / Sequencing

<!--
Sequence diagram or temporal description if applicable.
For an API: authentication constraints, rate-limit, ordering.
For a bus: timing, arbitration, frame format.
-->

### 3.3 Error handling

| Error case          | Expected behaviour (producer)     | Expected behaviour (consumer)       |
|---------------------|-----------------------------------|-------------------------------------|
| …                   | …                                 | …                                   |

## 4. Non-functional constraints

| Attribute         | Target value | Note                  |
|-------------------|--------------|-----------------------|
| Max throughput    | …            | …                     |
| Max latency       | …            | …                     |
| Availability      | …            | …                     |
| Security          | …            | Encryption, auth…     |

## 5. Validation procedure

<!--
How to prove that the interface meets this contract (conformance test, bench, simulation).
Link to the corresponding test case in docs/verification/test-cases/.
-->

- Associated test: [TC-XXXX](../../verification/test-cases/)

## 6. Revisions

| Date       | Version | Author     | Change      |
|------------|---------|------------|-------------|
| YYYY-MM-DD | 0.1     | First Last | Creation    |
