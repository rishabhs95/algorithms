#!/bin/python3

import os
import glob

files = glob.glob('*')
files.sort(key=os.path.getmtime)
counter = len(files)+31

for file in files:
	if (counter%4 == 0 or counter%5 == 0):
		counter = counter-1
	if file[0] != '.':
		os.system("git add " + file)
		os.system("git commit -m 'Add " + file + "' --date " + str(counter) + ".days.ago")
	counter = counter-1	