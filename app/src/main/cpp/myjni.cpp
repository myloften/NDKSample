#include <jni.h>
#include <string.h>

extern "C"{
JNIEXPORT jstring JNICALL
Java_com_loften_ndksample_JniTest_combine(JNIEnv *env, jclass type, jstring a_, jstring b_) {
    const char *a = env->GetStringUTFChars(a_, 0);
    const char *b = env->GetStringUTFChars(b_, 0);

    int size = strlen(a) + strlen(b);

    char * n_char = new char[size];
    strcpy(n_char,a);
    strcat(n_char,b);

    jstring returnValue = env->NewStringUTF(n_char);

    delete [] n_char;

    env->ReleaseStringUTFChars(a_, a);
    env->ReleaseStringUTFChars(b_, b);

    return returnValue;
}

}