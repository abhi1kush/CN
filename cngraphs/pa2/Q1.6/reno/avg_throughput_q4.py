#!/usr/bin/env python 
import re
import string


# opening files
with open("tcp_throughput.txt","r") as inputfile :
	with open("bytes.txt","w") as outputfile :
		# Reading line by line
		lines = inputfile.readlines()
		bytes =0
		i=0
		for line in lines :
			i=i+1
		j=1
		for line in lines:
			if j == 1 :
				ft= float(line.split()[0])
			if j == i :
				lt=float(line.split()[0]) 
			bytes = bytes + int(line.split()[1])
			j=j+1
		print lt 
		print ft
		print lt-ft+1
		throughput= float(bytes)*10**(-6)/(lt-ft + 1)
			
		outputfile.write( "thr" + str(throughput) )
		print "thr" + str(throughput)

with open("queue_occupancy.txt","r") as inputfile :
	with open("bytes.txt","a") as outputfile :
		# Reading line by line
		lines = inputfile.readlines()
		bytes =0.0
		i=0
		for line in lines :
			i=i+1
		j=1
		for line in lines: 
			bytes = bytes + float(line.split()[1])
		throughput= float(bytes)/i	
		outputfile.write( "occupancy" + str(throughput) )
		print "occupancy"+str(throughput)

with open("queueing_delay.txt","r") as inputfile :
	with open("bytes.txt","a") as outputfile :
		# Reading line by line
		lines = inputfile.readlines()
		bytes =0.0
		i=0
		for line in lines :
			i=i+1
		j=1
		for line in lines: 
			bytes = bytes + float(line.split()[1])
		throughput= float(bytes)/i	
		outputfile.write( "delay" + str(throughput) )
		print "delay"+str(throughput)

with open("tcp-example.cwnd","r") as inputfile :
	with open("bytes.txt","a") as outputfile :
		# Reading line by line
		lines = inputfile.readlines()
		bytes =0.0
		i=0
		for line in lines :
			i=i+1
		j=1
		for line in lines: 
			bytes = bytes + float(line.split()[1])
		throughput= float(bytes)/i	
		outputfile.write( "cwnd " + str(throughput) )
		print "cwnd "+ str(throughput)
