// GenerateImages.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "ImageGenerator.h"
#include <iostream>

int main()
{
    ImageGenerator imageGenerator;
    std::string imageFile1 = "../Resources/sino801_540x1200 (1).raw";
    std::string imageFile2 = "../Resources/sino800_540x1200 (1).raw";
    std::string differenceImageFile;

    int imageSize = 540 * 1200;
    int imageCount = 5; // Número de imágenes generadas

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


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
