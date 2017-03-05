/*
Tag2Sub11.h
Preferred Symmetric Algorithms

Copyright (c) 2013 - 2017 Jason Lee @ calccrypto at gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef __TAG2_SUB11__
#define __TAG2_SUB11__

#include "../Encryptions/Encryptions.h"
#include "Tag2Subpacket.h"

// 5.2.3.7. Preferred Symmetric Algorithms
//
//    (array of one-octet values)
//
//    Symmetric algorithm numbers that indicate which algorithms the key
//    holder prefers to use. The subpacket body is an ordered list of
//    octets with the most preferred listed first. It is assumed that only
//    algorithms listed are supported by the recipient’s software.
//    Algorithm numbers are in Section 9. This is only found on a self-
//    signature.

class Tag2Sub11 : public Tag2Subpacket{
    private:
        std::string psa;

    public:
        typedef std::shared_ptr <Tag2Sub11> Ptr;

        Tag2Sub11();
        Tag2Sub11(const std::string & data);
        void read(const std::string & data);
        std::string show(const uint8_t indents = 0, const uint8_t indent_size = 4) const;
        std::string raw() const;

        std::string get_psa() const;  // string containing Symmetric Key Algorithm values (ex: "\x07\x08\x09")

        void set_psa(const std::string & s);

        Tag2Subpacket::Ptr clone() const;
};

#endif
