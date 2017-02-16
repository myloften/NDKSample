#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "LogUtils.h"


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

    LOGW("this is a warning");
    LOGE("i=%d",5);
    srand(time(0));
    jint * rs = new jint[size];
    for (int i = 0; i < size; ++i) {
        rs[i] = random(100);
    }
    jintArray array = env->NewIntArray(size);
    env->SetIntArrayRegion(array,0,size,rs);
    return array;
}


JNIEXPORT void JNICALL
Java_com_loften_ndksample_JniTest_sortIntArray(JNIEnv *env, jclass type, jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);

    int size = env->GetArrayLength(array_);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-1-i; ++j) {
            if(array[j]>array[j+1]){
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }

    env->ReleaseIntArrayElements(array_, array, 0);
}

JNIEXPORT jobject JNICALL
Java_com_loften_ndksample_JniTest_creatBean(JNIEnv *env, jobject type, jstring msg_, jint what) {

    jclass bean_clz = env->FindClass("com/loften/ndksample/Bean");
    if(bean_clz==NULL){
        LOGE("can't find class");
        return NULL;
    }

    jmethodID bean_init = env->GetMethodID(bean_clz,"<init>","(Ljava/lang/String;I)V");
    if(bean_init==NULL){
        LOGE("can't find init function");
        return NULL;
    }

    jobject bean = env->NewObject(bean_clz,bean_init,msg_,what);
    return bean;

}

JNIEXPORT jstring JNICALL
Java_com_loften_ndksample_JniTest_getBeanString(JNIEnv *env, jobject instance, jobject bean) {

    jclass bean_clz = env->FindClass("com/loften/ndksample/Bean");

    jmethodID bean_getmsg = env->GetMethodID(bean_clz,"getMsg","()Ljava/lang/String;");
    jmethodID bean_getwhat = env->GetMethodID(bean_clz,"getWhat","()I");
    jstring _msg = (jstring) env->CallObjectMethod(bean, bean_getmsg);
    jint _what = env->CallIntMethod(bean, bean_getwhat);

    /*jfieldID msg_id = env->GetFieldID(bean_clz,"msg","Ljava/lang/String;");
    jfieldID what_id = env->GetFieldID(bean_clz,"what","I");
    jstring _msg = (jstring)env->GetObjectField(bean,msg_id);
    jint _what = env->GetIntField(bean,what_id);*/

    const char *msg = env->GetStringUTFChars(_msg,NULL);
    char *str = new char[1024];
    sprintf(str,"Msg:%s;What:%d(From C++)",msg,_what);
    jstring rs = env->NewStringUTF(str);
    delete []str;
    env->ReleaseStringUTFChars(_msg,msg);

    return rs;
}


JNIEXPORT void JNICALL
Java_com_loften_ndksample_JniTest_ModifyBean(JNIEnv *env, jobject instance, jobject bean) {
    jclass bean_clz = env->FindClass("com/loften/ndksample/Bean");

    jfieldID bean_msg = env->GetFieldID(bean_clz,"msg","Ljava/lang/String;");
    jfieldID bean_what = env->GetFieldID(bean_clz,"what","I");

    jstring modify = env->NewStringUTF("modify a bean");

    env->SetObjectField(bean,bean_msg,modify);
    env->SetIntField(bean,bean_what,2);

    return;

}

}