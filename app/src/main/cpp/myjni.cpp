#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

extern "C" {
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

#define random(x) (rand()%x)
JNIEXPORT jintArray JNICALL
Java_com_loften_ndksample_JniTest_getIntArray(JNIEnv *env, jclass type, jint size) {

    srand(time(0));
    jint * rs = new jint[size];
    for (int i = 0; i < size; ++i) {
        rs[i] = random(100);
    }
    jintArray array = env->NewIntArray(size);
    env->SetIntArrayRegion(array,0,size,rs);
    return array;
}

}