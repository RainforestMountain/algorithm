import requests
from bs4 import BeautifulSoup
import re

headers = {"User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
                         "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36"}
page = 5  # 读取评论几页
comments = []
for start_num in range(0, page):
    url = f"https://movie.douban.com/subject/1292722/comments?start={start_num * 20}&limit=20&status=P&sort=new_score"
    response = requests.get(url, headers=headers)
    response.encoding = "utf-8"
    # print(response.status_code)
    soup = BeautifulSoup(response.text, 'html.parser')

    # 定位评论区的区域
    comment_section = soup.find_all("div", attrs={"class": "comment"})

    # print(str(comment_section))
    # 提取内容

    comment_elements = re.findall(r'<span class="short">(.+?)<\/span>', str(comment_section))
    print(f"page{start_num}: ")
    for elements in comment_elements:
        print(elements)
    print()