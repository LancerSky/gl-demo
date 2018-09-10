#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gl/gjson.h>

/**demo_hello
 * @api {GET} /demo/hello /demo/hello
 * @apiGroup demo
 * @apiVersion 0.0.1
 * @apiDescription Demo for comment
 * @apiParam {String} msg Show message
 * @apiParamExample {json} Request
 *                $ curl --cookie "QSESSIONID=9177564b1203c30000" 192.168.8.1/api/demo/hello
 * @apiSuccess (200) {int} code 0 is success and occur error when code < 0. <a href="#api-ErrorCode-DescriptionCode">Detailed...</a>
 * @apiSuccess (200) {int} -1 Invalid user, permission denied or not logged in!
 * @apiSuccess (200) {int} -4 Invalid parameter, value or format!
 * @apiSuccess (200) {int} -5 No parameter found!
 * @apiSuccessExample {json} Response
 *                {"code":0,"msg":"Hello World","http_cookie":"QSESSIONID=9177564b1203c30000"}
 */
int demo_hello(json_object* input, json_object* output)
{
	gjson_add_string(output, "msg", "Hello World");
	return 0;
}


/** The implementation of the GetAPIFunctions function **/
#include <gl/glapibase.h>

static api_info_t gl_lstCgiApiFuctionInfo[] = {
		map("/demo/hello", "get", demo_hello),
};

api_info_t* get_api_entity(int* pLen)
{
	(*pLen) = sizeof(gl_lstCgiApiFuctionInfo) / sizeof(gl_lstCgiApiFuctionInfo[0]);
	return gl_lstCgiApiFuctionInfo;
}

