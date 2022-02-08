from time import sleep

import aclib

p = aclib.Physics()
g = aclib.Graphics()
s = aclib.Statics()

target = s

for i in range(0, 10):
    for pr in dir(target):
        if not pr.startswith('_'):
            print(pr, getattr(target, pr), end=" | ")
    print()
    sleep(1)

