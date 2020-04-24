#!/usr/bin/env python2
import random, os, sys

def generate_combination():
    combination = []
    for i in range(3):
        numbers = ""
        for _ in range(10):
            rand_num = random.randint(0, 99)
            if rand_num < 10:
                numbers += "0"
            numbers += str(rand_num)
            if _ != 9:
                numbers += "-"
        combination.append(numbers)
    return combination


if __name__ == '__main__':
    sessionId = str(sys.argv[1])
    random.seed(os.getpid())
    combList = generate_combination()
    f = open('/tmp/combination-' + sessionId + '.txt', 'w+')
    for comb in combList:
        f.write(str(comb)+'\n')
    f.close()
