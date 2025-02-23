#include "../libs/clap/include/clap/clap.h"

static bool entry_init(const char *plugin_path) { return true; }

static void entry_deinit(void) {}

static uint32_t
plugin_factory_get_plugin_count(const clap_plugin_factory_t *factory) {
  return 1;
}

static const clap_plugin_descriptor_t desc = {
    .id = "me.tphbrok.plugin",
    .name = "Plugin",
    .features = (const char *[]){NULL},
};

static const clap_plugin_descriptor_t *
get_plugin_descriptor(const struct clap_plugin_factory *factory,
                      uint32_t index) {
  return &desc;
}

static bool plugin_init(const struct clap_plugin *plugin) { return true; }

static void plugin_destroy(const struct clap_plugin *plugin) {}

static bool plugin_activate(const struct clap_plugin *plugin,
                            double sample_rate, uint32_t min_frames_count,
                            uint32_t max_frames_count) {
  return true;
}

static void plugin_deactivate(const struct clap_plugin *plugin) {}

clap_plugin_t plugin = {
    .desc = &desc,
    .init = plugin_init,
    .destroy = plugin_destroy,
    .activate = plugin_activate,
    .deactivate = plugin_deactivate,
};

static const clap_plugin_t *
create_plugin(const struct clap_plugin_factory *factory,
              const clap_host_t *host, const char *plugin_id) {
  return &plugin;
}

static const clap_plugin_factory_t factory = {
    .get_plugin_count = plugin_factory_get_plugin_count,
    .get_plugin_descriptor = get_plugin_descriptor,
    .create_plugin = create_plugin,
};

static const void *entry_get_factory(const char *factory_id) {
  return &factory;
}

CLAP_EXPORT const clap_plugin_entry_t clap_entry = {
    .clap_version = CLAP_VERSION_INIT,
    .init = entry_init,
    .deinit = entry_deinit,
    .get_factory = entry_get_factory};
