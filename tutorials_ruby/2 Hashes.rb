#!/usr/bin/ruby

hsh1 = {"Sreejith"=>"Human", "Lion"=>"Animal"}

hsh2 = {"Sreejith", "Human", "Lion", "Animal"}


hsh1.each do |key, value|
	print "hash1: ", key, " is ", value, "\n"
end


hsh2.each do |key, value|
	print "hash2: ", key, " is ", value, "\n"
end