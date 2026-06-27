# Évaluation des performances et amélioration

| Version | Date       | Auteur | Statut |
|---------|------------|--------|--------|
| 0.1     | YYYY-MM-DD |        | Draft  |

**Clauses couvertes** : ISO 42001 §9.1 · §9.2 · §9.3 · §10.1 · §10.2

---

## 9.1 Surveillance, mesure, analyse et évaluation

### Indicateurs de performance de l'AIMS

<!--
Définir les indicateurs suivis pour évaluer l'efficacité de l'AIMS.
Ces indicateurs alimentent la revue de direction (§9.3).
-->

| Indicateur | Source | Fréquence | Cible | Responsable |
|---|---|---|---|---|
| Dérive de performance du modèle (concept drift) | Monitoring production | Mensuelle | < X% de dégradation | |
| Taux d'incidents IA ouverts / résolus | Registre incidents | Mensuelle | 100% traités sous 30j | |
| Couverture des contrôles Annexe A | Audit interne | Annuelle | ≥ 90% | |
| Taux de complétion des formations IA | RH | Semestrielle | 100% | |
| Non-conformités ouvertes | Registre NC | Mensuelle | 0 NC critiques | |
| Satisfaction des parties prenantes | Enquête / retours | Annuelle | À définir | |

### Méthodes d'évaluation

| Méthode | Objet | Fréquence |
|---|---|---|
| Monitoring automatisé | Performance, biais, dérive en production | Continue |
| Revue des incidents | Incidents IA, quasi-incidents | Mensuelle |
| Audit interne | Conformité aux contrôles Annexe A | Annuelle |
| Revue de direction | Efficacité globale de l'AIMS | Annuelle |

---

## 9.2 Audit interne

### Programme d'audit

<!--
Définir la fréquence, les méthodes, les responsabilités et les critères d'audit.
Les auditeurs ne doivent pas auditer leur propre travail.
-->

| Domaine audité | Clause(s) | Fréquence | Auditeur |
|---|---|---|---|
| Politique et leadership | §5 | Annuelle | |
| Évaluation des risques et impacts | §6.1 | Annuelle | |
| Cycle de vie du système IA | §8.4 | Annuelle | |
| Contrôles Annexe A | Annexe A | Annuelle | |
| Gestion des fournisseurs | §8.6 | Annuelle | |
| Non-conformités et actions correctives | §10.1 | Semestrielle | |

### Rapports d'audit

| Date | Périmètre | Auditeur | Résultat | Non-conformités | Référence |
|---|---|---|---|---|---|
| | | | | | |

---

## 9.3 Revue de direction

<!--
La direction doit revoir l'AIMS à intervalles planifiés pour s'assurer
de son adéquation, son efficacité et son alignement avec la stratégie.
-->

### Éléments d'entrée de la revue

- [ ] Statut des actions des revues précédentes
- [ ] Évolution du contexte externe et interne
- [ ] Résultats des audits internes
- [ ] Performance des indicateurs (§9.1)
- [ ] Incidents IA et non-conformités
- [ ] Résultats de l'évaluation des risques et impacts
- [ ] Retours des parties prenantes
- [ ] Opportunités d'amélioration

### Éléments de sortie de la revue

- [ ] Décisions sur les opportunités d'amélioration
- [ ] Décisions sur les besoins en ressources
- [ ] Mise à jour des objectifs IA
- [ ] Révision éventuelle de la politique IA

### Registre des revues

| Date | Participants | Décisions | Actions | Responsable | Échéance |
|---|---|---|---|---|---|
| | | | | | |

---

## 10.1 Non-conformités et actions correctives

<!--
Une non-conformité est le non-respect d'une exigence de l'AIMS.
Elle peut être identifiée lors d'un audit, d'un incident, ou d'une surveillance courante.
-->

### Processus de traitement

1. **Identifier** la non-conformité et ses effets
2. **Réagir** : contenir les effets immédiats si nécessaire
3. **Analyser les causes** : recherche de la cause racine
4. **Définir les actions correctives** : actions visant à éliminer la cause
5. **Implémenter** les actions correctives
6. **Vérifier l'efficacité** des actions mises en place
7. **Mettre à jour** les risques si nécessaire

### Registre des non-conformités

| ID | Date | Source | Description | Cause racine | Action corrective | Responsable | Échéance | Vérification | Statut |
|---|---|---|---|---|---|---|---|---|---|
| NC-AI-001 | | | | | | | | | |

---

## 10.2 Amélioration continue

<!--
Documenter les initiatives d'amélioration continue de l'AIMS,
au-delà des actions correctives (qui traitent des non-conformités identifiées).
-->

| Initiative | Objectif visé | Source (audit / incident / revue / …) | Responsable | Statut |
|---|---|---|---|---|
| | | | | |
