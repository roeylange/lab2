menu_map: menu_map.c
	gcc -g -m32  -c -o menu_map.o menu_map.c
	gcc -g -m32 menu_map.o -o menu_map
	rm menu_map.o

.PHONY: clean
clean:
	rm -rf ./*.o menu_map
