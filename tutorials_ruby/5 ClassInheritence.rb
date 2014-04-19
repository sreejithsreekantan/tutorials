#!/usr/bin/ruby

class Parent
	def talk_something
		puts "blah... blah... blah..."
	end
end

class Child < Parent
	
end

class GrandChild < Child
	def talk_something
		puts "buhahahaha.... "
	end
end

c = Child.new
c.talk_something

c = GrandChild.new
c.talk_something