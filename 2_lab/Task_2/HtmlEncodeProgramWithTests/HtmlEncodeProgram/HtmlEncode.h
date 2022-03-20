#pragma once
#include <string>
#include <iosfwd>

std::string HtmlEncode(const std::string& text);

void HtmlEncodeLines(std::istream& input, std::ostream& output);