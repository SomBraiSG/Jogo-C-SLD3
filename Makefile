

gcc-opts=-std=c++17 
gcc-includes=-I"SDL2-2.30.3\x86_64-w64-mingw32\include" -L"SDL2-2.30.3\x86_64-w64-mingw32\lib"
compiler=g++
files= src/main.cpp src/GM_render.cpp
libs= -lmingw32 -lSDL2main -lSDL2



all:
	$(compiler) $(gcc-opts) $(files) $(gcc-includes) $(libs)   -o game.exe   -static-libstdc++


