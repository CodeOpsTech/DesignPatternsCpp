/* DO NOT EDIT THIS FILE - it is machine generated */
/* Server_0005fDiscovery_0005fUtil.h,v 1.3 1998/11/03 19:53:59 yamuna Exp */
#include <jni.h>
/* Header for class Server_0005fDiscovery_0005fUtil */

#ifndef _Included_Server_0005fDiscovery_0005fUtil
#define _Included_Server_0005fDiscovery_0005fUtil
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Server_0005fDiscovery_0005fUtil
 * Method:    evaluate_performance_property
 * Signature: (Ljava/lang/String;Ljava/lang/String;)F
 */
JNIEXPORT jfloat JNICALL Java_Server_1Discovery_1Util_evaluate_1performance_1property
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     Server_0005fDiscovery_0005fUtil
 * Method:    get_movie_info
 * Signature: (Ljava/lang/String;)[LTAO_VR/Movie;
 */
JNIEXPORT jobjectArray JNICALL Java_Server_1Discovery_1Util_get_1movie_1info
  (JNIEnv *, jclass, jstring);

/*
 * Class:     Server_0005fDiscovery_0005fUtil
 * Method:    get_servers
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_Server_1Discovery_1Util_get_1servers
  (JNIEnv *, jclass);

/*
 * Class:     Server_0005fDiscovery_0005fUtil
 * Method:    load_movie
 * Signature: (Ljava/lang/String;LTAO_VR/Movie;)V
 */
JNIEXPORT void JNICALL Java_Server_1Discovery_1Util_load_1movie
  (JNIEnv *, jclass, jstring, jobject);

/*
 * Class:     Server_0005fDiscovery_0005fUtil
 * Method:    query_trader
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_Server_1Discovery_1Util_query_1trader
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif