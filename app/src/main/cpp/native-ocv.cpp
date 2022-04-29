#include <jni.h>
#include <android/log.h>
#include <opencv2/core/core.hpp>
#include <cstring>

#define TAG "native-ocv"
// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("usbcamera");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("usbcamera")
//      }
//    }
extern "C" {
void JNICALL
Java_com_jiangdg_usbcamera_view_USBCameraActivity_numLog(JNIEnv *env, jobject instance,
                                                         int number) {
    __android_log_print(ANDROID_LOG_INFO, TAG, "the number is %d", number);
}

JNIEXPORT jlong JNICALL
Java_com_jiangdg_usbcamera_view_USBCameraActivity_numreturn(JNIEnv *env, jobject instance,
                                                            int number) {
    return number * number;
}
void JNICALL
Java_com_serenegiant_usb_common_AbstractUVCCameraHandler_numlog(JNIEnv *env, jclass instance,
                                                                int number) {
    __android_log_print(ANDROID_LOG_INFO, TAG, "the number is %d", number);

}
}
extern "C" {
//JNIEXPORT void JNICALL
JNIEXPORT void JNICALL
Java_com_serenegiant_usb_common_AbstractUVCCameraHandler_spoilBuffer(JNIEnv *env, jclass instance,
                                                                     jbyteArray array) {
    __android_log_print(ANDROID_LOG_INFO, TAG, "fdw: AbstractUVCCameraHandler.spoilBuffer");

    uint8_t *buffer = reinterpret_cast<uint8_t *>(env->GetByteArrayElements(array, 0));
    jsize size = env->GetArrayLength(array);

    //__android_log_print(ANDROID_LOG_DEBUG, TAG, "fdw: first element of array %d; buffer %d",array[1], buffer[1]);

    void *cbuf = malloc(size);
    //memcpy(cbuf,, size);
    memset(cbuf, 0, 450000);
    //if (cbuf != NULL)
    //{
    //    env->ReleaseByteArrayElements(array, cbuf, JNI_COMMIT);
    //}
}
JNIEXPORT void JNICALL
Java_com_jiangdg_usbcamera_view_USBCameraActivity_spoilBuffer(JNIEnv *env, jobject instance, jbyteArray array, jint arrlen)
{
    //__android_log_print(ANDROID_LOG_INFO, TAG, "funcname %d", __func__ );
    __android_log_print(ANDROID_LOG_INFO,TAG, "spoilBuffer arrlength %d",arrlen);
    jbyte *buffer = env->GetByteArrayElements(array, 0);
    memset(buffer, 0, arrlen);
    if (buffer != NULL)
    {
        env->ReleaseByteArrayElements(array, buffer, JNI_COMMIT);
    }

}
JNIEXPORT void JNICALL
Java_com_serenegiant_usb_widget_UVCCameraTextureView_spoilBuffer(JNIEnv *env, jobject instance, jbyteArray array)
{

    //int henktwee = 5/0;
    jbyte *buffer = env->GetByteArrayElements(array, 0);
    //memset(buffer, 0, 400000000);
    for(int i = 0; i <20000; i++)
    {
        buffer[i] = 0;
    }
    if (buffer != NULL)
    {
    env->ReleaseByteArrayElements(array, buffer, JNI_COMMIT);
    }
}
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_serenegiant_usb_UVCCamera_spoilSurface(JNIEnv *env, jobject thiz, jobject tex) {

    return tex;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_jiangdg_usbcamera_view_USBCameraActivity_spoilSurface(JNIEnv *env, jobject thiz, jobject tex, jint width, jint height)
{
    char hw[12] ="helloworld";
    return reinterpret_cast<jstring>(hw);
}