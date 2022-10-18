RUN HEAP TESTS
cd heap_test
make
make test

RUN LOGICSIM
make

respective commands:
./logicsim single_and.txt > my_and.uml 
java -jar plantuml.jar my_and.uml

./logicsim single_or.txt > my_or.uml 
java -jar plantuml.jar my_or.uml

./logicsim single_not.txt > my_not.uml 
java -jar plantuml.jar my_not.uml

./logicsim exclusive_or.txt > my_exclusive_or.uml 
java -jar plantuml.jar my_exclusive_or.uml