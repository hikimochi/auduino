#!/usr/bin/env python
# coding: utf-8

import os
import requests
import json
import time
import serial

# face API
image_path = './images/sample.jpg'
image =  open(image_path, 'rb').read()
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
    anger_face = r['emotion_detail']['anger']
    sad_face = r['emotion_detail']['sad']

# voice API
voice_url ='https://api.webempath.net/v2/analyzeWav'
apikey = os.environ['API_KEY']
payload = {'apikey': apikey}
wav= './voices/sample.wav'
voice_data = open(wav, 'rb')
file = {'wav': voice_data}

res = requests.post(voice_url, params=payload, files=file)
param = res.json()
anger_voice = param['anger']
sorrow_voice = param['sorrow']


def stress_level(anger_face, sad_face, anger_voice, sorrow_voice):
    stress = anger_face + sad_face + anger_voice/100 + anger_face/100
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

# Arduino
device = '/dev/tty.usbmodem144401'

with serial.Serial(device, 115200, timeout=0.1) as ser:
    time.sleep(2)
    stress_level(anger_face, sad_face, anger_voice, sorrow_voice)
    ser.close()