# API Contracts

<!--
Software interface contracts: REST, GraphQL, WebSocket, gRPC, MQTT, etc.
For each endpoint, define: method, path, payload, return codes.
Generate or link to the OpenAPI spec if applicable.
-->

## Conventions

- Versioning: `/api/v{N}/...`
- Format: JSON (UTF-8)
- Authentication: Bearer JWT (header `Authorization`)
- Errors: unified format `{ "code": "ERR_XXX", "message": "...", "details": {} }`
- Rate limiting: …

## OpenAPI reference

<!--
If an OpenAPI spec exists, link to it here:
-->
> OpenAPI spec: `docs/architecture/interfaces/openapi.yaml` _(to be created)_

---

## Endpoints

### [Domain 1 — e.g. Authentication]

#### `POST /api/v1/auth/login`

| Field        | Value                           |
|--------------|---------------------------------|
| **Purpose**  | Authenticate a user             |
| **Auth**     | Not required                    |
| **Content-Type** | `application/json`          |

**Request body**
```json
{
  "email": "string",
  "password": "string"
}
```

**Responses**

| Code | Description                        | Body (example)                              |
|------|------------------------------------|---------------------------------------------|
| 200  | Success                            | `{ "token": "...", "expiresIn": 3600 }`     |
| 400  | Invalid payload                    | `{ "code": "ERR_VALIDATION", "message": "…" }` |
| 401  | Incorrect credentials              | `{ "code": "ERR_UNAUTHORIZED" }`            |

**Traced requirement**: SW-I001

---

### [Domain 2 — e.g. Main resource]

#### `GET /api/v1/{resource}`

<!--
Repeat the pattern above for each endpoint.
-->

---

## Webhooks / Events (if applicable)

| Event        | Trigger                       | Payload (schema)               |
|-------------|-------------------------------|--------------------------------|
| …           | …                             | …                              |

## Reference

- SW architecture: [../sw-architecture.md](../sw-architecture.md)
- Interface requirements: [../../requirements/sw-requirements.md](../../requirements/sw-requirements.md)
