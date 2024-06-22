import requests
from bs4 import BeautifulSoup
import re
import random
import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
USER_AGENTS = [

    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.19582',

    'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:78.0) Gecko/20100101 Firefox/78.0',

    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36 Edge/16.16299',

    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36"
    # 更多用户代理信息...

]


def get_random_user_agent():
    return random.choice(USER_AGENTS)


for start_num in range(0, 250, 25):
    headers = {"User-Agent": get_random_user_agent()}
    response = requests.get(f"https://movie.douban.com/top250?start={start_num}", headers=headers)
    html = response.text
    soup = BeautifulSoup(html, "html.parser")
    all_titles = soup.findAll("span", attrs={"class": "title"})
    all_score = soup.find_all("span", attrs={"class": "rating_num"})
    titles = []
    rating = []
    for i in range(0, len(all_score)):
        try:
            # print(all_titles[i].string)
            titles.append(all_titles[i].string)
            # print(all_score[i].string)
            rating.append(float(all_score[i].string))
        except Exception as e:
            print(e)
    # 假设我们已经获取了电影数据
    data = {'title': titles, 'rating': rating}
    df = pd.DataFrame(data)

    # 数据清洗
    df.dropna(inplace=True)
    df['rating'] = df['rating'].astype(float)

    print(df)

# 假设我们有用户评分矩阵
ratings_matrix = np.array([
    [5, 4, 0, 0],
    [4, 0, 0, 2],
    [0, 0, 5, 4],
    [0, 3, 4, 0]
])

# 计算相似度
user_similarity = cosine_similarity(ratings_matrix)
print(user_similarity)


# 基于用户相似度的推荐
def recommend(user_index, ratings_matrix, user_similarity):
    similar_users = user_similarity[user_index]
    weighted_ratings = np.dot(similar_users, ratings_matrix)
    recommendation = weighted_ratings / np.array([np.abs(similar_users).sum(axis=0)])
    return recommendation


user_index = 0
recommendations = recommend(user_index, ratings_matrix, user_similarity)
print(recommendations)



# 假设我们有电影的描述数据
descriptions = [
    "Action Adventure",
    "Romantic Comedy",
    "Action Thriller",
    "Comedy Drama"
]

# 计算TF-IDF
vectorizer = TfidfVectorizer()
tfidf_matrix = vectorizer.fit_transform(descriptions)

# 计算相似度
cosine_sim = cosine_similarity(tfidf_matrix, tfidf_matrix)
print(cosine_sim)

# 基于内容的推荐
def content_recommend(movie_index, cosine_sim):
    similar_movies = list(enumerate(cosine_sim[movie_index]))
    similar_movies = sorted(similar_movies, key=lambda x: x[1], reverse=True)
    return similar_movies

movie_index = 0
content_recommendations = content_recommend(movie_index, cosine_sim)
print(content_recommendations)
