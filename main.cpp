
#include <jni.h>
#include <android/log.h>
#include <cstdint>
#include <cstring>

#define TAG "skidddder"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

struct Button { const char* label; const char* mod; float value; };
struct Page   { const char* name; const Button* buttons; int count; };

static constexpr const char* kName   = "skidddder";
static constexpr const char* kAuthor = "me dick";

static constexpr Button kMain[] = {
    {"Platforms",   "platforms",   0.0f},
    {"Fly (A)",     "fly",         12.0f},
    {"Speed Boost", "speed_boost", 1.3f},
    {"Long Arms",   "long_arms",   1.2f},
    {"Low Gravity", "low_gravity", 0.5f},
};
static constexpr Button kSettings[] = {
    {"Drop Menu",   "drop_menu",   0.0f},
    {"Disconnect",  "disconnect",  0.0f},
    {"Reload Menu", "reload_menu", 0.0f},
    {"Close Menu",  "close_menu",  0.0f},
};
static constexpr Page kPages[] = {
    {"Main",     kMain,     (int)(sizeof(kMain) / sizeof(Button))},
    {"Settings", kSettings, (int)(sizeof(kSettings) / sizeof(Button))},
};

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM*, void*) {
    LOGI("%s by %s", kName, kAuthor);
    for (const Page& p : kPages)
        for (int i = 0; i < p.count; ++i)
            LOGI("[%s] %s -> %s (%.2f)", p.name, p.buttons[i].label, p.buttons[i].mod, p.buttons[i].value);
    return JNI_VERSION_1_6;
}
