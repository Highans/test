#include <crc32.h>

uint64_t fsize(FILE *file){
	uint64_t pos = ftell(file);
	uint64_t size;
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, pos, SEEK_SET);
	return size;
}

#define BUFFSIZE 1024
uint32_t fcrc32(FILE *file){
	uint32_t crc = 0;
	int buff[BUFFSIZE];
	int read;
	while((read = fread(buff, 1, sizeof(buff), file))){
		crc = crc32(crc, (const Bytef*)buff, read);
	}
	return crc;
}

#ifdef CRC32TOOL_STANDALONE
int main(int argc, char **argv){
	if(argc >= 2){
		FILE *fp = fopen(argv[1], "rb");
		if(!fp){
			printf("%.8X\t%10.u\t%s\n", 0, argv[1]);
			return 0;
		}
		printf("%.8X\t%10.u\t%s\n", fcrc32(fp), (unsigned int)fsize(fp), argv[1]);

		fclose(fp);
	}
}
#endif
