# 🌿 Plant Disease Classifier - FGVC7 2020

Ce projet propose une solution basée sur un réseau de neurones convolutif (CNN) pour détecter différentes maladies des plantes à partir d'images de feuilles, dans le cadre de la compétition [Plant Pathology 2020 - FGVC7](https://www.kaggle.com/c/plant-pathology-2020-fgvc7).

---

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

---

## 🛠️ Améliorations futures

- Utilisation de modèles pré-entraînés (Transfer Learning)
- Meilleure gestion du déséquilibre (oversampling, loss pondérée)
- Interface Streamlit ou Flask pour prédictions temps réel

---

## 👨‍💻 Auteur

Projet développé par **Jean-Charles Houinato** Encadré dans le cadre de projets Deep Learning

---

## 📄 Licence

Ce projet est libre d'utilisation à des fins éducatives et de recherche.
