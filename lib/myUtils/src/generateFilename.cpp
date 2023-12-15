/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** generateFilename
*/

#include <ctime>
#include <filesystem>
#include <iomanip>
#include <string>

std::string generateUniqueFilename(const std::string &extension, const std::string &directoryPath = "")
{
    std::time_t now = std::time(nullptr);
    std::tm tm = *std::localtime(&now);

    if (!std::filesystem::is_directory(directoryPath))
        std::filesystem::create_directory(directoryPath);

    std::stringstream ss;
    ss << directoryPath;
    ss << "screenshot_";
    ss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");
    ss << extension.c_str();
    return ss.str();
}
