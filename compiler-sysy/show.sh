./sysyc -s ./Test/1.sy ./Output/1.s
gcc -static ./Output/1.s -o ./Build/1 

./sysyc -s ./Test/2.sy ./Output/2.s
gcc -static ./Output/2.s -o ./Build/2 


./sysyc -s ./Test/3.sy ./Output/3.s
gcc -static ./Output/3.s -o ./Build/3 


./sysyc -s ./Test/4.sy ./Output/4.s
gcc -static ./Output/4.s -o ./Build/4


./sysyc -s ./Test/0.sy ./Output/0.s
gcc -static ./Output/0.s -o ./Build/0
