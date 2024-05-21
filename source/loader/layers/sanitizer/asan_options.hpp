/*
 *
 * Copyright (C) 2024 Intel Corporation
 *
 * Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
 * See LICENSE.TXT
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 * @file asan_options.hpp
 *
 */

#pragma once

#include "common/ur_util.hpp"
#include "ur/ur.hpp"

#include <cstdint>

namespace ur_sanitizer_layer {

struct AsanOptions {
  public:
    AsanOptions(AsanOptions &other) = delete;
    void operator=(const AsanOptions &) = delete;

    static AsanOptions &getInstance() {
        static AsanOptions instance;
        return instance;
    }

    // We use "uint64_t" here because EnqueueWriteGlobal will fail when it's "uint32_t"
    uint64_t Debug = 0;
    uint32_t MaxQuarantineSizeMB = 0;
    bool DetectLocals = true;

  private:
    AsanOptions() {
        auto OptionsEnvMap = getenv_to_map("UR_LAYER_ASAN_OPTIONS");
        if (!OptionsEnvMap.has_value()) {
            return;
        }

        auto KV = OptionsEnvMap->find("debug");
        if (KV != OptionsEnvMap->end()) {
            auto Value = KV->second.front();
            Debug = Value == "1" || Value == "true" ? 1 : 0;
        }

        KV = OptionsEnvMap->find("quarantine_size_mb");
        if (KV != OptionsEnvMap->end()) {
            auto Value = KV->second.front();
            try {
                MaxQuarantineSizeMB = std::stoul(Value);
            } catch (...) {
                die("<SANITIZER>[ERROR]: \"quarantine_size_mb\" should be "
                    "an positive integer");
            }
        }

        KV = OptionsEnvMap->find("detect_locals");
        if (KV != OptionsEnvMap->end()) {
            auto Value = KV->second.front();
            DetectLocals = Value == "1" || Value == "true" ? true : false;
        }
    }
};

inline AsanOptions &Options() { return AsanOptions::getInstance(); }

} // namespace ur_sanitizer_layer
