# Gouvernance IA — ISO 42001

| Version | Date       | Auteur | Statut |
|---------|------------|--------|--------|
| 0.1     | YYYY-MM-DD |        | Draft  |

Vue d'ensemble du Système de Management de l'IA (AIMS) conforme à ISO/IEC 42001:2023.

---

## Périmètre de cette section

ISO/IEC 42001:2023 est le premier standard international de système de management spécifiquement dédié à l'IA. Il définit les exigences pour établir, implémenter, maintenir et améliorer continuellement un AIMS au sein d'une organisation.

Cette section documente la mise en œuvre de l'AIMS pour ce projet. Elle est organisée selon les clauses du standard.

## Mapping Clauses → Documents

| Clause ISO 42001 | Titre | Document |
|---|---|---|
| 4 | Contexte de l'organisation | [context-and-scope.md](context-and-scope.md) |
| 5 | Leadership et politique IA | [leadership-and-policy.md](leadership-and-policy.md) |
| 6.1 | Évaluation des risques et impacts | [risk-and-impact.md](risk-and-impact.md) |
| 6.2 | Objectifs IA | [ai-objectives.md](ai-objectives.md) |
| 7 | Support (ressources, compétences, communication) | [support.md](support.md) |
| 8 | Opérations et cycle de vie du système IA | [ai-lifecycle.md](ai-lifecycle.md) |
| 8.6 | Gestion des fournisseurs IA | [supplier-management.md](supplier-management.md) |
| 9 + 10 | Évaluation des performances et amélioration | [performance-and-improvement.md](performance-and-improvement.md) |
| Annexe A | Contrôles de référence | [controls.md](controls.md) |

## Concepts clés

**AIMS** (AI Management System) — Système structuré de politiques, processus et contrôles pour développer et utiliser l'IA de façon responsable.

**Système IA** — Tout système qui, à partir d'objectifs définis, produit des sorties (prédictions, recommandations, décisions) influençant des environnements réels ou virtuels.

**Utilisation prévue / mésusage prévisible** — Le standard exige de documenter explicitement les deux : ce pourquoi le système est conçu, et les usages déviants raisonnablement prévisibles.

**Impact IA** — Conséquences sur les individus, les groupes et la société, positives ou négatives, directes ou indirectes.

## Relation avec les autres sections

- Risques IA → complète [hazard-analysis.md](../safety-compliance/hazard-analysis.md)
- Sécurité IA → complète [security.md](../safety-compliance/security.md)
- Exigences système IA → tracées dans [system-requirements.md](../requirements/system-requirements.md)
- Décisions d'architecture IA → tracées dans [architecture/decisions/](../architecture/decisions/ADR-0001-template.md)
