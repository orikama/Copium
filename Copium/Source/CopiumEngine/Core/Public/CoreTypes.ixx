module;

#include <cstdint>

export module CopiumEngine.Core.CoreTypes;


export namespace Copium
{

    using int8  = std::int8_t;
    using int16 = std::int16_t;
    using int32 = std::int32_t;
    using int64 = std::int64_t;

    using uint8  = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;

    using float32 = float;
    using float64 = double;

} // export namespace Copium


static_assert(sizeof(Copium::float32) == 4);
static_assert(sizeof(Copium::float64) == 8);
