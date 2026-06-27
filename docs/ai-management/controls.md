# Contrôles de référence — Annexe A

| Version | Date       | Auteur | Statut |
|---------|------------|--------|--------|
| 0.1     | YYYY-MM-DD |        | Draft  |

**Référence** : ISO/IEC 42001:2023 Annexe A

---

## Usage de ce document

L'Annexe A de la norme liste les contrôles de référence applicables à un AIMS. Ce document sert de déclaration d'applicabilité : pour chaque contrôle, indiquer s'il est applicable, et si oui, comment il est mis en œuvre.

**Statuts** : `Applicable` · `Non applicable` · `Partiellement applicable`

---

## A.2 — Politiques relatives à l'IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.2.1 | Politique relative à l'utilisation de l'IA | | [leadership-and-policy.md](leadership-and-policy.md) | |
| A.2.2 | Politique relative aux ressources IA | | [support.md](support.md) | |

## A.3 — Responsabilité interne relative à l'IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.3.1 | Rôles et responsabilités IA | | [leadership-and-policy.md §5.3](leadership-and-policy.md) | |
| A.3.2 | Signalement des problèmes liés à l'IA | | [performance-and-improvement.md §10.1](performance-and-improvement.md) | |

## A.4 — Ressources pour les systèmes IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.4.1 | Processus de gestion des ressources IA | | [support.md §7.1](support.md) | |

## A.5 — Évaluation de l'impact sur les parties prenantes IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.5.1 | Évaluation de l'impact sur les parties prenantes | | [risk-and-impact.md §6.1.4](risk-and-impact.md) | |
| A.5.2 | Processus de retour des parties prenantes | | [performance-and-improvement.md §9.1](performance-and-improvement.md) | |

## A.6 — Cycle de vie des systèmes IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.6.1.1 | Conception des systèmes IA | | [ai-lifecycle.md §Phase 1](ai-lifecycle.md) | |
| A.6.1.2 | Spécification des données | | [ai-lifecycle.md §Phase 1](ai-lifecycle.md) | |
| A.6.1.3 | Évaluation des risques liés aux données | | [risk-and-impact.md](risk-and-impact.md) | |
| A.6.1.4 | Gestion de la qualité des données | | [ai-lifecycle.md §Phase 2](ai-lifecycle.md) | |
| A.6.1.5 | Protection des données | | [security.md](../safety-compliance/security.md) | |
| A.6.2.1 | Définition des objectifs du système IA | | [ai-objectives.md](ai-objectives.md) | |
| A.6.2.2 | Sélection des outils et technologies | | [ai-lifecycle.md §Phase 2](ai-lifecycle.md) | |
| A.6.2.3 | Explicabilité du système IA | | [ai-lifecycle.md §Phase 2](ai-lifecycle.md) | |
| A.6.2.4 | Sécurité du système IA | | [security.md](../safety-compliance/security.md) | |
| A.6.2.5 | Robustesse et fiabilité | | [verification-plan.md](../verification/verification-plan.md) | |
| A.6.2.6 | Documentation du système IA | | [ai-lifecycle.md](ai-lifecycle.md) | |
| A.6.2.7 | Vérification et validation | | [verification-plan.md](../verification/verification-plan.md) | |
| A.6.2.8 | Conditions de retrait du système IA | | [ai-lifecycle.md §Phase 6](ai-lifecycle.md) | |

## A.7 — Opérations liées aux données pour les systèmes IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.7.1 | Traitement équitable des données | | [risk-and-impact.md](risk-and-impact.md) | |
| A.7.2 | Sécurité des données | | [security.md](../safety-compliance/security.md) | |
| A.7.3 | Confidentialité des données personnelles | | [security.md](../safety-compliance/security.md) | |
| A.7.4 | Accès aux données pour l'IA | | | |

## A.8 — Sécurité de l'information pour les systèmes IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.8.1 | Gestion des risques de sécurité IA | | [risk-and-impact.md](risk-and-impact.md) | |
| A.8.2 | Protection contre les attaques adversariales | | [security.md](../safety-compliance/security.md) | |
| A.8.3 | Sécurité des pipelines IA | | [security.md](../safety-compliance/security.md) | |
| A.8.4 | Protection contre la fuite de données (model inversion) | | [security.md](../safety-compliance/security.md) | |

## A.9 — Comportement responsable des systèmes IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.9.1 | Évaluation des préjudices IA | | [risk-and-impact.md §6.1.4](risk-and-impact.md) | |
| A.9.2 | Évaluation de la partialité (biais) | | [ai-lifecycle.md §Phase 2](ai-lifecycle.md) | |
| A.9.3 | Surveillance et pilotage du comportement | | [performance-and-improvement.md §9.1](performance-and-improvement.md) | |
| A.9.4 | Contrôle humain | | [ai-lifecycle.md](ai-lifecycle.md) | |

## A.10 — Relations avec les fournisseurs de systèmes IA

| Réf. | Contrôle | Statut | Mise en œuvre | Justification d'exclusion |
|---|---|---|---|---|
| A.10.1 | Politique de gestion des fournisseurs IA | | [supplier-management.md](supplier-management.md) | |
| A.10.2 | Contrats et accords avec les fournisseurs IA | | [supplier-management.md §maîtrise contractuelle](supplier-management.md) | |
| A.10.3 | Gestion des changements chez les fournisseurs IA | | [supplier-management.md §suivi](supplier-management.md) | |
