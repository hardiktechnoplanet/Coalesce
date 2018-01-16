coalesce.exe: coalesce.cpp
		g++ coalesce.cpp -o coalesce.exe

clean:
		rm *.o coalesce.exe
