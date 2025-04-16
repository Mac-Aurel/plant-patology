# 🌿 Plant Disease Classifier - FGVC7 2020

## Description

Ce projet a pour objectif de reconnaître des maladies sur des plantes à partir d'images capturées par un drone. Le modèle d'intelligence artificielle analyse les images pour détecter des signes de maladies comme les taches, le jaunissement, et d'autres dégradations. Le drone, équipé d'une caméra ESP32-CAM, capture les images à distance et les transmet à un serveur pour analyse par un modèle IA.
Il propose une solution basée sur un réseau de neurones convolutif (CNN) pour détecter différentes maladies des plantes à partir d'images de feuilles, dans le cadre de la compétition [Plant Pathology 2020 - FGVC7](https://www.kaggle.com/c/plant-pathology-2020-fgvc7).

---
# 🧠 Partie IA - Reconnaissance de Maladies

## 📁 Dataset

- **Source** : Compétition Kaggle FGVC7
- **Classes** :
  - `healthy`
  - `rust`
  - `scab`
  - `multiple_diseases`

Le dataset est très déséquilibré, ce qui a orienté le choix des métriques d’évaluation vers l’AUC plutôt que l’accuracy.

---

## 🧠 Modèle

Un **CNN dynamique** construit avec Keras/TensorFlow :

- Nombre de blocs convolutionnels personnalisable
- Filtres adaptables
- Option de dropout
- Choix de l'optimiseur (`adam`, `adamw`, `sgd`, `rmsprop`)
- L2 regularization configurable

---

## 🔁 Pipeline

1. **Chargement des données**
2. **Exploration visuelle**
3. **Prétraitement des images**
4. **Augmentation des données**
5. **Construction dynamique du CNN**
6. **Entraînement avec EarlyStopping & TensorBoard**
7. **Évaluation avec AUC et matrice de confusion**

---

## 📦 Installation

1. Cloner le dépôt :
```bash
git clone https://github.com/ton-utilisateur/plant-disease-cnn.git
cd plant-disease-cnn
```

2. Installer les dépendances :
```bash
pip install -r requirements.txt
```

3. Ajouter votre clé `kaggle.json` dans le bon dossier :
```bash
mkdir -p ~/.kaggle
cp /votre/chemin/kaggle.json ~/.kaggle/
chmod 600 ~/.kaggle/kaggle.json
```

4. Télécharger les données :
```bash
kaggle competitions download -c plant-pathology-2020-fgvc7
unzip plant-pathology-2020-fgvc7.zip
```

---

## 🚀 Entraînement

Lancement d’une expérience :

```python
model, history = run_experiment(
    seed=42,
    img_size=(128, 128),
    batch_size=32,
    epochs=50,
    use_dropout=True,
    num_blocks=3,
    base_filters=16,
    opt='adam',
    l2_lambda=0.001,
    learning_rate=3e-4,
    use_augmentation=True
)
```

---

## 📊 Résultats

- **Meilleure AUC obtenue** : *0.98+* (selon les paramètres)
- **Optimiseur le plus performant** : `Adam` avec dropout et augmentation
- **Méthode d'évaluation** : `roc_auc_score (macro average)`

<img width="1680" alt="image" src="https://github.com/user-attachments/assets/73c8970a-21a3-4445-8493-d6611054eec4" />
<img width="1680" alt="image" src="https://github.com/user-attachments/assets/b6e2ad9b-a76f-4f8b-80c9-993bcd974211" />



---

## 🛠️ Améliorations futures

- Utilisation de modèles pré-entraînés (Transfer Learning)
- Meilleure gestion du déséquilibre (oversampling, loss pondérée)
- Interface Streamlit ou Flask pour prédictions temps réel

---

# Drone de Surveillance des Plantes avec ESP32-CAM

Ce projet consiste à concevoir et assembler un drone de petite taille équipé d'une caméra ESP32-CAM pour capturer des images des plantes. Le drone utilise un capteur MPU6050 pour sa stabilisation, des moteurs brushless pour le vol et une batterie LiPo pour l'alimentation. Le but est de tester et d'optimiser la prise de photos et leur envoi vers un serveur pour analyse via un modèle d'intelligence artificielle (IA).

## Composants principaux

