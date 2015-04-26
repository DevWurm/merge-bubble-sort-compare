all:
	g++ compare.cpp liberror/liberror.a -std=c++11 -pthread -o ./compare

run:
	g++ compare.cpp liberror/liberror.a -std=c++11 -pthread -o ./builds/run/compare

debug:
	g++ compare.cpp liberror/liberror.a -std=c++11 -pthread -g -o ./builds/debug/compare
