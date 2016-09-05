// The MIT License (MIT)
//
// Copyright (c) 2016 THINK BIG LABS SL
// Author: alvarolb@gmail.com (Alvaro Luis Bustamante)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef THINGER_WIFI101_H
#define THINGER_WIFI101_H

#include "ThingerWifi.h"

class ThingerWifi101 : public ThingerWifi {

public:
    ThingerWifi101(const char* user, const char* device, const char* device_credential, bool ssl = true) :
            ThingerWifi(user, device, device_credential), ssl_(ssl)
    {}

    ~ThingerWifi101(){

    }

protected:

    virtual bool connect_socket(){
        if(ssl_){
            return client_.connectSSL(THINGER_SERVER, THINGER_SSL_PORT);
        }else{
            return client_.connect(THINGER_SERVER, THINGER_PORT);
        }
    }

private:
    bool ssl_;
};

#endif