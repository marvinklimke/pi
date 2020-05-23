#!/usr/bin/env python3
"""Calculate the value of pi using multiprocessing in Python"""

from datetime import datetime
from multiprocessing import Pool
import os
from sys import argv


def compute(args):
    begin, end, num_steps = args
    subtotal = 0.0
    for i in range(begin, end):
        x = (i + 0.5) / num_steps
        subtotal += 4.0 / (1.0 + x**2)
    subtotal /= num_steps
    return subtotal


def main():
    num_processes = os.cpu_count()
    num_steps = 1000000
    if len(argv) > 2:
        num_processes = int(argv[2])
    if len(argv) > 1:
        num_steps = int(argv[1])

    print("Calculating pi using {} processes in {} steps...".format(num_processes, num_steps))

    start = datetime.now()

    args = []
    for i in range(num_processes):
        args.append((int(i * num_steps / num_processes),
                     int((i + 1) * num_steps / num_processes),
                     num_steps))
    with Pool(num_processes) as pool:
        subtotals = pool.map(compute, args)
    total = sum(subtotals)

    finish = datetime.now()
    duration = finish - start

    print("==> pi = {}".format(total))
    print("Calculation took {} seconds.".format(duration.total_seconds()))


if __name__ == "__main__":
    main()
