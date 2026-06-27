# Cycle de vie du système IA

| Version | Date       | Auteur | Statut |
|---------|------------|--------|--------|
| 0.1     | YYYY-MM-DD |        | Draft  |

**Clauses couvertes** : ISO 42001 §8.1 · §8.2 · §8.3 · §8.4 · §8.5 · Annexe E

---

## Vue d'ensemble du cycle de vie

Le cycle de vie d'un système IA couvre toutes les phases de son existence, de la conception au retrait. ISO 42001 exige que les contrôles appropriés soient appliqués à chaque phase.

```
Conception → Développement → Vérification → Déploiement → Exploitation → Retrait
```

---

## 8.1 Planification et maîtrise opérationnelles

<!--
Décrire les processus nécessaires pour répondre aux exigences de l'AIMS
et implémenter les actions de traitement des risques et impacts identifiés.
-->

| Processus | Description | Responsable | Référence |
|---|---|---|---|
| Revue des exigences IA | Vérifier que les exigences intègrent les critères IA responsable | | [sw-requirements.md](../requirements/sw-requirements.md) |
| Revue de conception | Valider les choix architecturaux au regard des risques IA | | [sw-architecture.md](../architecture/sw-architecture.md) |
| Validation du modèle | Évaluer biais, robustesse, performance avant déploiement | | [verification-plan.md](../verification/verification-plan.md) |
| Monitoring en production | Surveiller dérive de performance, incidents, biais émergents | | [runbook.md](../operations/runbook.md) |

---

## 8.2 Évaluation des risques IA (opérationnelle)

Référence : [risk-and-impact.md](risk-and-impact.md)

L'évaluation des risques est réalisée :
- Avant le développement d'un nouveau système IA
- Lors de changements significatifs du système ou des données
- Selon une périodicité définie (voir [performance-and-improvement.md](performance-and-improvement.md))

---

## 8.3 Évaluation des impacts IA (opérationnelle)

Référence : [risk-and-impact.md](risk-and-impact.md)

L'évaluation des impacts est réalisée :
- Avant le déploiement initial
- Lors d'extension du périmètre d'utilisation
- Lors d'incidents affectant des individus ou groupes

---

## 8.4 Cycle de vie — détail par phase

### Phase 1 : Conception

| Activité | Critère de sortie | Artefact |
|---|---|---|
| Définition de l'utilisation prévue et des mésusages prévisibles | Documenté et approuvé | [risk-and-impact.md §utilisation prévue](risk-and-impact.md) |
| Évaluation des risques initiale | Registre des risques créé | [risk-and-impact.md](risk-and-impact.md) |
| Évaluation des impacts initiale | Rapport d'impact créé | [risk-and-impact.md](risk-and-impact.md) |
| Définition des objectifs de performance | Métriques et seuils définis | [ai-objectives.md](ai-objectives.md) |
| Sélection des données d'entraînement | Critères de qualité et représentativité validés | |

### Phase 2 : Développement

| Activité | Critère de sortie | Artefact |
|---|---|---|
| Développement du modèle | Code versionné, expériences tracées | |
| Évaluation des biais | Résultats par groupe démographique documentés | |
| Tests de robustesse | Tests adversariaux exécutés | [verification-plan.md](../verification/verification-plan.md) |
| Explicabilité | Mécanismes d'explication implémentés | |
| Revue de sécurité | Revue sécurité IA complétée | [security.md](../safety-compliance/security.md) |

### Phase 3 : Vérification et validation

| Activité | Critère de sortie | Artefact |
|---|---|---|
| Validation des performances | Métriques ≥ seuils définis | [coverage.md](../verification/coverage.md) |
| Validation de l'équité | Biais dans les limites acceptées | |
| Test de charge et robustesse | Comportement sous contrainte validé | |
| Revue finale avant déploiement | GO/NO-GO documenté | |

### Phase 4 : Déploiement

| Activité | Critère de sortie | Artefact |
|---|---|---|
| Déploiement contrôlé (canary / shadow) | Déploiement progressif validé | [deployment.md](../operations/deployment.md) |
| Activation du monitoring | Alertes et dashboards opérationnels | [runbook.md](../operations/runbook.md) |
| Communication aux parties prenantes | Utilisateurs informés | |

### Phase 5 : Exploitation

| Activité | Critère de sortie | Artefact |
|---|---|---|
| Surveillance des performances | Rapport de dérive mensuel | [performance-and-improvement.md](performance-and-improvement.md) |
| Gestion des incidents IA | Incidents tracés et traités | [performance-and-improvement.md](performance-and-improvement.md) |
| Réévaluation périodique des risques | Registre mis à jour | [risk-and-impact.md](risk-and-impact.md) |
| Mise à jour du modèle | Processus de ré-entraînement documenté | |

### Phase 6 : Retrait

| Activité | Critère de sortie | Artefact |
|---|---|---|
| Plan de retrait | Impacts sur les utilisateurs évalués | |
| Communication | Parties prenantes notifiées | |
| Archivage | Modèle, données et logs archivés ou supprimés selon politique | |
| Revue post-retrait | Leçons apprises documentées | |

---

## 8.5 Utilisation prévue et mésusages prévisibles

<!--
ISO 42001 exige une documentation explicite de l'utilisation prévue
et des mésusages raisonnablement prévisibles.
-->

**Utilisation prévue** :
> _Le système est conçu pour [objectif précis], dans le contexte [contexte d'usage], par [profil d'utilisateur]._

**Populations d'utilisateurs visées** :
- <!-- ex: opérateurs industriels formés -->

**Conditions d'utilisation normales** :
- <!-- ex: données en entrée respectant le format X, connexion réseau disponible -->

**Mésusages prévisibles** :

| Mésusage | Conséquence | Mesure de mitigation |
|---|---|---|
| | | |
