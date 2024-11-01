// Программа состоит из двух модулей:
// hello_main.c - главный модуль, компилируется в hello_main.o:
//      gcc -c hello_main.c
// hello_func.S - модуль с функцией hello_func(), компилируется в hello_func.o:
//      nasm -felf64 hello_func.S
// После чего выполняется сборка исполняемого файла:
//      gcc -static -o hello_func hello_main.o hello_func.o

void hello_func();

int main() {
	hello_func();
	return 0;
}
