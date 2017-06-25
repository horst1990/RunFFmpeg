#include <jni.h>
#include <string>
#include "libavcodec/avcodec.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hor_runffmpeg_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    char info[10000] = {0};
    sprintf(info, "%s\n", avcodec_configuration());

    return env->NewStringUTF(info);
}