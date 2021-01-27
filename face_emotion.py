#!/usr/bin/env python
# coding: utf-8

import requests
import json
import time
import serial

# APIのみ
# image
image_path = './images/komari.jpg'
image =  open(image_path, 'rb').read()

# face api
url = "https://ai-api.userlocal.jp/face"
res = requests.post(url, files={"image_data": image})
data = json.loads(res.content)
result = data['result']

for r in result:
    print(f"""
    年齢: {r['age']}
    感情: {r['emotion']}
    性別: {r['gender']}
    顔の向き: {r['head_pose']}
    顔の位置: {r['location']}
    感情詳細: {r['emotion_detail']}
    """)
    anger = r['emotion_detail']['anger']
    sad = r['emotion_detail']['sad']