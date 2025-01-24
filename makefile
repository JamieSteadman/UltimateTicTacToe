main: main.c interface.c win_logic.c algorithms.c help.c game_logic.c functions.h
	gcc -o main main.c interface.c win_logic.c algorithms.c help.c game_logic.c `pkg-config --cflags --libs gtk+-3.0`

ctest: main.c interface.c win_logic.c algorithms.c help.c game_logic.c functions.h
	gcc -o ctest --coverage main.c interface.c win_logic.c algorithms.c help.c game_logic.c `pkg-config --cflags --libs gtk+-3.0`
	
testing: testing.c interface.c win_logic.c algorithms.c help.c game_logic.c functions.h
	gcc -o testing testing.c interface.c win_logic.c algorithms.c help.c game_logic.c `pkg-config --cflags --libs gtk+-3.0`
