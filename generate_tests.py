<<<<<<< HEAD
import glob

makefileTests = file('Makefile_tests', 'w')
files = glob.glob('src/core/*_test.cpp')
str = ''
all = ''

for file in files:
  f = file[9:-4]
  all = all + ' ' + f
  str = str + f + ':\n\tscons ' + f + '\n\t./' + f + '\n'
str = str + '\nall_tests:' + all + '\n\n'
str = str + '.PHONY:' + all + '\n'

makefileTests.write(str)
=======

testFile = file('tests.txt', 'r')
makefileTests = file('Makefile_tests', 'w')

s = 'init'
while(s != EOF):
  s = testFile.readline()
  print s
  s = s.replace('\n', '')
  s = s + '_test'
  str = s + ':\n\tscons build/' + s + '\n\t./build/' + s
  # makefileTests.write(str)

print str
>>>>>>> 5e386ff4860c1d51e1528e55a41222c4a6c3da65
