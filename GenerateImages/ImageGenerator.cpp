#include "ImageGenerator.h"
std::vector<unsigned short> ImageGenerator::ReadImageFile(const std::string& filename, int imageSize)
{
    std::ifstream file(filename, std::ios::binary);
    std::vector<unsigned short> image(imageSize);

    if (file)
    {
        file.read(reinterpret_cast<char*>(image.data()), imageSize * sizeof(unsigned short));
        file.close();
    }
    else
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }

    return image;
}

void ImageGenerator::WriteImageFile(const std::string& filename, const std::vector<unsigned short>& image)
{
    std::ofstream file(filename, std::ios::binary);

    if (file)
    {
        file.write(reinterpret_cast<const char*>(image.data()), image.size() * sizeof(unsigned short));
        file.close();
    }
    else
    {
        std::cerr << "Failed to write file: " << filename << std::endl;
    }
}

std::vector<unsigned short> ImageGenerator::GenerateDifferenceImage(const std::vector<unsigned short>& image1, const std::vector<unsigned short>& image2)
{
    std::vector<unsigned short> differenceImage(image1.size());

    for (size_t i = 0; i < differenceImage.size(); ++i)
    {
        differenceImage[i] = image1[i] - image2[i];
    }

    return differenceImage;
}

bool ImageGenerator::DirectoryExists(const std::string& path)
{
    return _access(path.c_str(), 0) == 0;
}

void ImageGenerator::CreateDirectory(const std::string& path)
{
    _mkdir(path.c_str());
}

void ImageGenerator::SaveGeneratedImage(const std::string& filename, const std::vector<unsigned short>& image)
{
    std::string folderPath = "imagenes_generadas";

    // Comprobar si la carpeta existe, si no, crearla
    if (!DirectoryExists(folderPath))
    {
        CreateDirectory(folderPath);
    }

    // Combinar la ruta de la carpeta con el nombre del archivo
    std::string fullPath = folderPath + "/" + filename;

    // Guardar la imagen generada en la carpeta "imagenes_generadas"
    WriteImageFile(fullPath, image);
}