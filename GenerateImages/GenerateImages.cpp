#include "ImageGenerator.h"
#include <iostream>
#include <limits> // Para utilizar std::numeric_limits

bool IsInteger(const std::string& str)
{
    for (char c : str)
    {
        if (!std::isdigit(c))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ImageGenerator imageGenerator;
    // ruta de las imagenes aqui:
    std::string imageFile1 = "../Resources/sino801_540x1200 (1).raw";
    std::string imageFile2 = "../Resources/sino800_540x1200 (1).raw";
    std::string differenceImageFile;
    // ajustar tamano aqui:
    int imageSize = 540 * 1200;
    int imageCount;
    // metodo validacion entrada
    std::string userInput;
    bool validInput = false;

    while (!validInput)
    {
        std::cout << "Enter the number of images to generate (up to 5): ";
        std::cin >> userInput;

        if (IsInteger(userInput))
        {
            imageCount = std::stoi(userInput);
            if (imageCount >= 1 && imageCount <= 5)
            {
                validInput = true;
            }
        }

        if (!validInput)
        {
            std::cout << "Invalid input. Please enter a valid integer number between 1 and 5." << std::endl;
        }

        // Limpiar el estado del flujo de entrada y descartar cualquier entrada no válida
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
