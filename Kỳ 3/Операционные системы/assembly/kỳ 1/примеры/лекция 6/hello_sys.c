#include <unistd.h>

int main() {
	char *str_ptr = "Hello, world!\n";
	write(1, str_ptr, 14);
	
	return 0;
}
