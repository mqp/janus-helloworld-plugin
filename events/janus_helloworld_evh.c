#include <jansson.h>
#include <events/eventhandler.h>
#include <debug.h>

#define JANUS_HELLOWORLD_EVH_VERSION 1
#define JANUS_HELLOWORLD_EVH_VERSION_STRING "0.0.1"
#define JANUS_HELLOWORLD_EVH_DESCRIPTION "The simplest possible Janus event handler."
#define JANUS_HELLOWORLD_EVH_NAME "JANUS hello world event handler"
#define JANUS_HELLOWORLD_EVH_AUTHOR	"Marshall Quander"
#define JANUS_HELLOWORLD_EVH_PACKAGE "janus.eventhandler.helloworld_evh"

janus_eventhandler *create(void);
int janus_helloworld_evh_init(const char *config_path);
void janus_helloworld_evh_destroy(void);
int janus_helloworld_evh_get_api_compatibility(void);
int janus_helloworld_evh_get_version(void);
const char *janus_helloworld_evh_get_version_string(void);
const char *janus_helloworld_evh_get_description(void);
const char *janus_helloworld_evh_get_name(void);
const char *janus_helloworld_evh_get_author(void);
const char *janus_helloworld_evh_get_package(void);
void janus_helloworld_evh_incoming_event(json_t *event);

static janus_eventhandler janus_helloworld_evh =
  JANUS_EVENTHANDLER_INIT(.init = janus_helloworld_evh_init,
                          .destroy = janus_helloworld_evh_destroy,
                          .get_api_compatibility = janus_helloworld_evh_get_api_compatibility,
                          .get_version = janus_helloworld_evh_get_version,
                          .get_version_string = janus_helloworld_evh_get_version_string,
                          .get_description = janus_helloworld_evh_get_description,
                          .get_name = janus_helloworld_evh_get_name,
                          .get_author = janus_helloworld_evh_get_author,
                          .get_package = janus_helloworld_evh_get_package,
                          .incoming_event = janus_helloworld_evh_incoming_event,
                          .events_mask = JANUS_EVENT_TYPE_ALL
                          );

janus_eventhandler *create(void) {
  JANUS_LOG(LOG_VERB, "%s created!\n", JANUS_HELLOWORLD_EVH_NAME);
  return &janus_helloworld_evh;
}

int janus_helloworld_evh_init(const char *config_path) {
  JANUS_LOG(LOG_INFO, "%s initialized!\n", JANUS_HELLOWORLD_EVH_NAME);
  return 0;
}

void janus_helloworld_evh_destroy(void) {
  JANUS_LOG(LOG_INFO, "%s destroyed!\n", JANUS_HELLOWORLD_EVH_NAME);
}

int janus_helloworld_evh_get_api_compatibility(void) {
  return JANUS_EVENTHANDLER_API_VERSION;
}

int janus_helloworld_evh_get_version(void) {
  return JANUS_HELLOWORLD_EVH_VERSION;
}

const char *janus_helloworld_evh_get_version_string(void) {
  return JANUS_HELLOWORLD_EVH_VERSION_STRING;
}

const char *janus_helloworld_evh_get_description(void) {
  return JANUS_HELLOWORLD_EVH_DESCRIPTION;
}

const char *janus_helloworld_evh_get_name(void) {
  return JANUS_HELLOWORLD_EVH_NAME;
}

const char *janus_helloworld_evh_get_author(void) {
  return JANUS_HELLOWORLD_EVH_AUTHOR;
}

const char *janus_helloworld_evh_get_package(void) {
  return JANUS_HELLOWORLD_EVH_PACKAGE;
}

void janus_helloworld_evh_incoming_event(json_t *event) {
  int type = json_integer_value(json_object_get(event, "type"));
  JANUS_LOG(LOG_VERB, "Got an event: type %d.\n", type);
}
