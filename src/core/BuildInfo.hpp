#pragma once

namespace core {

struct BuildInfo {
    static const char* const project_name;
    static const char* const version;
    static const char* const git_hash;
    static const char* const build_date;
    static const char* const build_time;
};

} // namespace core
