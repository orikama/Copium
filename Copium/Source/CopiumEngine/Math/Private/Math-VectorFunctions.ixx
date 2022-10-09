// !!! GENERATED BY MathTool !!!
export module CopiumEngine.Math:VectorFunctions;

import :Constants;
import :Float2;
import :Float3;
import :Float4;
import :Functions;
import :Int2;
import CopiumEngine.Core.CoreTypes;

import <cmath>;
import <utility>;


export namespace Copium::Math
{

    [[nodiscard]] constexpr Float2 Radians(Float2 degrees) noexcept { return degrees * k_DegreeToRadians; }
    [[nodiscard]] constexpr Float3 Radians(const Float3& degrees) noexcept { return degrees * k_DegreeToRadians; }
    [[nodiscard]] constexpr Float4 Radians(const Float4& degrees) noexcept { return degrees * k_DegreeToRadians; }

    [[nodiscard]] constexpr Float2 Degrees(Float2 radians) noexcept { return radians * k_RadiansToDegree; }
    [[nodiscard]] constexpr Float3 Degrees(const Float3& radians) noexcept { return radians * k_RadiansToDegree; }
    [[nodiscard]] constexpr Float4 Degrees(const Float4& radians) noexcept { return radians * k_RadiansToDegree; }

    // NOTE(v.matushkin): Seems like compilers can't use SVML intrinsics (https://godbolt.org/z/9fdT7f3Tq)

    [[nodiscard]] Float2 Sin(Float2 v) noexcept { return Float2(std::sinf(v.X), std::sinf(v.Y)); }
    [[nodiscard]] Float3 Sin(const Float3& v) noexcept { return Float3(std::sinf(v.X), std::sinf(v.Y), std::sinf(v.Z)); }
    [[nodiscard]] Float4 Sin(const Float4& v) noexcept { return Float4(std::sinf(v.X), std::sinf(v.Y), std::sinf(v.Z), std::sinf(v.W)); }

    [[nodiscard]] Float2 Cos(Float2 v) noexcept { return Float2(std::cosf(v.X), std::cosf(v.Y)); }
    [[nodiscard]] Float3 Cos(const Float3& v) noexcept { return Float3(std::cosf(v.X), std::cosf(v.Y), std::cosf(v.Z)); }
    [[nodiscard]] Float4 Cos(const Float4& v) noexcept { return Float4(std::cosf(v.X), std::cosf(v.Y), std::cosf(v.Z), std::cosf(v.W)); }

    [[nodiscard]] std::pair<Float2, Float2> SinCos(Float2 v) noexcept { return { Sin(v), Cos(v) }; }
    [[nodiscard]] std::pair<Float3, Float3> SinCos(const Float3& v) noexcept { return { Sin(v), Cos(v) }; }
    [[nodiscard]] std::pair<Float4, Float4> SinCos(const Float4& v) noexcept { return { Sin(v), Cos(v) }; }


    [[nodiscard]] constexpr int32 Dot(Int2 lhs, Int2 rhs) noexcept { return lhs.X * rhs.X + lhs.Y * rhs.Y; }
    [[nodiscard]] constexpr float32 Dot(Float2 lhs, Float2 rhs) noexcept { return lhs.X * rhs.X + lhs.Y * rhs.Y; }
    [[nodiscard]] constexpr float32 Dot(const Float3& lhs, const Float3& rhs) noexcept { return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z; }
    [[nodiscard]] constexpr float32 Dot(const Float4& lhs, const Float4& rhs) noexcept { return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z + lhs.W * rhs.W; }

    [[nodiscard]] constexpr Float3 Cross(const Float3& lhs, const Float3& rhs) noexcept
    {
        return Float3(lhs.Y * rhs.Z - lhs.Z * rhs.Y,
                      lhs.Z * rhs.X - lhs.X * rhs.Z,
                      lhs.X * rhs.Y - lhs.Y * rhs.X);
    }

} // export namespace Copium::Math
