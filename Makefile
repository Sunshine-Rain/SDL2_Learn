includeDir = ./include
objects = mian.o ResourceManager.o SDLApp.o TexturedRectangle.o SDLAppPosition.o

build:
	/usr/bin/clang++ -std=c++17 \
	-I/Users/quan/Desktop/codes/demos/1.cDemos/del_cpp/include \
	-fcolor-diagnostics -fansi-escape-codes \
	/Users/quan/Desktop/codes/demos/1.cDemos/del_cpp/src/main.cpp \
	-o /Users/quan/Desktop/codes/demos/1.cDemos/del_cpp/bin/main \
	-lsdl2

run: 
	./bin/main

SDLApp.o: 
SDLAppPosition.o: 
ResourceManager.o 