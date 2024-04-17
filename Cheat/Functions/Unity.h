#include "../../Utils/Utils.h"

typedef struct _monoString {
    void *klass;
    void *monitor;
    int length;
    char chars[1];

    int getLength() { return length; }

    std::string getChars() { return std::string(chars, length * 2); }
} MonoString;

struct AnalyticsParams {
    int enum1;
    int enum2;
    int enum3;
    int enum4;
    int enum5;
    int enum6;
    int enum7;
    bool boolean1;
    void *klass1;
    int enum8;
    bool bool2;
    int enum9;
    void *klass2;
    bool boolean3;
    int enum10;
    int integer1;
};