#include <jni.h>
#include <string>

#include <vector>
#include <unordered_map>
#include "Eigen/Eigen/Dense"
#include "boost/thread.hpp"
#include "opencv2/core.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_a_b_iawithpowell_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    char res[100];

    Eigen::MatrixXd M(2,2) ;
    Eigen::MatrixXd V(2,2) ;
    M(0,0)=2;
    M(0,1)=1;
    M(1,0)=3.5;
    M(1,1)=-1;

    V(0,0)=1.2;
    V(0,1)=0;

    V(1,0)=0;
    V(1,1)=1.2;



    Eigen::MatrixXd Result = M*V;
    sprintf(res, "M:  %f,  %f \n      %f, %f", Result(0,0), Result(0,1), Result(1,0), Result(1,1));



    //std::string hello = "Hello from C++";
    //return env->NewStringUTF(hello.c_str());
    return env->NewStringUTF(res);
}
