#!/usr/bin/env python
# coding: utf-8

import os
import requests

url ='https://api.webempath.net/v2/analyzeWav'

apikey = os.environ['API_KEY']
payload = {'apikey': apikey}

wav = "./voices/voice.wav"
data = open(wav, 'rb')
file = {'wav': data}

res = requests.post(url, params=payload, files=file)
print(res.json())