/**
 *
 * @file trace.hpp
 * @author Kelson Wysocki (kelson.wysocki@gmail.com)
 * @brief
 * @date 2025-03-17
 *
 */

#ifndef TRACE_HPP
#define TRACE_HPP
#pragma once

// std includes //
#include <string>
#include <fstream>
#include <source_location>

/**
 * @brief Allows tracing messages. Sends them to a log file in folder with exe
 *        and to std::out. Includes file name and line trace message is from.
 *
 */
class Trace {
public:
    /**
     * @brief Prints a message into the output file including file name and line
     *        number.
     *
     * @param message Message to be printed
     * @param src Source location information (file name, line number, etc.)
     * @return void
     */
    static void
    message( std::string Message,
             std::source_location Src = std::source_location::current() );

    /**
     * @brief Destroy the Trace:: Trace object
     *
     */
    ~Trace();

private:
    /**
     * @brief Construct a new Trace:: Trace object
     *
     */
    Trace();

    /**
     * @brief Construct a new Trace object
     *
     * @param OutputFile
     */
    Trace( const std::string& OutputFile );

    /**
     * @brief Get the instance of trace
     *
     * @return Trace&
     */
    static Trace& getInstance() {
        static Trace traceInstance;
        return traceInstance;
    }

private:
    std::fstream traceStream; //!< Output file
};

#endif
