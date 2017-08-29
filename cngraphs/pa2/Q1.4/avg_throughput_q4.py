#!/usr/bin/env python 
import re
import string

"""Function to extract time of line"""
def time_extract(line):
	time_text = line.split("/")[0]
	time = time_text.split()[1]
	return time

# opening files
with open("throughput_q4.txt","r") as inputfile :
	with open("avg_throughput_q4.txt","w") as outputfile :
		# Reading line by line
		lines = inputfile.readlines()
		i=0
		bytes =0
		end_count = 0
		for line in lines:
			
			if "start" not in line and "end" not in line :
					bytes = bytes + int(line.split()[1])
			#extracting time
			if "start" in line :
				f_time = lines[i+1].split()[0]
			if"end" in line:
				l_time = lines[i-1].split()[0]
				t_time = float(l_time) - float(f_time) + 1.0
				throughput = float(bytes)/t_time
				rate = 10**(-3-end_count)
				outputfile.write(str(rate) + " " + str(throughput) + "\n")
				end_count = end_count + 1
				bytes=0	
			i=i+1
				
