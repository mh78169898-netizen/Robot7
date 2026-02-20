import FinanceDataReader as fdr

samsung = fdr.DataReader('005930', start='01/01/2016')

print(samsung.head())

print(samsung.describe())

print(samsung.info())

print(samsung.shape)

import numpy as np
def make_samsung_data(data, window):
    train = []
    target = []
    for i in range(data.size - window):
        train.append(data[i:i + window]) # n개씩 묶기
        target.append(data[i + window]) # n개씩 묶은 것에 대한 1개의 정답표(핵심)
    return np.array(train), np.array(target)

samsung = fdr.DataReader('005930', start='01/01/2016')
print(samsung)

# 정규화를 해야 한다
from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler(feature_range=(0, 1))

scaled_data = scaler.fit_transform(samsung[['Open']])
print(scaled_data)

print(scaled_data.shape)

TEST_SIZE = 200
train_data = scaled_data[:-TEST_SIZE]
test_data = scaled_data[-TEST_SIZE:]

(X_train, y_train) = make_samsung_data(train_data, 30)
(X_test, y_test) = make_samsung_data(test_data, 30)

print(X_train.shape)

print(y_train.shape)

print(y_train[0])

import tensorflow as tf
model =tf.keras.models.Sequential()
input_layer = tf.keras.layers.Input(shape=(30, 1))
model.add(input_layer)
model.add(tf.keras.layers.LSTM(128, return_sequences=True, activation='tanh'))
model.add(tf.keras.layers.LSTM(64, return_sequences=True, activation='tanh'))
model.add(tf.keras.layers.LSTM(1, return_sequences=False, activation='sigmoid')) #0~1사이의 실수값이기 때문에 sigmoid를 사용
model.summary()

model.compile(optimizer='adam', loss='mse', metrics=['accuracy']) #숫자값이기 때문에 mse를 사용

model.fit(X_train, y_train, epochs=100)

model.save('SAMSUNG_STOCK.keras')

predicts = model.predict(X_test)

from matplotlib import pyplot as plt
plt.figure(figsize=(10,10))
plt.plot(y_test, color='red', label='Target') #실제
plt.plot(predicts, color='blue', label='Prediction') #예상
plt.legend(loc='best')
plt.show()
