TestRule: main.cpp 
	g++ -g -W -Wall -pedantic-errors main.cpp point.cpp line.cpp triangle.cpp polygon.cpp -o testProg.exe -static-libgcc -static-libstdc++ 
