#include "log.h"
#include <json-c/json.h>
#include <stdio.h>
#include <time.h>

static void log_message(const char *level, const char *message)
{
	struct json_object *jobj = json_object_new_object();
	struct json_object *jlevel = json_object_new_string(level);
	struct json_object *jmessage = json_object_new_string(message);
	struct json_object *jtimestamp = json_object_new_int64(time(NULL));

	json_object_object_add(jobj, "timestamp", jtimestamp);
	json_object_object_add(jobj, "level", jlevel);
	json_object_object_add(jobj, "message", jmessage);

	fprintf(stderr, "%s\n",
		json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PLAIN));

	json_object_put(jobj); // Free memory
}

void info(const char *message)
{
	log_message("INFO", message);
}

void error(const char *message)
{
	log_message("ERROR", message);
}
