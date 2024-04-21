#include <microhttpd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8888

static MHD_Result handle_request(void *cls, struct MHD_Connection *connection,
				 const char *url, const char *method,
				 const char *version, const char *upload_data,
				 size_t *upload_data_size, void **con_cls)
{
	const char *page = "<html><body>Hello World!</body></html>";
	struct MHD_Response *response;
	int ret;

	response = MHD_create_response_from_buffer(strlen(page), (void *)page,
						   MHD_RESPMEM_PERSISTENT);
	ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
	MHD_destroy_response(response);

	return ret ? MHD_YES : MHD_NO;
}

int main()
{
	struct MHD_Daemon *daemon;
	daemon = MHD_start_daemon(MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL,
				  NULL, &handle_request, NULL, MHD_OPTION_END);
	if (daemon == NULL) {
		fprintf(stderr, "Failed to start the server\n");
		return EXIT_FAILURE;
	}
	printf("Server running on port %d\n", PORT);
	getchar(); // Press Enter to terminate the server

	MHD_stop_daemon(daemon);
	printf("Server has been stopped\n");
	return EXIT_SUCCESS;
}