all: mac linux windows

mac :
	@g++ -dynamiclib -o fwlib.dylib fwlib.cpp

linux :
	@g++ -fPIC fwlib.cpp -shared -o fwlib.so

windows :
	@g++ -c -o fwlib.o fwlib.cpp -D DLL_EXPORT
	@g++ -o fwlib.dll fwlib.o -shared -Wl
	@rm -f *.o

clean:
	@rm -f *dylib *dll *so
