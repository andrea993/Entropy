build:
	g++ -O2 -o entropy entropy.cpp
install:
	cp -f entropy /usr/bin/entropy
	chmod +x /usr/bin/entropy
uninstall:
	rm -f /usr/bin/entropy
clean:
	rm -f entropy

