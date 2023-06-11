#include "ImageGenerator.h"
#include <iostream>
#include <string>
#include <limits>

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

bool IsValidResponse(const std::string& response)
{
    return (response == "Y" || response == "N");
}

char GetRepeatResponse()
{
    std::string userInput;
    bool validInput = false;

    while (!validInput)
    {
        std::cout << "Do you want to repeat the program? (Y/N): ";
        std::cin >> userInput;

        if (IsValidResponse(userInput))
        {
            validInput = true;
        }
        else
        {
            std::cout << "Invalid response. Please enter 'Y' to repeat or 'N' to exit." << std::endl;
        }

        // Clear the input stream
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return userInput[0];
}

int main()
{
    char repeatProgram ='Y';

    while (repeatProgram == 'Y')
    {
        ImageGenerator imageGenerator;
        std::string imageFile1 = "../Resources/template.raw";
        std::string imageFile2 = "../Resources/sino800_540x1200 (1).raw";
        std::string differenceImageFile;
        int imageSize = 540 * 1200;
        int imageCount;
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

            // Clear the input stream
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 1; i <= imageCount; ++i)
        {
            differenceImageFile = "ImageGenerate" + std::to_string(i) + ".raw";

            std::vector<unsigned short> image1 = imageGenerator.ReadImageFile(imageFile1, imageSize);
            std::vector<unsigned short> image2 = imageGenerator.ReadImageFile(imageFile2, imageSize);

            std::vector<unsigned short> differenceImage = imageGenerator.GenerateDifferenceImage(image1, image2);

            imageGenerator.SaveGeneratedImage(differenceImageFile, differenceImage);

            std::cout << "Difference image " << i << " generated successfully." << std::endl;
        }

        repeatProgram = GetRepeatResponse();
    }

    return 0;
}
