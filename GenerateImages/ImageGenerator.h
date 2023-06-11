#ifndef IMAGEGENERATOR_H
#define IMAGEGENERATOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <direct.h>
#include <io.h>

class ImageGenerator
{
public:
    std::vector<unsigned short> ReadImageFile(const std::string& filename, int imageSize);
    void WriteImageFile(const std::string& filename, const std::vector<unsigned short>& image);
    std::vector<unsigned short> GenerateDifferenceImage(const std::vector<unsigned short>& image1, const std::vector<unsigned short>& image2);
    bool DirectoryExists(const std::string& path);
    void CreateDirectory(const std::string& path);
    void SaveGeneratedImage(const std::string& filename, const std::vector<unsigned short>& image);
};

#endif  // IMAGEGENERATOR_H
