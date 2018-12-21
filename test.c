#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 1024

int checksum(const char *s) {
	int c = 0;
	
	while(*s)
		c ^= *s++;
	return c;
}

int main(void)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen("test.txt","r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, stream)) != -1) {
		printf("%s",line);
		char* token = strtok(line,",");
		while (token != NULL) {
			if (strcmp(token,"$HEHDT") == 0) printf ("HE Heading - North Seeking Gyro\n");
			if (strcmp(token,"$GPHDT") == 0) printf ("GP Global positioning\n");
			if (strcmp(token,"$HNHDT") == 0) printf ("HN Heading - Non North Gyro\n");
			if (strcmp(token,"$IIHDT") == 0) printf ("II Intergrated Instrumentation\n");
			if (strcmp(token,"$HCHDT") == 0) printf ("HC Heading - Magnetic Compass\n");
	//		printf("%s\n",token);
			token = strtok(NULL, ",");
	}

//		printf("%s",line);
	}

	free(line);
	fclose(stream);


}
