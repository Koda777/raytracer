/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Factory
*/

#pragma once
#include <memory>

/**
 * @brief A factory interface that creates instances of a generic type T.
 *
 * This interface provides a create() method that returns a unique pointer to a new instance of type T.
 */
template <typename T>
class IFactory
{
    public:
        /**
         * @brief Destructor.
         */
        virtual ~IFactory() = default;

        /**
         * @brief Creates a new instance of type T.
         *
         * @param name The name of the instance to create.
         * @return A unique pointer to the new instance of type T.
         */
        virtual std::unique_ptr<T> create(const std::string &name) = 0;
};
