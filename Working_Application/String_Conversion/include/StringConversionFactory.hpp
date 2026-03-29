#ifndef STRINGCONVERSIONFACTORY_HPP
#define STRINGCONVERSIONFACTORY_HPP

#include <memory>
#include "IStringConversion.hpp"

/**
 * @enum ConversionType
 * @brief Defines types of string conversions available.
 */
enum class ConversionType {
    Lower,      /**< Converts string to lowercase */
    Upper,      /**< Converts string to uppercase */
    Capitalize, /**< Capitalizes the first letter of each word */
    Sentence,   /**< Converts string to sentence case */
    Toggle,      /**< Toggles the case of each character */
    Alternating  /**< Alternates the case of each character */
};

/**
 * @class StringConversionFactory
 * @brief Factory class for creating string conversion strategies.
 *
 * This class provides a single static method `create` which returns
 * a unique pointer to an IStringConversion object corresponding
 * to the requested ConversionType.
 *
 * Usage example:
 * @code
 * auto conv = StringConversionFactory::create(ConversionType::Upper);
 * std::string result = conv->convert("hello");
 * // result == "HELLO"
 * @endcode
 */
class StringConversionFactory {
public:
    /**
     * @brief Creates a string conversion object based on ConversionType.
     * @param type The type of conversion to create.
     * @return std::unique_ptr<IStringConversion> Pointer to the conversion object.
     *         Returns nullptr if the type is invalid.
     */
    static std::unique_ptr<IStringConversion> create(ConversionType type);
};

#endif // STRINGCONVERSIONFACTORY_HPP