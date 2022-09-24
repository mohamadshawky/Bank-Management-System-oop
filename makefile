all: app.exe
	@ app.exe
	
app.exe: obj/app.o obj/cClient.o obj/cAdmin.o
	@ g++ obj/app.o obj/cClient.o obj/cAdmin.o -o app.exe

obj/app.o: app.cpp
	@ g++ -c app.cpp -o obj/app.o
 
obj/cClient.o: src/cClient.cpp
	@ cd src && g++ -c cClient.cpp -o ../obj/cClient.o
 
obj/cAdmin.o: src/cAdmin.cpp
	@ cd src && g++ -c cAdmin.cpp -o ../obj/cAdmin.o
