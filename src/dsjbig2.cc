#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <io.h>
#include <string.h>

#include "com_docshifter_modules_hifi_jbig2_Jbig2Library.h"

#include "jbig2.h"

JNIEXPORT jint JNICALL Java_com_docshifter_modules_hifi_jbig2_Jbig2Library_encodeImage
(JNIEnv* env, jclass obj, jobjectArray arrayFromJava) {

    jsize arraySize = env->GetArrayLength(arrayFromJava);

    char** parametersList = (char**)malloc(arraySize * sizeof(char*));

    if (parametersList == NULL) {
        return 1;
    }

    for (int index = 0; index < arraySize; index++) {

        // Getting the String from array
        jstring arrayElement = (jstring)(env->GetObjectArrayElement(arrayFromJava, index));

        // Converting to a pointer to first char
        const char* nativeElement = env->GetStringUTFChars(arrayElement, NULL);

        // Allocate memory for the string
        parametersList[index] = (char*)malloc((strlen(nativeElement) + 1) * sizeof(char)); // 50 is an arbitrary maximum string length

        // Check if memory allocation was successful
        if (parametersList[index] == NULL) {
            return 1;
        }

        // Copy a string into the allocated memory
        sprintf(parametersList[index], nativeElement);

        // free string
        env -> ReleaseStringUTFChars(arrayElement, nativeElement);
    }

    int response = encode_image(arraySize, parametersList);

    // Free memory allocated for each individual string
    for (int index = 0; index < arraySize; index++) {
        free(parametersList[index]);
    }

    // Free memory allocated for the array of pointers
    free(parametersList);

    return response;
}