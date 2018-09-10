#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gl/gjson.h>
#include "demo.h"

int main(int argc , char *argv[])
{
	json_object* input = json_object_new_object();
	json_object* output = json_object_new_object();
	
	demo_hello(input, output);
	
	printf("result:\n%s\n", json_object_to_json_string(output));
	
	json_object_put(input);
	json_object_put(output);
	
	return 0;
}
