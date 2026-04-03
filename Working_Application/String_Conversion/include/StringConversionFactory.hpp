/*********************************************************************/
/* $Header: StringConversionFactory.hpp                               */
/*                                                                   */
/* Copyright (c) 2016-2026 nitishhsinghh. All rights reserved.       */
/* This material may be reproduced for teaching and learning         */
/* purposes only. It is not to be used in industry or for            */
/* commercial purposes.                                              */
/*                                                                   */
/* File        - StringConversionFactory.hpp                           */
/*                                                                   */
/* Description - Factory class for creating string conversion        */
/*               strategy objects. Provides a static `create` method*/
/*               to instantiate an IStringConversion derived object  */
/*               based on the requested ConversionType.             */
/*                                                                   */
/* Notes       - Supports multiple conversion types:                 */
/*               Lower, Upper, Capitalize, Sentence, Toggle,         */
/*               Alternating, Reverse, RemoveVowels, RemoveSpaces,   */
/*               InvertWords, SnakeCase, KebabCase, LeetSpeak       */
/*                                                                   */
/* $Log: StringConversionFactory.hpp                                  */
/*********************************************************************/

#ifndef STRINGCONVERSIONFACTORY_HPP
#define STRINGCONVERSIONFACTORY_HPP

/*********************************************************************/
/* Dependencies                                                      */
/*********************************************************************/
#include <memory>
#include "IStringConversion.hpp"

/**
 * @enum ConversionType
 * @brief Defines types of string conversions available.
 */
enum class ConversionType {
    Lower,         /**< Converts string to lowercase */
    Upper,         /**< Converts string to uppercase */
    Capitalize,    /**< Capitalizes the first letter of each word */
    Sentence,      /**< Converts string to sentence case */
    Toggle,        /**< Toggles the case of each character */
    Alternating,   /**< Alternates the case of each character */
    Reverse,       /**< Reverses the string */
    RemoveVowels,  /**< Removes all vowels from the string */
    RemoveSpaces,  /**< Removes all spaces from the string */
    InvertWords,   /**< Inverts the order of characters in each word */     
    SnakeCase,     /**< Converts string to lower snake case */
    KebabCase,     /**< Converts string to kebab case */   
    LeetSpeak      /**< Converts string to leet speak */
};

/**
 * @class StringConversionFactory
 * @brief Factory class to create IStringConversion objects based on ConversionType.
 *
 * This class provides a single static method `create` which returns
 * a unique pointer to a string conversion object corresponding to
 * the requested ConversionType. If an invalid type is provided,
 * it returns nullptr.
 *
 * Example usage:
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