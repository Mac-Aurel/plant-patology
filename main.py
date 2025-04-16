from src.data_preprocessing.preprocess import *
from src.data_preprocessing.preprocess_plant import *
from src.utils.utilities import *
import cv2

def main():
    #preprocess data
    test_df = pd.read_csv('data/external/plant-pathology-2020-fgvc7/test.csv')
    train_df = pd.read_csv('data/external/plant-pathology-2020-fgvc7/train.csv')

    ##create data with img
    test_df['img_path'] = test_df['image_id'].apply(generate_path)
    train_df['img_path'] = train_df['image_id'].apply(generate_path)
    print(test_df['img_path'].iloc[0])
    print(train_df['img_path'].iloc[0])

    test3 = cv2.imread(test_df['img_path'].iloc[1819])

    plt.imshow(test3)
    plt.axis('off')
    plt.show()

if __name__ == "__main__":
    main()