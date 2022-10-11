# University of Washington, Programming Languages, Homework 6, hw6runner.rb

require_relative './tetrisprovided.rb'
require_relative './tetrisassignment.rb'

def runTetris
  Tetris.new 
  mainLoop
end

def runMyTetris
  MyTetris.new
  mainLoop
end

if ARGV.count == 0
  runMyTetris
elsif ARGV.count != 1
  puts "usage: tetrisrunner.rb [enhanced | original]"
elsif ARGV[0] == "enhanced"
  runMyTetris
elsif ARGV[0] == "original"
  runTetris
else
  puts "usage: tetrisrunner.rb [enhanced | original]"
end
