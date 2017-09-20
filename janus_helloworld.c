#include <plugins/plugin.h>
#include <debug.h>

#define JANUS_HELLOWORLD_VERSION 1
#define JANUS_HELLOWORLD_VERSION_STRING	"0.0.1"
#define JANUS_HELLOWORLD_DESCRIPTION "The simplest possible Janus plugin."
#define JANUS_HELLOWORLD_NAME "JANUS hello world plugin"
#define JANUS_HELLOWORLD_AUTHOR	"Marshall Quander"
#define JANUS_HELLOWORLD_PACKAGE "janus.plugin.helloworld"

janus_plugin *create(void);
int janus_helloworld_init(janus_callbacks *callback, const char *config_path);
void janus_helloworld_destroy(void);
int janus_helloworld_get_api_compatibility(void);
int janus_helloworld_get_version(void);
const char *janus_helloworld_get_version_string(void);
const char *janus_helloworld_get_description(void);
const char *janus_helloworld_get_name(void);
const char *janus_helloworld_get_author(void);
const char *janus_helloworld_get_package(void);
void janus_helloworld_create_session(janus_plugin_session *handle, int *error);
struct janus_plugin_result *janus_helloworld_handle_message(janus_plugin_session *handle, char *transaction, json_t *message, json_t *jsep);
void janus_helloworld_setup_media(janus_plugin_session *handle);
void janus_helloworld_incoming_rtp(janus_plugin_session *handle, int video, char *buf, int len);
void janus_helloworld_incoming_rtcp(janus_plugin_session *handle, int video, char *buf, int len);
void janus_helloworld_incoming_data(janus_plugin_session *handle, char *buf, int len);
void janus_helloworld_slow_link(janus_plugin_session *handle, int uplink, int video);
void janus_helloworld_hangup_media(janus_plugin_session *handle);
void janus_helloworld_destroy_session(janus_plugin_session *handle, int *error);
json_t *janus_helloworld_query_session(janus_plugin_session *handle);

static janus_plugin janus_helloworld_plugin =
	JANUS_PLUGIN_INIT (
		.init = janus_helloworld_init,
		.destroy = janus_helloworld_destroy,

		.get_api_compatibility = janus_helloworld_get_api_compatibility,
		.get_version = janus_helloworld_get_version,
		.get_version_string = janus_helloworld_get_version_string,
		.get_description = janus_helloworld_get_description,
		.get_name = janus_helloworld_get_name,
		.get_author = janus_helloworld_get_author,
		.get_package = janus_helloworld_get_package,

		.create_session = janus_helloworld_create_session,
		.handle_message = janus_helloworld_handle_message,
		.setup_media = janus_helloworld_setup_media,
		.incoming_rtp = janus_helloworld_incoming_rtp,
		.incoming_rtcp = janus_helloworld_incoming_rtcp,
		.incoming_data = janus_helloworld_incoming_data,
		.slow_link = janus_helloworld_slow_link,
		.hangup_media = janus_helloworld_hangup_media,
		.destroy_session = janus_helloworld_destroy_session,
		.query_session = janus_helloworld_query_session,
	);

janus_plugin *create(void) {
	JANUS_LOG(LOG_VERB, "%s created!\n", JANUS_HELLOWORLD_NAME);
	return &janus_helloworld_plugin;
}

int janus_helloworld_init(janus_callbacks *callback, const char *config_path) {
	JANUS_LOG(LOG_INFO, "%s initialized!\n", JANUS_HELLOWORLD_NAME);
	return 0;
}


void janus_helloworld_destroy(void) {
	JANUS_LOG(LOG_INFO, "%s destroyed!\n", JANUS_HELLOWORLD_NAME);
}

int janus_helloworld_get_api_compatibility(void) {
	return JANUS_PLUGIN_API_VERSION;
}

int janus_helloworld_get_version(void) {
	return JANUS_HELLOWORLD_VERSION;
}

const char *janus_helloworld_get_version_string(void) {
	return JANUS_HELLOWORLD_VERSION_STRING;
}

const char *janus_helloworld_get_description(void) {
	return JANUS_HELLOWORLD_DESCRIPTION;
}

const char *janus_helloworld_get_name(void) {
	return JANUS_HELLOWORLD_NAME;
}

const char *janus_helloworld_get_author(void) {
	return JANUS_HELLOWORLD_AUTHOR;
}

const char *janus_helloworld_get_package(void) {
	return JANUS_HELLOWORLD_PACKAGE;
}


void janus_helloworld_create_session(janus_plugin_session *handle, int *error) {
	JANUS_LOG(LOG_INFO, "Session created.\n");
}

void janus_helloworld_destroy_session(janus_plugin_session *handle, int *error) {
	JANUS_LOG(LOG_INFO, "Session destroyed.\n");
}

json_t *janus_helloworld_query_session(janus_plugin_session *handle) {
	return json_object();
}

struct janus_plugin_result *janus_helloworld_handle_message(janus_plugin_session *handle, char *transaction, json_t *message, json_t *jsep) {
	return janus_plugin_result_new(JANUS_PLUGIN_OK, NULL, json_object());
}

void janus_helloworld_setup_media(janus_plugin_session *handle) {
	JANUS_LOG(LOG_INFO, "WebRTC media is now available.\n");
}

void janus_helloworld_incoming_rtp(janus_plugin_session *handle, int video, char *buf, int len) {
	JANUS_LOG(LOG_VERB, "Got an RTP message (%d bytes.)\n", len);
}

void janus_helloworld_incoming_rtcp(janus_plugin_session *handle, int video, char *buf, int len) {
	JANUS_LOG(LOG_VERB, "Got an RTCP message (%d bytes.)\n", len);
}

void janus_helloworld_incoming_data(janus_plugin_session *handle, char *buf, int len) {
	JANUS_LOG(LOG_VERB, "Got a DataChannel message (%d bytes.)\n", len);
}

void janus_helloworld_slow_link(janus_plugin_session *handle, int uplink, int video) {
	JANUS_LOG(LOG_VERB, "Slow link detected.\n");
}

void janus_helloworld_hangup_media(janus_plugin_session *handle) {
	JANUS_LOG(LOG_INFO, "No WebRTC media anymore.\n");
}
