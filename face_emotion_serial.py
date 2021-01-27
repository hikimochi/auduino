#!/usr/bin/env python
# coding: utf-8

import requests
import json
import time
import serial

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

def stress_level(anger, sad):
    stress = anger + sad
    print(stress)
    if 0.6 < stress:
        print('level 3')
        ser.write(b'3')
    elif 0.2 < stress <= 0.6:
        print('level 2')
        ser.write(b'2')
    else:
        print('level 1')
        ser.write(b'1')
    return


with serial.Serial('/dev/tty.usbmodem144401', 115200, timeout=0.1) as ser:
    time.sleep(2)
    stress_level(sad, anger)
    ser.close()