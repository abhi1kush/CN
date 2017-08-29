#!/usr/bin/env python 

import re

"""Function to extract how many bytes transfered"""
def payload_of_one_line(line):
	if "NodeList/1" in line :
		halfline = line.split("length:")[1]
		payload = int(halfline.split()[0]) -40
	return payload


"""For extracting Throughput """
# opening files
with open("tcp-example.tr","r") as inputfile :
	with open("tcp_throughput.txt","w") as outputfile :
		# Reading line by line
		lines = inputfile.readlines()
		
		# Searching first activity of node 1
		for l in lines:
			if "NodeList/1" in l :
				time_text = l.split("/")[0]
				first_time = float(time_text.split()[1])
				break
		bytes=0		
		for line in lines:
			# Checking existence of Payload data in line
			if "NodeList/1"  in line :
				time_text = line.split("/")[0]
				time = float(time_text.split()[1])
				if time - first_time<=1.0:
					bytes = bytes + payload_of_one_line(line)
				else :	
					outputfile.write(str(time) + " " + str(bytes*8) + "\n")
					first_time = time
					bytes = payload_of_one_line(line)
 
			













