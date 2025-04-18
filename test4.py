import tensorflow as tf
import numpy as np
from sklearn import datasets
import matplotlib.pyplot as plt

# 1. 数据准备
iris = datasets.load_iris()
x_data = iris.data
y_data = iris.target

# 将数据集打乱
np.random.seed(116)
np.random.shuffle(x_data)
np.random.seed(116)
np.random.shuffle(y_data)

# 分割训练集和测试集
x_train = x_data[:-30]
y_train = y_data[:-30]
x_test = x_data[-30:]
y_test = y_data[-30:]

# 转换数据类型
x_train = tf.cast(x_train, tf.float32)
x_test = tf.cast(x_test, tf.float32)

# 创建数据集
train_db = tf.data.Dataset.from_tensor_slices((x_train, y_train)).batch(32)
test_db = tf.data.Dataset.from_tensor_slices((x_test, y_test)).batch(32)

# 2. 模型参数初始化
w1 = tf.Variable(tf.random.truncated_normal([4, 3], stddev=0.1, seed=1))
b1 = tf.Variable(tf.random.truncated_normal([3], stddev=0.1, seed=1))

lr = 0.1  # 学习率
epoch = 500  # 训练轮数
train_loss_results = []  # 记录训练loss
test_acc = []  # 记录测试准确率

# 3. 训练过程
for epoch in range(epoch):
    loss_all = 0
    for step, (x_train_batch, y_train_batch) in enumerate(train_db):
        with tf.GradientTape() as tape:
            # 前向传播
            y = tf.matmul(x_train_batch, w1) + b1
            y = tf.nn.softmax(y)
            # 转换为one-hot编码
            y_ = tf.one_hot(y_train_batch, depth=3)
            # 计算损失
            loss = tf.reduce_mean(tf.square(y_ - y))
            loss_all += loss.numpy()

        # 反向传播
        grads = tape.gradient(loss, [w1, b1])
        # 参数更新
        w1.assign_sub(lr * grads[0])
        b1.assign_sub(lr * grads[1])

    # 打印loss
    print("Epoch {}, loss: {}".format(epoch, loss_all / 4))
    train_loss_results.append(loss_all / 4)

    # 4. 测试过程
    total_correct, total_number = 0, 0
    for x_test_batch, y_test_batch in test_db:
        # 预测
        y = tf.matmul(x_test_batch, w1) + b1
        y = tf.nn.softmax(y)
        pred = tf.argmax(y, axis=1)
        pred = tf.cast(pred, dtype=y_test_batch.dtype)
        # 计算正确率
        correct = tf.cast(tf.equal(pred, y_test_batch), dtype=tf.int32)
        correct = tf.reduce_sum(correct)
        total_correct += int(correct)
        total_number += x_test_batch.shape[0]

    acc = total_correct / total_number
    test_acc.append(acc)
    print("Test_acc:", acc)
    print("---")

# 5. 可视化
# 绘制loss曲线
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.title('Loss Function Curve')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.plot(train_loss_results, label="Loss")
plt.legend()

# 绘制accuracy曲线
plt.subplot(1, 2, 2)
plt.title('Accuracy Curve')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.plot(test_acc, label="Accuracy")
plt.legend()

plt.tight_layout()
plt.show()
