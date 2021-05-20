#include <jni.h>
#include <string>

extern "C" {
#include "sparse/cs.h"
}


using namespace std;








extern "C"
JNIEXPORT jstring JNICALL
Java_com_vaca_sparse_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from C++";
    cs *T;
    cs *A;
    double tol = 1e-14;
    int order=1;


    T = cs_spalloc(0,0,1,1,1);
    cs_entry(T, 1,1,0.61);
    cs_entry(T, 0,0,0.31);
    double b[2]={0.3,0.7};
    A=cs_compress(T);
    cs_lusol(order,A,b,tol);

    hello+=to_string(b[0]);

    hello+="  ";
    hello+=to_string(b[1]);



    return env->NewStringUTF(hello.c_str());
}