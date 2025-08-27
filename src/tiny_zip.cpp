//
//  tiny_zip.cpp
//  crossme
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 27.08.2025.
//  Copyright © 2025 Dmitrii Torkhov. All rights reserved.
//

#include "tiny_zip/tiny_zip.hpp"
#include <zlib.h>

std::string dtor::tiny_zip::encode(const std::string &data) {
    std::string compressed;

    z_stream zs;
    memset(&zs, 0, sizeof(zs));

    if (deflateInit(&zs, Z_BEST_COMPRESSION) != Z_OK) {
        return "";
    }

    zs.next_in = (Bytef *)data.data();
    zs.avail_in = uInt(data.size());

    int ret;
    char buffer[32768];
    do {
        zs.next_out = reinterpret_cast<Bytef *>(buffer);
        zs.avail_out = sizeof(buffer);

        ret = deflate(&zs, Z_FINISH);

        compressed.append(buffer, std::min(zs.total_out, zs.total_out - compressed.size()));
    } while (ret == Z_OK);

    deflateEnd(&zs);

    if (ret != Z_STREAM_END) {
        return "";
    }

    return compressed;
}

std::string dtor::tiny_zip::decode(const std::string &data) {
    if (data.empty()) {
        return "";
    }

    std::string decompressed;

    z_stream zs;
    memset(&zs, 0, sizeof(zs));

    if (inflateInit(&zs) != Z_OK) {
        return "";
    }

    zs.next_in = (Bytef *)data.data();
    zs.avail_in = uInt(data.size());

    int ret;
    char buffer[32768];

    do {
        zs.next_out = reinterpret_cast<Bytef *>(buffer);
        zs.avail_out = sizeof(buffer);

        ret = inflate(&zs, 0);

        decompressed.append(buffer, std::min(zs.total_out, zs.total_out - decompressed.size()));
    } while (ret == Z_OK);

    inflateEnd(&zs);

    if (ret != Z_STREAM_END) {
        return "";
    }

    return decompressed;
}
