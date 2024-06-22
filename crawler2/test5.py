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


page = 1


def jude(rating, titleRegion):
    for i in range(0, len(titleRegion)):
        if str(rating).__contains__(str(titleRegion[i])):
            return True
    return False


# 5个用户
def getTitleAndRating(page, url):
    movieTitle = []
    movieRating = []
    url = re.split("start=0", url)
    for i in range(0, page):
        headers = {"User-Agent": get_random_user_agent()}
        url = url[0] + f"start={i * 15}" + url[1]
        response = requests.get(url, headers=headers)
        response.encoding = "utf-8"
        html = response.text
        soup = BeautifulSoup(html, "html.parser")
        titleRegion = soup.find_all("li", attrs={"class": "title"})
        ratingRegion = soup.find_all("div", attrs={"class": "info"})
        for title in titleRegion:
            movieTitle.append(str(re.findall(r'<em>([^<]+)</em>', str(title)))[0])
        for rating in ratingRegion:
            if jude(rating, titleRegion):
                if len(re.findall(r'<span class="rating\d-t"><\/span>', str(rating))) == 0:
                    movieRating.append(float(2))
                else:
                    movieTitle.append(float(re.findall(r'<span class="rating(\d)-t"><\/span>', str(rating))[0]))
        return movieTitle, movieRating


user1T, user1R = getTitleAndRating(1,
                                   "https://movie.douban.com/people/whiterhinoceros/collect?sort=time&start=0&mode=grid&tags_sort=count")
user2T, user2R = getTitleAndRating(1,
                                   "https://movie.douban.com/people/ruxiaoguo/collect?start=0&sort=time&rating=all&mode=grid&type=all&filter=all")

user3T, user3R = getTitleAndRating(1,
                                   "https://movie.douban.com/people/lazywormzhao/collect?sort=time&start=0&mode=grid&tags_sort=count")
user4T, user4R = getTitleAndRating(1,
                                   "https://movie.douban.com/people/58718941/collect?sort=time&start=0&mode=grid&tags_sort=count")
user5T, user5R = getTitleAndRating(1,
                                   "https://movie.douban.com/people/suoliweng/collect?sort=time&start=0&mode=grid&tags_sort=count")
titles = user1T + user2T + user3T + user4T + user5T
rating = user1R + user2R + user3R + user4R + user5R
print(len(titles))
print(len(rating))
for i in range(0, len(rating)):
    print(titles[i], ":", rating[i])
