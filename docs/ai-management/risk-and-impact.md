# Évaluation des risques et impacts IA

| Version | Date       | Auteur | Statut |
|---------|------------|--------|--------|
| 0.1     | YYYY-MM-DD |        | Draft  |

**Clauses couvertes** : ISO 42001 §6.1.2 (risques) · §6.1.4 (impacts) · Annexes C et D

---

## 6.1.2 Évaluation des risques IA

<!--
L'évaluation des risques IA est distincte de la gestion des risques projet (risk-register.md)
et de la HARA (hazard-analysis.md). Elle porte spécifiquement sur les risques liés
aux propriétés du système IA : biais, robustesse, explicabilité, dérive de modèle, etc.
-->

### Processus d'évaluation

1. Identifier les risques spécifiques au système IA (voir catégories ci-dessous)
2. Estimer la vraisemblance et la sévérité de chaque risque
3. Déterminer les traitements (contrôles de l'Annexe A)
4. Valider l'acceptabilité du risque résiduel

### Catégories de risques IA

| Catégorie | Exemples | Contrôles applicables (Annexe A) |
|---|---|---|
| Biais et équité | Discrimination sur des attributs protégés | A.6.1.2, A.6.1.5 |
| Robustesse | Sensibilité aux entrées adversariales, dérive de distribution | A.6.2.5, A.9.3 |
| Explicabilité | Décisions non interprétables par les parties affectées | A.6.2.3 |
| Confidentialité | Fuite de données d'entraînement, inversion de modèle | A.8.4 |
| Fiabilité | Hallucinations, erreurs systématiques, défaillances silencieuses | A.9.3, A.9.4 |
| Dépendance fournisseur | Indisponibilité d'un modèle tiers, changement de conditions | A.10.1 |
| Mésusage prévisible | Utilisation du système à des fins non prévues | A.6.1.3 |

### Registre des risques IA

| ID | Risque | Vraisemblance | Sévérité | Criticité | Traitement | Contrôle(s) | Responsable | Statut |
|---|---|---|---|---|---|---|---|---|
| AI-R-001 | | | | | | | | |

---

## 6.1.4 Évaluation des impacts IA

<!--
L'évaluation des impacts (AI Impact Assessment) est distincte de l'évaluation des risques :
elle porte sur les conséquences pour les individus, groupes et société,
pas seulement sur les risques pour l'organisation.
Référence : Annexe D de la norme.
-->

### Périmètre de l'évaluation

**Système IA évalué** : <!-- Nom et description courte -->

**Utilisation prévue** :
> _Le système est conçu pour [objectif], utilisé par [qui], dans le contexte de [quoi]._

**Mésusages prévisibles** :
> _Il est raisonnablement prévisible que le système puisse être utilisé pour [liste]._

### Parties potentiellement affectées

| Groupe affecté | Type d'impact potentiel | Positif / Négatif | Probabilité | Sévérité |
|---|---|---|---|---|
| Utilisateurs directs | | | | |
| Tiers affectés par les décisions | | | | |
| Groupes vulnérables | | | | |
| Société / environnement | | | | |

### Décision et traitement

| Impact identifié | Décision (accepter / atténuer / éviter) | Mesure retenue |
|---|---|---|
| | | |

### Approbation

| Rôle | Nom | Date | Signature |
|---|---|---|---|
| Responsable AIMS | | | |
| Responsable conformité | | | |

---

## Relation avec les autres évaluations

| Document | Périmètre | Lien |
|---|---|---|
| HARA | Dangers physiques, SIL/PL | [hazard-analysis.md](../safety-compliance/hazard-analysis.md) |
| FMEA | Modes de défaillance composants | [fmea.md](../safety-compliance/fmea.md) |
| Modèle de menace STRIDE | Attaques intentionnelles | [security.md](../safety-compliance/security.md) |
| Registre des risques projet | Risques planning/budget | [risk-register.md](../project/risk-register.md) |
