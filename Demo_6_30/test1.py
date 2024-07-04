import numpy as np

# 学生数据
students = {
    'A': {'height': 175, 'weight': 72},
    'B': {'height': 180, 'weight': 78},
    'C': {'height': 168, 'weight': 62},
    'D': {'height': 178, 'weight': 70},
    'E': {'height': 182, 'weight': 77},
    'F': {'height': 185, 'weight': 88}
}

# 提取身高和体重数据
heights = np.array([students[student]['height'] for student in students])
weights = np.array([students[student]['weight'] for student in students])

# 计算均值
mean_height = np.mean(heights)
mean_weight = np.mean(weights)

# 计算方差
var_height = np.var(heights)
var_weight = np.var(weights)

# 计算标准差
std_height = np.std(heights)
std_weight = np.std(weights)

# 计算协方差
cov_height_weight = np.cov(heights, weights, bias=True)[0][1]

# 计算相关系数
corr_height_weight = np.corrcoef(heights, weights)[0][1]

# 输出结果
print(f"身高均值: {mean_height}")
print(f"体重均值: {mean_weight}")
print(f"身高方差: {var_height}")
print(f"体重方差: {var_weight}")
print(f"身高标准差: {std_height}")
print(f"体重标准差: {std_weight}")
print(f"身高和体重的协方差: {cov_height_weight}")
print(f"身高和体重的相关系数: {corr_height_weight}")