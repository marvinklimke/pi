#!/usr/bin/env python3
"""Calculate the value of pi using a sequential approach in Python"""

from datetime import datetime
from sys import argv


num_steps = 1000000
if(len(argv) > 1):
	num_steps = int(argv[1])

print("Calculating pi in {} steps...".format(num_steps))

start = datetime.now()

total = 0.0
for i in range(num_steps):
	x = (i + 0.5) / num_steps
	total += 4.0 / (1.0 + x**2)
total /= num_steps

finish = datetime.now()
duration = finish - start

print("==> pi = {}".format(total))
print("Calculation took {} seconds.".format(duration.total_seconds()))