- **ESP32-CAM** : Caméra 2 MP utilisée pour prendre des photos des plantes. Elle est compacte et légère, idéale pour un drone de petite taille.
- **MPU6050** (Gyroscope + Accéléromètre) : Utilisé pour la stabilisation du drone pendant son vol. Il mesure l'inclinaison et l'orientation du drone.
- **Moteurs brushless et ESC** : Quatre moteurs brushless alimentés par des ESC pour contrôler la vitesse et les mouvements du drone.
- **Batterie LiPo** : Fournit l'énergie nécessaire pour le vol du drone. La capacité typique varie de 1500mAh à 2200mAh.
- **Récepteur RC 4 canaux** : Permet de contrôler le drone à distance via une radiocommande.

## Câblage et Assemblage du Drone

<img width="1001" alt="image" src="https://github.com/user-attachments/assets/184dd2ca-a9f2-4ac9-9d62-3ed77ea0c0c2" />
<img width="1001" alt="image" src="https://github.com/user-attachments/assets/606a4ff1-26cb-41b6-b6df-041726362c6f" />


### Composants et connexions :

| Composant       | Connexion                     | Description                        |
|-----------------|-------------------------------|------------------------------------|
| **ESC1**        | Pin 3 (PWM)                   | Contrôle du moteur 1               |
| **ESC2**        | Pin 5 (PWM)                   | Contrôle du moteur 2               |
| **ESC3**        | Pin 6 (PWM)                   | Contrôle du moteur 3               |
| **ESC4**        | Pin 9 (PWM)                   | Contrôle du moteur 4               |
| **MPU6050**     | Pins SDA (21) et SCL (22)     | Stabilisation du drone             |
| **ESP32-CAM**   | GPIO Pins                     | Capture des images des plantes     |

## Contrôle du Drone

Le drone est contrôlé par quatre axes :

- **Yaw** : Rotation autour de l'axe vertical
- **Pitch** : Inclinaison avant/arrière
- **Roll** : Inclinaison latérale
- **Throttle** : Accélération pour la montée/descente

## Logiciel et Commandes

### Firmware du Drone

Le firmware du drone est développé avec **Arduino IDE** ou **PlatformIO**, en utilisant les bibliothèques suivantes :

- **ESP32 Wi-Fi** : Utilisé pour la capture d'images et l'envoi des données via Wi-Fi.
- **Wire** : Utilisé pour la communication avec le capteur **MPU6050** via I2C.

### Capture d'Images

- Le drone prend une photo toutes les **20 secondes** pendant le vol.
- Les images sont ensuite enregistrées sur une **carte SD** pour être envoyées au serveur d'analyse.

## Tests à réaliser

Avant de déployer le drone, il est essentiel de réaliser certains tests pour s'assurer de sa stabilité et de la qualité de ses performances.

### 1. Tester la stabilité du drone en vol
Assurez-vous que le drone reste stable en vol avec un contrôle précis des axes (yaw, pitch, roll, throttle).

### 2. Vérifier la durée de vol avec la batterie LiPo
La batterie LiPo devrait offrir une autonomie de **10-15 minutes**. Vérifiez cette durée lors d'un vol test complet.

### 3. Tester la qualité des images capturées
Prenez des photos en vol et vérifiez la résolution et la clarté des images capturées pour s'assurer que la caméra ESP32-CAM est suffisante pour l'application.

### 4. Optimiser l'envoi des photos au serveur pour analyse par IA
Vérifiez que les images peuvent être envoyées efficacement au serveur pour analyse via un modèle d'IA. L'optimisation du processus d'envoi est cruciale pour un système de surveillance en temps réel.

## Installation

1. **Assembler les composants du drone** : Suivez le schéma de câblage pour connecter l'ESP32-CAM, les moteurs brushless, l'ESC, et le MPU6050.
2. **Configurer l'IDE** : Téléchargez et installez **Arduino IDE** ou **PlatformIO**.
3. **Télécharger le code source** : Clonez ce repository et chargez le code sur l'ESP32.
4. **Tester le drone** : Effectuez des tests pour vérifier les performances et la stabilité en vol.

## Aide et Support

Si vous avez des questions ou avez besoin d'aide, veuillez ouvrir une issue dans ce repository. Nous serons heureux de vous aider !

---

*Ce projet est en développement et pourrait être amené à évoluer. Restez à l'écoute pour les mises à jour futures.*

## 👨‍💻 Auteur

Projet développé par **Oladé LAOUROU** Encadré dans le cadre de projets Deep Learning

---

## 📄 Licence

Ce projet est libre d'utilisation à des fins éducatives et de recherche.
