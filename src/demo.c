#include "demo.h"


int demo_hello(json_object* input, json_object* output)
{
	json_object_object_add(output, "msg", json_object_new_string("Hello World"));
	return 0;
}


/** The implementation of the GetAPIFunctions function **/
#include "glapibase.h"

static api_info_t gl_lstCgiApiFuctionInfo[] = {
		map("/demo/hello", "get", demo_hello),
};

api_info_t* get_api_entity(int* pLen)
{
	(*pLen) = sizeof(gl_lstCgiApiFuctionInfo) / sizeof(gl_lstCgiApiFuctionInfo[0]);
	return gl_lstCgiApiFuctionInfo;
}

