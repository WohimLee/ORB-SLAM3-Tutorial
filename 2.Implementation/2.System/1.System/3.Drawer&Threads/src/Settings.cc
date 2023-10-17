
#include "Settings.h"
#include "System.h"

#include <opencv2/core/persistence.hpp>
#include <opencv2/core/eigen.hpp>

#include <iostream>

using namespace std;

namespace ORB_SLAM3 {

    Settings::Settings(const std::string &configFile, const int& sensor) :
    bNeedToUndistort_(false), bNeedToRectify_(false), bNeedToResize1_(false), bNeedToResize2_(false) {
        sensor_ = sensor;

        //Open settings file
        cv::FileStorage fSettings(configFile, cv::FileStorage::READ);
        if (!fSettings.isOpened()) {
            cerr << "[ERROR]: could not open configuration file at: " << configFile << endl;
            cerr << "Aborting..." << endl;

            exit(-1);
        }
        else{
            cout << "Loading settings from " << configFile << endl;
        }

        //Read first camera
        readCamera1(fSettings);
        cout << "\t-Loaded camera 1" << endl;

        //Read second camera if stereo (not rectified)
        if(sensor_ == System::STEREO || sensor_ == System::IMU_STEREO){
            readCamera2(fSettings);
            cout << "\t-Loaded camera 2" << endl;
        }

        //Read image info
        readImageInfo(fSettings);
        cout << "\t-Loaded image info" << endl;

        if(sensor_ == System::IMU_MONOCULAR || sensor_ == System::IMU_STEREO || sensor_ == System::IMU_RGBD){
            readIMU(fSettings);
            cout << "\t-Loaded IMU calibration" << endl;
        }

        if(sensor_ == System::RGBD || sensor_ == System::IMU_RGBD){
            readRGBD(fSettings);
            cout << "\t-Loaded RGB-D calibration" << endl;
        }

        readORB(fSettings);
        cout << "\t-Loaded ORB settings" << endl;
        readViewer(fSettings);
        cout << "\t-Loaded viewer settings" << endl;
        readLoadAndSave(fSettings);
        cout << "\t-Loaded Atlas settings" << endl;
        readOtherParameters(fSettings);
        cout << "\t-Loaded misc parameters" << endl;

        if(bNeedToRectify_){
            precomputeRectificationMaps();
            cout << "\t-Computed rectification maps" << endl;
        }

        cout << "----------------------------------" << endl;
    }

    void Settings::readCamera1(cv::FileStorage &fSettings) {
        
    }

    void Settings::readCamera2(cv::FileStorage &fSettings) {

    }

    void Settings::readImageInfo(cv::FileStorage &fSettings) {
    
    }

    void Settings::readIMU(cv::FileStorage &fSettings) {
    
    }

    void Settings::readRGBD(cv::FileStorage& fSettings) {
    
    }

    void Settings::readORB(cv::FileStorage &fSettings) {
    
    }

    void Settings::readViewer(cv::FileStorage &fSettings) {

    }

    void Settings::readLoadAndSave(cv::FileStorage &fSettings) {
    
    }

    void Settings::readOtherParameters(cv::FileStorage& fSettings) {
    
    }

    void Settings::precomputeRectificationMaps() {
    
    }

    ostream &operator<<(std::ostream& output, const Settings& settings){
    
    }
};
