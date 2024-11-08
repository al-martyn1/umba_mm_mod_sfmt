#pragma once

#include "umba/umba.h"
// 
#include "umba/simple_formatter.h"
//
#include "umba/string_char_writers.h"

namespace umba {


class StringSimpleFormatter : public SimpleFormatter
{

protected:

    StringCharWriter charWritter;

public:

    StringSimpleFormatter() : SimpleFormatter(&charWritter) {}

    StringSimpleFormatter(const StringSimpleFormatter &fmt)
    : SimpleFormatter(&charWritter)
    , charWritter(fmt.charWritter)
    {}

    StringSimpleFormatter& operator=(const StringSimpleFormatter &fmt)
    {
        if (&fmt==this)
            return *this;

        charWritter = fmt.charWritter;
        setCharWritter(&charWritter);
        return *this;
    }

    StringSimpleFormatter(StringSimpleFormatter &&fmt)
    : SimpleFormatter()
    , charWritter(std::move(fmt.charWritter))
    {
        setCharWritter(&charWritter);
    }

    StringSimpleFormatter& operator=(StringSimpleFormatter &&fmt)
    {
        if (&fmt==this)
            return *this;

        charWritter = std::move(fmt.charWritter);
        setCharWritter(&charWritter);
        return *this;
    }


    //! Совместимый по интерфейсу с std::stringstream метод, возвращающий строку
    const std::string& str() const
    {
        return charWritter.str();
    }
     
    //! Возвращает ASCII-Z указатель на строку. Совместимый по интерфейсу с std::string метод
    const std::string::value_type* c_str() const
    {
        return charWritter.c_str();
    }
     
    //! Возвращает указатель на данные строки (без гарантии замершающего нуля). Совместимый по интерфейсу с std::string метод
    const std::string::value_type* data() const
    {
        return charWritter.data();
    }
     
    //! Возвращает размер строки. Совместимый по интерфейсу с std::string метод
    std::string::size_type size() const
    {
        return charWritter.size();
    }
     
    //! Возвращает true для пустой строки. Совместимый по интерфейсу с std::string метод
    bool empty() const
    {
        return charWritter.empty();
    }

    template<typename OutputType>
    StringSimpleFormatter& operator<<(const OutputType &o)
    {
        SimpleFormatter &stream = *this;
        stream << o;
        return *this;
    }


}; // class StringSimpleFormatter






} // namespace umba


