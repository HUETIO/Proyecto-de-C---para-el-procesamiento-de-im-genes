#include "ImageGenerator.h"
#include <iostream>

int main()
{
    ImageGenerator imageGenerator;
    std::string imageFile1 = "../Resources/sino801_540x1200 (1).raw";
    std::string imageFile2 = "../Resources/sino800_540x1200 (1).raw";
    std::string differenceImageFile;

    int imageSize = 540 * 1200;
    int imageCount;

    std::cout << "Enter the number of images to generate (up to 5): ";
    std::cin >> imageCount;

    if (imageCount < 1 || imageCount > 5)
    {
        std::cout << "Invalid image count. Please enter a number between 1 and 5." << std::endl;
        return 1;
    }

    for (int i = 1; i <= imageCount; ++i)
    {
        differenceImageFile = "ImageGenerate" + std::to_string(i) + ".raw";

        // Leer las dos imágenes de entrada
        std::vector<unsigned short> image1 = imageGenerator.ReadImageFile(imageFile1, imageSize);
        std::vector<unsigned short> image2 = imageGenerator.ReadImageFile(imageFile2, imageSize);

        // Generar la imagen de diferencia
        std::vector<unsigned short> differenceImage = imageGenerator.GenerateDifferenceImage(image1, image2);

        // Guardar la imagen de diferencia en un archivo
        imageGenerator.SaveGeneratedImage(differenceImageFile, differenceImage);

        std::cout << "Difference image " << i << " generated successfully." << std::endl;
    }

    return 0;
}