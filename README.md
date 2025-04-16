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

Cette partie consiste à concevoir et assembler un drone de petite taille équipé d'une caméra ESP32-CAM pour capturer des images des plantes. Le drone utilise un capteur MPU6050 pour sa stabilisation, des moteurs brushless pour le vol et une batterie LiPo pour l'alimentation. Le but est de tester et d'optimiser la prise de photos et leur envoi vers un serveur pour analyse via un modèle d'intelligence artificielle (IA).


## 📸 Fonctionnalités

- Capture automatique de photos toutes les 20 secondes avec ESP32-CAM
- Stockage sur carte SD via SD_MMC
- Stabilisation gyroscopique (MPU6050)
- Commande via radiocommande RC (Throttle, Yaw, Pitch, Roll)
- 4 moteurs contrôlés par ESC via la librairie Servo

---

## 🧰 Matériel requis

| Composant | Quantité |
|----------|----------|
| ESP32-CAM | 1 |
| Carte microSD + Adaptateur | 1 |
| MPU6050 (Gyroscope/Accéléromètre) | 1 |
| Moteurs brushless + ESC (x4) | 4 |
| Récepteur RC 4 canaux | 1 |
| Batterie LiPo | 1 |
| Câbles Dupont, breadboard ou PCB perso | - |

---

## 🔌 Schéma de câblage (résumé)

<img width="1001" alt="image" src="https://github.com/user-attachments/assets/184dd2ca-a9f2-4ac9-9d62-3ed77ea0c0c2" />
<img width="1001" alt="image" src="https://github.com/user-attachments/assets/606a4ff1-26cb-41b6-b6df-041726362c6f" />

### ESP32-CAM (Caméra)

- Se réfère à la configuration des GPIO dans le code.
- Carte SD branchée sur les ports SD_MMC de l’ESP32-CAM.

### Contrôle moteur

| ESC | Pin Arduino |
|-----|-------------|
| ESC1 | 3 |
| ESC2 | 5 |
| ESC3 | 6 |
| ESC4 | 9 |

### Récepteur RC

| Canal RC | Pin Arduino |
|----------|-------------|
| Roll     | 2 |
| Pitch    | 4 |
| Throttle | 7 |
| Yaw      | 8 |

### MPU6050

Connecté en I2C :
- SDA → A4 (ou selon la carte)
- SCL → A5

---

## ⚙️ Installation

1. Installer les librairies suivantes :
   - `esp_camera.h`
   - `SD_MMC.h`
   - `Servo.h`
   - `MPU6050.h`
   - `Wire.h`

2. Compiler et téléverser le code depuis l'IDE Arduino.

3. Préparer la carte SD (formatée en FAT32).

4. Insérer la carte SD dans l’ESP32-CAM, brancher l’alim, et tout se fait automatiquement.

---

## 🛫 Utilisation

- Une photo est prise toutes les 20 secondes et sauvegardée sur la carte SD.
- Les valeurs de mouvement du MPU6050 corrigent le signal RC en vol.
- Les ESC sont armés à l'initialisation pour démarrer les moteurs.

---

## ⚠️ Avertissements

- Toujours tester sans hélices au début !
- Le montage demande une bonne gestion de l’alimentation (courant élevé pour les ESC).
- La gestion des ESC dépend de leur type (BLHeli, etc).
- Pour l'IA, un modèle léger est recommandé pour l'exécution sur des plateformes embarquées comme l'ESP32, ou bien l'envoi des images vers un serveur pour traitement.

---

## 🧪 À faire

- Ajouter du streaming live via WiFi (ESP32-CAM)
- Kalman filter ou PID pour stabilisation plus avancée
- Détection d'obstacle avec capteur ultrasons ?
- Développer le modèle d'IA pour la reconnaissance de maladies (utiliser TensorFlow Lite ou un modèle préentraîné)
- Tester l'intégration du modèle IA avec le drone (traitement des images sur le vol)

## Aide et Support

Si vous avez des questions ou avez besoin d'aide, veuillez ouvrir une issue dans ce repository. Nous serons heureux de vous aider !

---

*Ce projet est en développement et pourrait être amené à évoluer. Restez à l'écoute pour les mises à jour futures.*

## 👨‍💻 Auteur

Projet développé par **Oladé LAOUROU** Encadré dans le cadre de projets Deep Learning

---

## 📄 Licence

Ce projet est libre d'utilisation à des fins éducatives et de recherche.
