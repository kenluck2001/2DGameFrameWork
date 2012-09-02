CFLAGS=-I/usr/include/SDL -I./DemoEngine `sdl-config --static-libs`
LIBS=-L/usr/lib -lSDL_ttf -lSDL_gfx -lSDL_image -lSDL_mixer -lSDL -Wl,-rpath,/usr/local/lib,-Bstatic -lpng -lz -lstdc++ -Wl,-Bdynamic -lGL -lX11 -lXext -ldl -lpthread -lrt 
all: engine
	g++ -O0 -g $(CFLAGS) main.cpp *.o $(LIBS) && mv *.o Debug/

engine:
	g++ -c $(CFLAGS) DemoEngine/*.cpp Game/*.cpp


.PHONY: clean

release: engine
	g++ -w -O2 $(CFLAGS) main.cpp *.o $(LIBS) && mv *.o Release/ && mv a.out Application/

clean:
	rm -rf Release/*.o Application/a.out Debug/*.o Debug/a.out *.o *.h.gch DemoEngine/*.h.gch Game/*.h.gch *~ Application/*~ Debug/*~ DemoEngine/*~ Game/*~ Release/*~ fonts/*~ pics/*~ sound/*~

exec:
	./a.out

appexec:
	./Application/a.out


