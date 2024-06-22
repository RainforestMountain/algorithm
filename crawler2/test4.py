import requests
from bs4 import BeautifulSoup
import re
import random
import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np

USER_AGENTS = [

    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.19582',

    'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:78.0) Gecko/20100101 Firefox/78.0',

    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36 Edge/16.16299',
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36"
    # 更多用户代理信息...

]


def get_random_user_agent():
    return random.choice(USER_AGENTS)


page = 7
movieName = []
score = []
comment = []
for start_num in range(0, page):
    url = f"https://www.douban.com/people/tjz230/reviews?start={start_num * 10}"
    headers = {"User-Agent": get_random_user_agent()}
    response = requests.get(url, headers=headers)
    # print(response.status_code)
    # 电影加上评分
    response.encoding = "utf-8"
    soup = BeautifulSoup(response.text, "html.parser")
    # 获得评分名字评论的html区域,方便正则表达式匹配
    scoreRegion = soup.find_all("header", attrs={"class": "main-hd"})
    nameRegion = soup.find_all("div", attrs={"class": "main-bd"})
    commentRegion = soup.find_all("div", attrs={"class": "short-content"})

    for i in range(0, len(scoreRegion)):
        try:
            score.append(int((re.findall(r'<span class="allstar(\d+) main-title-rating" title="[^"]*"></span>',
                                         str(scoreRegion[i])))[0]) / 10.0)
            movieName.append(
                re.findall(r'<h2><a href="https://movie.douban.com/review/\d+/">([^<]+)</a></h2>', str(nameRegion[i]))[
                    0])
            print(re.split(" ", re.findall(
                r'<div class="short-content">\s*([^<]+)\s*',
                str(commentRegion[i]))[0])[0])
            comment.append(re.split(" ", re.findall(
                r'<div class="short-content">\s*([^<]+)\s*',
                str(commentRegion[i]))[0])[0])
        except Exception as e:
            print(e)


# 创建一个DataFrame来处理数据
data = {'movie': movieName[0:50], 'rating': score[0:50], 'comment': comment[0:50]}
df = pd.DataFrame(data)

# 假设你已经有了用户ID和电影ID的映射
# 这里为了示例，生成一些假数据
user_ids = [random.randint(1, 10) for _ in range(len(df))]
movie_ids = [random.randint(1, 100) for _ in range(len(df))]
df['user_id'] = user_ids
df['movie_id'] = movie_ids

# 构建用户-电影评分矩阵
rating_matrix = df.pivot_table(index='user_id', columns='movie_id', values='rating').fillna(0)

# 计算相似度矩阵
user_similarity = cosine_similarity(rating_matrix)
np.fill_diagonal(user_similarity, 0)
user_similarity_df = pd.DataFrame(user_similarity, index=rating_matrix.index, columns=rating_matrix.index)


# 基于用户的协同过滤推荐
def get_user_recommendations(user_id, num_recommendations=5):
    user_ratings = rating_matrix.loc[user_id].values.reshape(1, -1)
    user_similarities = user_similarity_df[user_id].values.reshape(1, -1)
    weighted_sum = user_similarities.dot(rating_matrix.values)
    norm_factor = np.array([np.abs(user_similarities).sum(axis=1)]).T
    predicted_ratings = weighted_sum / norm_factor
    predicted_ratings = predicted_ratings.flatten()

    recommendations = pd.Series(predicted_ratings, index=rating_matrix.columns)
    recommendations = recommendations.sort_values(ascending=False).head(num_recommendations)
    return recommendations


# 获取用户1的电影推荐
user_id = 1
recommendations = get_user_recommendations(user_id)
print(f"为用户 {user_id} 推荐的电影ID：", recommendations.index.tolist())

# 基于内容的推荐系统（假设我们有电影的内容特征）
# 这里为了简化，假设电影ID和电影内容特征已经提取好
movie_features = pd.DataFrame(np.random.rand(100, 5), index=range(1, 101))

# 计算电影相似度矩阵
movie_similarity = cosine_similarity(movie_features)
np.fill_diagonal(movie_similarity, 0)
movie_similarity_df = pd.DataFrame(movie_similarity, index=movie_features.index, columns=movie_features.index)


# 基于内容的推荐函数
def get_content_based_recommendations(movie_id, num_recommendations=5):
    movie_similarities = movie_similarity_df[movie_id].sort_values(ascending=False)
    recommendations = movie_similarities.head(num_recommendations)
    return recommendations


# 获取电影ID 1 的相似电影推荐
movie_id = 1
content_recommendations = get_content_based_recommendations(movie_id)
print(f"与电影ID {movie_id} 相似的电影ID：", content_recommendations.index.tolist())