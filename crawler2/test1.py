# import csv
# import requests
# import re
# import time
#
# url = f'https://www.bilibili.com/video/BV1Er421c74D/?spm_id_from=333.1007.tianma.1-1-1.click&vd_source=af79a8b303a429e9e4ac136384f57db2?'
# headers = {
#     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36'
# }
#
# response = requests.get(url, headers)
# print(response.status_code)

import re

src = re.findall(r'a(.+?)g', "abbcccggg")
print(src)
