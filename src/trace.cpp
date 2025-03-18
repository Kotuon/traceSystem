/**
 * 
 * @file trace.cpp
 * @author Kelson Wysocki (kelson.wysocki@gmail.com)
 * @brief 
 * @date 2025-03-18
 * 
 */

// std includes //
#include <iostream>
#include <cstdarg>

#include "trace.hpp"

/**
 * @brief Construct a new Trace:: Trace object
 * 
 */
Trace::Trace() {
    traceStream.open( "trace.log", std::ofstream::out );
    if ( !traceStream ) std::cout << "Trace file wasn't opened successfully.\n";

    std::source_location Src = std::source_location::current();
    std::cout << "trace.cpp" << "( " << std::to_string( Src.line() ) << ":"
              << std::to_string( Src.column() ) + " )" << ": "
              << "Trace file was opened successfully.\n";
}

/**
 * @brief Construct a new Trace:: Trace object
 * 
 * @param OutputFile 
 */
Trace::Trace( const std::string& OutputFile ) {
    traceStream.open( OutputFile, std::ofstream::out );
    if ( !traceStream ) std::cout << "Trace file wasn't opened successfully.\n";

    std::source_location Src = std::source_location::current();
    std::cout << "trace.cpp" << "( " << std::to_string( Src.line() ) << ":"
              << std::to_string( Src.column() ) + " )" << ": "
              << "Trace file was opened successfully.\n";
}

/**
 * @brief 
 * 
 * @param Message 
 * @param Src 
 */
void Trace::message( std::string Message, std::source_location Src ) {
    Trace& TraceInstance = Trace::getInstance();
    if ( !TraceInstance.traceStream ) return;

    std::string Filename = std::string( Src.file_name() );

    size_t startPos = Filename.find_last_of( '\\' );
    if ( startPos == std::string::npos ) startPos = 0;

    std::string output = Filename.substr( startPos + 1, std::string::npos ) +
                         "( " + std::to_string( Src.line() ) + ":" +
                         std::to_string( Src.column() ) + " )" + ": " + Message;

    TraceInstance.traceStream << output << "\n";
    std::cout << output << "\n";
}

Trace::~Trace() {
    if ( traceStream ) traceStream.close();
}
