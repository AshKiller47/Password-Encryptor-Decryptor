all: build execute

build:
	g++ -std=c++17 -o bin\password_encryptor_decryptor password_encryptor_decryptor.cpp

execute:
	bin\password_encryptor_decryptor

clean:
	del bin\password_encryptor_decryptor.exe