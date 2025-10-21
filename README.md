# svg-app


# Projet SVG CLI en C - Editeur NOAH-SVG...

## Table des matières

* [Présentation](#présentation)
* [Objectifs du projet](#objectifs-du-projet)
* [Architecture du projet](#architecture-du-projet)
* [Structures et Types](#structures-et-types)
* [Fonctionnalités](#fonctionnalités)
* [Menus et Interface CLI](#menus-et-interface-cli)
* [Gestion des Styles](#gestion-des-styles)
* [Parser SVG](#parser-svg)
* [Chronomètre et utilitaires CLI](#chronomètre-et-utilitaires-cli)
* [Conventions de codage](#conventions-de-codage)
* [Installation et compilation](#installation-et-compilation)
* [Exemples d’utilisation](#exemples-dutilisation)
* [Auteur et contact](#auteur-et-contact)

---

## Présentation

Ce projet est une **application en ligne de commande** pour la création, la modification et l’exportation de fichiers **SVG**.
Il permet de manipuler plusieurs formes vectorielles classiques comme les cercles, ellipses, rectangles, carrés, lignes, polylines, polygones et paths, ainsi que de **grouper des formes** et d’appliquer des **styles** (couleur, contour, transformations).

Le projet est entièrement écrit en **C**, avec une architecture modulaire et des structures de données dynamiques (listes chaînées, unions et enums) pour gérer la complexité des SVG.

---

## Objectifs du projet

* Permettre la **création interactive de fichiers SVG** via CLI.
* Fournir une **interface intuitive** pour éditer, styliser et exporter des formes.
* Offrir un **système de groupes** pour gérer plusieurs formes en ensemble.
* Inclure un **parser SVG** pour charger et interpréter des fichiers existants.
* Intégrer des **fonctions utilitaires** pour améliorer l’expérience CLI (chrono, animations, saisie sécurisée).

---

## Architecture du projet

Le projet est organisé en modules principaux :

```
shapes/           # Formes SVG
 ├─ circle/
 ├─ ellipse/
 ├─ line/
 ├─ rectangle/
 ├─ square/
 ├─ polyline/
 ├─ polygone/
 ├─ path/
 ├─ group/
 └─ shapes-style/
parser/           # Analyse et parsing des fichiers SVG
CLI_UI/           # Interface utilisateur
svg/              # Gestion des fichiers SVG
common-fonctions/ # Fonctions utilitaires
other/            # Autres outils (kbhit, chrono)
```

Chaque module concerne une forme précise ou un bloc de fonctionnalitées réutilisables et contient des **fichiers `.h` et `.c`** avec une **Javadoc en français**, ce qui facilite la maintenance et l’extension.

---

## Structures et Types

### Formes de base

* `Circle`: Cercle SVG (`cx`, `cy`, `rx`)
* `Ellipse`: Extension de cercle avec `ry`
* `Rect`: Rectangle (`x`, `y`, `height`, `width`, `round`)
* `Line`: Ligne (`x1`, `y1`, `x2`, `y2`)
* `Square`: Carré (hérite de `Rect`)
* `Polyline` et `Polygone`: Listes chaînées de points (`LinkPoint` et `Head`)
* `Path`: Liste chaînée de commandes SVG (`MoveTo`, `LineTo`, `CubicCurve`, etc.)

### Styles

* `Style`: Définition des attributs graphiques (`stroke`, `fill`, `width`, `rotation`, `scale`, `translate`)
* `BlocStyle`: Enumération des types de modification (`FILL`, `STROKE`, `ROTATE`, etc.)

### Groupes

* `Group`: Contient un ensemble de `GroupElement`, qui peut être n’importe quelle forme ou sous-groupe.
* `CurrentShapes` et `Shapes`: Utilisation d’union et enum pour gérer dynamiquement tous les types de formes.

---

## Fonctionnalités

### Création de formes

* Saisie interactive via CLI avec validation.
* Support complet pour toutes les formes SVG classiques.
* Gestion des dimensions, positions, couleurs et arrondis.

### Modification

* Menu interactif pour modifier chaque propriété d’une forme.
* Support pour **modifier plusieurs formes en chaîne**.
* Fonctionnalités avancées comme **rotation, translation et scaling**.

### Styles

* Application de styles individuels ou globaux.
* Couleurs RGB + alpha pour `stroke` et `fill`.
* Largeur de contour et transformations intégrées.

### Groupes

* Création de groupes pour manipuler plusieurs formes simultanément.
* Ajout, suppression et édition de formes dans un groupe.
* Possibilité de **nesting** de groupes.

### Export

* Export des formes et groupes en fichiers `.svg`.
* Conformité au standard SVG.

---

## Menus et Interface CLI

Le projet fournit un **interface CLI structurée** :

### Premier menu

* Créer une forme
* Charger un fichier SVG existant
* Quitter

### Second menu

* Modifier une forme
* Styliser une forme
* Exporter
* Supprimer

### Menu des formes

* Sélection entre toutes les formes disponibles (cercle, ellipse, rectangle, carré, ligne, polyline, polygone, path, groupe).

---

## Parser SVG

Le module parser permet :

* Lecture d’un fichier `.svg` et création des structures internes.
* Extraction des attributs (position, taille, style).
* Parsing complet des `path` et `polyline`.
* Conversion en structures dynamiques pour édition et export.

---

## Chronomètre et utilitaires CLI

* `Chrono_assassin()`: Chronomètre visuel avec retour de statut (skip ou fin).
* `Ignore_extra_enters()`: Gestion des entrées multiples.
* `Auto_write()`: Écriture automatique avec délai.
* `Progress_bar_animation()`: Barre de progression CLI.
* Fonctions de saisie sécurisée (`Float_recup_verify_with_padding`).

---

## Conventions de codage

* **Structures** : PascalCase
* **Variables** : snake_case
* **Fonctions / procédures** : Big_snake_case
* **Documentation** : Javadoc  avec `/** */`

---

## Installation et compilation

1. Clonez le dépôt :

```bash
git clone <URL>
cd projet-svg-cli
```

2. Compilez :

```bash
gcc -o svg_cli *.c shapes/**/*.c parser/*.c CLI_UI/*.c svg/*.c -I.
```

3. Lancez :

```bash
./svg_cli
```

---

## Exemples d’utilisation

1. Créer un cercle avec style rouge et contour épais.
2. Ajouter un rectangle dans un groupe.
3. Exporter un path en fichier `output.svg`.
4. Modifier une polyline existante via le menu CLI.

---

## Auteur et contact

* **Nom**: [Darill ADJIWANOU]
* **Email**: [darill.adjiwanou@gmail.com]
* **Période de conception**: Octobre 2025-2026

