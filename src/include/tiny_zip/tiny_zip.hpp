//
//  tiny_zip.hpp
//  crossme
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 27.08.2025.
//  Copyright © 2025 Dmitrii Torkhov. All rights reserved.
//

#pragma once

#include <string>

namespace dtor::tiny_zip {
    std::string encode(const std::string &data);
    std::string decode(const std::string &data);
} // namespace dtor::tiny_zip
