all:
	g++ -fpermissive -Wall GPIOclient.cpp -o build/client
	g++ -fpermissive -Wall GPIOClass.cpp GPIOserver.cpp -o build/server

v2:
	g++ -fpermissive -Wall GPIOClass.cpp GPIOon.cpp -o build/gpion
	g++ -fpermissive -Wall GPIOClass.cpp GPIOoff.cpp -o build/gpioff

lib:
	g++ -fpermissive -fPIC -shared GPIOClass.cpp -o libshared.so
	g++ -L. -lshared -o build/server GPIOserver.cpp
