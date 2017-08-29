#!/usr/bin/env python 

import re

"""Function to extract time of line"""
def time_extract(line):
	time_text = line.split("/")[0]
	time = float(time_text.split()[1])
	return time

"""For extracting No of packets in Queue  """
# opening files
with open("tcp-example.tr","r") as inputfile :
	with open("queue_occupancy.txt","w") as outputfile :
		# Reading line by line
		lines = inputfile.readlines()
		no_of_packet_in_queue_now = 0
		for line in lines:
			# Checking for incoming of packet in queue
			if "Enqueue"  in line :
				no_of_packet_in_queue_now = no_of_packet_in_queue_now + 1
				outputfile.write(str(time_extract(line)) + " " + str(no_of_packet_in_queue_now) + "\n")
			# Checking for outgoing of packet from queue			
			elif "Dequeue"  in line :
				no_of_packet_in_queue_now = no_of_packet_in_queue_now - 1
				outputfile.write(str(time_extract(line)) + " " + str(no_of_packet_in_queue_now) + "\n")
							
					
 
			













