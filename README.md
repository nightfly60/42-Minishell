# 🐚 Minishell - 42 Project

## 🌍 Languages
[English](#english-version) | [Français](#version-française)

---

## English Version

> _“As beautiful as a shell.”_  
> _Create your own little Bash, a journey through processes, pipes, and file descriptors._

---

## 📘 Overview
**Minishell** is a collaborative project at 42 that involves creating a simplified version of the Bash shell.  
It’s one of the most challenging and rewarding C projects in the curriculum, as it requires mastering **process management**, **signals**, **pipes**, **file descriptors**, and **environment variables**.

The objective is to build a functional shell capable of interpreting and executing commands while mimicking real Bash behavior for a subset of its core features.

---

## 🎯 Project Goals
- Reproduce a **basic Unix shell** from scratch  
- Understand how **processes**, **signals**, and **file descriptors** work  
- Implement **command parsing**, **execution**, and **I/O redirections**  
- Handle **environment variables**, **pipes**, and **built-in commands**  
- Develop a deeper understanding of **the Unix system API**

---

## ⚙️ Mandatory Requirements

### 🖥️ General
- Display a **prompt** while waiting for user input  
- Maintain **command history** (`readline`, `add_history`)  
- Search and execute commands using **PATH** or **relative paths**  
- Use **only one global variable** to handle signals

---

### 🧠 Command Parsing
- Support **quotes**:
  - `'` → no variable expansion  
  - `"` → allows `$` expansion  
- Reject unclosed quotes and unsupported characters (`\`, `;`, etc.)

---

## 🧱 Built-in Commands

| Command | Description |
|----------|-------------|
| `echo` | Displays text to standard output. Supports the `-n` option (no newline). |
| `cd` | Changes the current working directory and updates `PWD` / `OLDPWD`. |
| `pwd` | Prints the current working directory. |
| `export` | Adds or updates environment variables. Without arguments, lists them in sorted order. |
| `unset` | Removes environment variables. |
| `env` | Displays all environment variables currently set. |
| `exit` | Exits the shell with a specific status code (or the previous one if none is given). |

---

### 🔄 Redirections
| Operator | Behavior |
|-----------|-----------|
| `<` | Redirect input from file |
| `>` | Redirect output to file (overwrite) |
| `<<` | Here-document (stop at delimiter) |
| `>>` | Redirect output (append) |

---

### 🚰 Pipes
- Implement `|` to connect multiple commands  
- Output of one command = input of the next

---

## Version Française

> _« Aussi beau qu’un shell. »_  
> _Crée ton propre mini Bash, un voyage à travers les processus, les pipes et les descripteurs de fichiers._

---

## 📘 Aperçu
**Minishell** est un projet collaboratif de 42 qui consiste à créer une version simplifiée du shell Bash.  
C’est l’un des projets C les plus complets et formateurs du cursus, car il demande de maîtriser la **gestion des processus**, les **signaux**, les **pipes**, les **descripteurs de fichiers** et les **variables d’environnement**.  

L’objectif est de construire un shell fonctionnel capable d’interpréter et d’exécuter des commandes tout en reproduisant le comportement de Bash pour un ensemble limité de fonctionnalités principales.

---

## 🎯 Objectifs du projet
- Reproduire un **shell Unix basique** à partir de zéro  
- Comprendre le fonctionnement des **processus**, **signaux** et **descripteurs de fichiers**  
- Implémenter la **lecture de commandes**, leur **exécution** et les **redirections d’entrée/sortie**  
- Gérer les **variables d’environnement**, les **pipes** et les **commandes internes (built-ins)**  
- Développer une compréhension approfondie de **l’API système Unix**

---

## ⚙️ Exigences obligatoires

### 🖥️ Général
- Afficher un **prompt** en attente d’une commande utilisateur  
- Maintenir un **historique des commandes** (`readline`, `add_history`)  
- Rechercher et exécuter les commandes en utilisant le **PATH** ou des **chemins relatifs**  
- Utiliser **une seule variable globale** pour la gestion des signaux  

---

### 🧠 Analyse des commandes
- Gestion des **guillemets** :
  - `'` → empêche toute expansion de variable  
  - `"` → autorise l’expansion des variables (`$`)  
- Rejeter les guillemets non fermés et les caractères non autorisés (`\`, `;`, etc.)

---

## 🧱 Commandes intégrées (Built-ins)

| Commande | Description |
|-----------|-------------|
| `echo` | Affiche du texte sur la sortie standard. Prend en charge l’option `-n` (sans saut de ligne). |
| `cd` | Change le répertoire courant et met à jour les variables `PWD` / `OLDPWD`. |
| `pwd` | Affiche le chemin absolu du répertoire courant. |
| `export` | Ajoute ou modifie des variables d’environnement. Sans argument, les affiche dans l’ordre alphabétique. |
| `unset` | Supprime des variables d’environnement. |
| `env` | Affiche toutes les variables d’environnement actuellement définies. |
| `exit` | Quitte le shell avec un code de sortie spécifique (ou celui de la dernière commande si non précisé). |

---

### 🔄 Redirections
| Opérateur | Comportement |
|------------|--------------|
| `<` | Redirige l’entrée depuis un fichier |
| `>` | Redirige la sortie vers un fichier (écrase le contenu existant) |
| `<<` | Here-document (lecture jusqu’à un délimiteur) |
| `>>` | Redirige la sortie vers un fichier (ajoute à la fin) |

---

### 🚰 Pipes
- Implémenter `|` pour relier plusieurs commandes entre elles  
- La sortie d’une commande devient l’entrée de la suivante
