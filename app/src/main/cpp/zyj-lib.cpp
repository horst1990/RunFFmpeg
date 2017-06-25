//
// Created by Administrator on 2017/6/24.
//
#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hor_runffmpeg_MainActivity_string2FromJNI(JNIEnv *env, jobject instance) {
    std::string hello = "Hello from C++ 22";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hor_runffmpeg_MainActivity_string3FromJNI(JNIEnv *env, jobject instance) {
    std::string hello = "Hello from C++ 2244";
    return env->NewStringUTF(hello.c_str());
}