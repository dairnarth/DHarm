#include <stdlib.h>
#include <stddef.h>
#include <lv2.h>

typedef struct {
    float *in;
    float *out;
} DHarm;

static LV2_Handle instantiate(const struct LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features) {
    return (DHarm *)calloc(1, sizeof(DHarm));
}

static void connect_port(LV2_Handle instance, uint32_t port, void *data_location) {
    DHarm *d = (DHarm *)instance;
    if (!d) return;

    switch (port) {
        case 0:
            d->in = (float *)data_location;
            break;

        case 1:
            d->out = (float *)data_location;
            break;

        default:
            break;
    }
}

static void activate(LV2_Handle instance) {}

static void run(LV2_Handle instance, uint32_t sample_count) {
    DHarm *d = (DHarm *)instance;
    if (!d) return;
    if ((!d->in) || (!d->out)) return;

    for (uint32_t i = 0; i < sample_count; i++) {}
}

static void deactivate(LV2_Handle instance) {}

static void cleanup(LV2_Handle instance) {
    DHarm *d = (DHarm *)instance;
    if (!d) return;
    free(d);
}

static const void *extension_data(const char *uri) {
    return NULL;
}

static LV2_Descriptor const descriptor = {
    "https://github.com/dairnarth/dharm",
    instantiate,
    connect_port,
    activate,
    run,
    deactivate,
    cleanup,
    extension_data
};

const LV2_SYMBOL_EXPORT LV2_Descriptor *lv2_descriptor(uint32_t index) {
    if (index == 0) return &descriptor;
    else return NULL;
}
