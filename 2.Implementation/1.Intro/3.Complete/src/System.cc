

#include "System.h"

#include <string>

using namespace std;


namespace ORB_SLAM3
{
System::System(const string &strVocFile, const string &strSettingsFile, const eSensor sensor,
               const bool bUseViewer, const int initFr, const string &strSequence){
                printf("Call constructor: System::System\n");
               }

float System::GetImageScale(){
    printf("Return image scale\n");
}
}