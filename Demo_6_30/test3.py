import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# 读取Excel文件
df = pd.read_excel('excel.xlsx', sheet_name='Sheet2', index_col='姓名')
print("原始数据：")
print(df)

plt.figure(figsize=(10, 6))
plt.plot(df.index, df['计算机'], marker='o', linestyle='-', color='b')
plt.title('计算机成绩折线图')
plt.xlabel('姓名')
plt.ylabel('计算机成绩')
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 6))
df['计算机'].head(5).plot(kind='bar', color='c', edgecolor='k')
plt.title('前5个学生的计算机成绩柱状图')
plt.xlabel('姓名')
plt.ylabel('计算机成绩')
plt.xticks(rotation=0)
plt.show()

plt.figure(figsize=(10, 6))
df.head(5).plot(kind='bar', edgecolor='k')
plt.title('前5个学生的各科成绩柱状图')
plt.xlabel('姓名')
plt.ylabel('成绩')
plt.xticks(rotation=0)
plt.legend(loc='upper right')
plt.show()

plt.figure(figsize=(10, 6))
df.loc[df.index[:4], ['英语', '数学', '语文', '计算机']].sum().plot(kind='pie', autopct='%1.1f%%', startangle=140)
plt.title('前4个学生成绩饼状图')
plt.ylabel('')
plt.show()

# 选择一个学生，例如第一个学生
student_name = df.index[0]
student_scores = df.loc[student_name, ['英语', '数学', '语文', '计算机']]

# 雷达图的标签
labels = student_scores.index
num_vars = len(labels)

# 计算角度
angles = np.linspace(0, 2 * np.pi, num_vars, endpoint=False).tolist()

# 使雷达图闭合
student_scores = student_scores.tolist()
student_scores += student_scores[:1]
angles += angles[:1]

# 绘制雷达图
fig, ax = plt.subplots(figsize=(6, 6), subplot_kw=dict(polar=True))
ax.fill(angles, student_scores, color='b', alpha=0.25)
ax.plot(angles, student_scores, color='b', linewidth=2)

# 添加标签
ax.set_yticklabels([])
ax.set_xticks(angles[:-1])
ax.set_xticklabels(labels)

plt.title(f'{student_name}的成绩雷达图')
plt.show()
