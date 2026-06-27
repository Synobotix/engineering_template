# Gestion des fournisseurs IA

| Version | Date       | Auteur | Statut |
|---------|------------|--------|--------|
| 0.1     | YYYY-MM-DD |        | Draft  |

**Clauses couvertes** : ISO 42001 §8.6 · Annexe A §10

---

## Périmètre

Cette section couvre tous les fournisseurs tiers dont les composants IA sont intégrés dans les systèmes couverts par l'AIMS : modèles pré-entraînés, APIs d'inférence, plateformes MLOps, fournisseurs de données d'entraînement.

---

## Inventaire des fournisseurs IA

| ID | Fournisseur | Composant / Service | Rôle dans le système | Criticité | Localisation des données |
|---|---|---|---|---|---|
| SUP-AI-001 | | | | Haute / Moyenne / Basse | |

---

## Critères de sélection et d'évaluation

<!--
Définir les critères utilisés pour sélectionner et évaluer les fournisseurs IA.
ISO 42001 exige que les fournisseurs soient évalués selon leur capacité
à répondre aux exigences de l'AIMS.
-->

| Critère | Exigence minimale | Vérification |
|---|---|---|
| Politique IA / éthique | Politique publiée et cohérente avec la nôtre | Revue documentaire |
| Transparence du modèle | Model card disponible (architecture, données, biais évalués) | Revue model card |
| Sécurité des données | Chiffrement en transit et au repos, certifications (SOC 2, ISO 27001…) | Questionnaire fournisseur |
| Disponibilité et SLA | SLA ≥ [X]%, RTO/RPO définis | Contrat de service |
| Conformité réglementaire | RGPD, AI Act si applicable | Attestation |
| Continuité de service | Plan de continuité documenté | Revue documentaire |

---

## Maîtrise contractuelle

<!--
Documenter les exigences contractuelles imposées aux fournisseurs IA.
-->

Clauses à inclure dans les contrats avec les fournisseurs IA critiques :

- [ ] Droit d'audit ou accès aux rapports d'audit tiers
- [ ] Notification obligatoire en cas d'incident de sécurité affectant le service IA
- [ ] Engagement de maintien de la politique IA / éthique du fournisseur
- [ ] Conditions de sortie et portabilité des données
- [ ] Restrictions d'utilisation des données soumises pour l'inférence
- [ ] Engagement de conservation des caractéristiques du modèle (pas de modification silencieuse)

---

## Suivi et réévaluation

| Activité | Fréquence | Responsable |
|---|---|---|
| Revue des model cards et documentations fournisseur | Annuelle ou lors de mise à jour majeure | |
| Questionnaire de conformité fournisseur | Annuelle | |
| Test de performance et dérive du modèle tiers | Mensuelle (monitoring) | |
| Revue contractuelle | Lors du renouvellement | |

---

## Gestion des risques fournisseurs

Les risques liés aux fournisseurs IA sont enregistrés dans le registre des risques IA : [risk-and-impact.md](risk-and-impact.md).

Risques typiques à évaluer :

| Risque | Impact potentiel | Mitigation |
|---|---|---|
| Indisponibilité de l'API / modèle tiers | Arrêt du service IA | Fallback local ou fournisseur alternatif |
| Changement silencieux du modèle | Dérive de comportement non détectée | Tests de non-régression automatisés |
| Fuite de données envoyées en inférence | Violation RGPD / confidentialité | Anonymisation, chiffrement, contrat DPA |
| Arrêt du fournisseur | Perte du service à long terme | Stratégie de sortie documentée |
