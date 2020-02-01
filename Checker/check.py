#!/usr/bin/env python3

import os

def cat(file):
    with open(file, "r") as f:
        for line in f:
            print(line)

try:
    i = 1
    os.system("g++ maker.cpp -o maker.run -O2")
    os.system("g++ baoli.cpp -o baoli.run -O2")
    os.system("g++ right.cpp -o right.run -O2")
    
    while True:
        os.system("./maker.run > yl")
        os.system("./right.run < yl > r1")
        os.system("./baoli.run < yl > r2")
        if os.system("diff -B -q r1 r2"):
            print("Wrong answer at pretest %d" % i)
            """
            print("-----------------------\nyangli:\n");
            cat("yl")
            print("-----------------------\nout1:\n");
            cat("r1")
            print("-----------------------\nout2:\n");
            cat("r2")
            print("-----------------------\n");
            print(" no\n");
            """
            break
        else:
            print("Accepted at pretest %d" % i)
            i += 1
except KeyboardInterrupt:
    pass
os.system("rm *.run r1 r2 yl &> /dev/null")
