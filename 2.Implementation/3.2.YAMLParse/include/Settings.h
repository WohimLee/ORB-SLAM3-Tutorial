#ifndef ORB_SLAM3_SETTINGS_H
#define ORB_SLAM3_SETTINGS_H

#include <string>

namespace ORB_SLAM3 {
    class Settings {
    public:
        enum CameraType {
            PinHole = 0,
            Rectified = 1,
            KannalaBrandt = 2
        };

        // Delete default constructor
        Settings() = delete;
        Settings(const std::string &configFile, const int& sensor);
        // Ostream operator overloading to dump settings to the terminal
        friend std::ostream &operator<<(std::ostream &output, const Settings &s);

        std::string atlasLoadFile() {return sLoadFrom_;}
        std::string atlasSaveFile() {return sSaveto_;}
    private:
        // Save & load maps
        std::string sLoadFrom_, sSaveto_;
    };
}

#endif // ORB_SLAM3_SETTINGS_H