#!/usr/bin/ruby

class Child
	def method1()
		puts "method1: Why did you call me?"
	end
end

c = Child.new
c.method1()
