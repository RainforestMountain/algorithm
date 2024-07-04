import pandas as pd
import numpy as np

# 读取Excel文件
df = pd.read_excel('excel.xlsx', sheet_name='Sheet1', index_col='姓名')
print("原始数据：")
print(df)

df.loc['张艳', '计算机'] = 80
print("\n修改张艳同学的计算机成绩为80分：")
print(df)

waiyu_students = df[df['专业'] == '外语']
print("\n专业为外语的学生信息：")
print(waiyu_students)

high_computer_scores = df[df['计算机'] >= 90].index.tolist()
print("\n计算机成绩大于等于90的学生姓名：")
print(high_computer_scores)

df[df < 0] = df[df < 0].abs()
print("\n处理负成绩为正成绩：")
print(df)

df.fillna(0, inplace=True)
print("\n缺失值处理：")
print(df)

df = df.drop_duplicates()
print("\n删除重复成绩：")
print(df)

df['平均分'] = df.mean(axis=1)
print("\n每个学生的各科平均分：")
print(df)

df['总成绩'] = df.sum(axis=1)
print("\n每个学生的总成绩：")
print(df)

def evaluate_performance(avg_score):
    if avg_score >= 80:
        return '优良'
    elif avg_score >= 60:
        return '及格'
    else:
        return '不及格'

df['总评'] = df['平均分'].apply(evaluate_performance)
print("\n按平均分进行学生总评：")
print(df)

df.sort_values(by=['总成绩', '计算机'], ascending=[False, False], inplace=True)
print("\n按总成绩降序排序，如果总成绩相同，则按计算机成绩降序排序：")
print(df)

df.to_excel('学生信息表.xlsx', sheet_name='资料信息表')
print("\n数据已保存到学生信息表.xlsx")

profession_counts = df['专业'].value_counts()
print("\n各专业的人数：")
print(profession_counts)

computer_stats = df.groupby('专业')['计算机'].agg(['max', 'min', 'mean', 'median']).round(2)
print("\n各专业的计算机成绩统计：")
print(computer_stats)

pivot_table = pd.pivot_table(df, values=['英语', '计算机', '数学'], index=['专业', '总评'], aggfunc={'mean', 'max'}, fill_value=0)
print("\n数据透视表：")
print(pivot_table)

# 保存数据透视表到Excel中
with pd.ExcelWriter('学生信息表.xlsx', mode='a') as writer:
    pivot_table.to_excel(writer, sheet_name='数据透视表')
print("\n数据透视表已保存到学生信息表.xlsx")