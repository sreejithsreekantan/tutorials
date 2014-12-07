#! /usr/bin/python

numOfInstances = int(raw_input())

for x in xrange(1,numOfInstances+1):
	limit = int(raw_input())
	numOfItems = int(raw_input())
	d = dict()
	items = [int(x) for x in raw_input().split()]
	for y in xrange(1,numOfItems+1):
		if items[y-1] not in d:
			d[items[y-1]] = set() 
		d[items[y-1]].add(y)

 	print d

	for x in d.keys():
		if x <= limit:
			index = d[x].pop()
			if (limit-x) in d and len(d[limit-x])>0:
				index2=d[limit-x].pop()
				d[limit-x].add(index2)
				print min(index, index2), max(index, index2)
			d[x].add(index)

