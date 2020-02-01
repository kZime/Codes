#!/usr/bin/env python3

import os
import fnmatch

def search(pattern, root=os.curdir):
    for path, dirs, files in os.walk(os.path.abspath(root)):
        for filename in fnmatch.filter(files, pattern):
            yield os.path.join(path, filename)

for x in search("*.run"): 
    print ("Deleting {0}".format(x))
    os.remove(x)
for x in search("*.out"):
    print ("Deleting {0}".format(x))
    os.remove(x)
for x in search("*.ans"):
    print ("Deleting {0}".format(x))
    os.remove(x)
for x in search("*.in"):
    print ("Deleting {0}".format(x))
    os.remove(x)
