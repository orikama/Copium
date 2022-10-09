// !!! GENERATED BY MathTool !!!
export module CopiumEngine.Math:Float4;

import CopiumEngine.Core.CoreTypes;


export namespace Copium
{

    struct Float4 final
    {
        float32 X;
        float32 Y;
        float32 Z;
        float32 W;


        constexpr Float4() = default;
        constexpr Float4(const Float4& other) = default;

        explicit constexpr Float4(float32 scalar)
            : X(scalar)
            , Y(scalar)
            , Z(scalar)
            , W(scalar)
        {}
        constexpr Float4(float32 x, float32 y, float32 z, float32 w)
            : X(x)
            , Y(y)
            , Z(z)
            , W(w)
        {}

        //- Compound
        //-- Vector | Scalar
        constexpr Float4& operator+=(float32 rhs) { X += rhs; Y += rhs; Z += rhs; W += rhs; return *this; }
        constexpr Float4& operator-=(float32 rhs) { X -= rhs; Y -= rhs; Z -= rhs; W -= rhs; return *this; }
        constexpr Float4& operator*=(float32 rhs) { X *= rhs; Y *= rhs; Z *= rhs; W *= rhs; return *this; }
        //-- Vector | Vector
        constexpr Float4& operator+=(const Float4& rhs) { X += rhs.X; Y += rhs.Y; Z += rhs.Z; W += rhs.W; return *this; }
        constexpr Float4& operator-=(const Float4& rhs) { X -= rhs.X; Y -= rhs.Y; Z -= rhs.Z; W -= rhs.W; return *this; }
        constexpr Float4& operator*=(const Float4& rhs) { X *= rhs.X; Y *= rhs.Y; Z *= rhs.Z; W *= rhs.W; return *this; }

        //- Unary
        friend constexpr Float4 operator-(const Float4& rhs) { return Float4(-rhs.X, -rhs.Y, -rhs.Z, -rhs.W); }

        //- Binary
        //-- Vector | Scalar
        friend constexpr Float4 operator+(const Float4& lhs, float32 rhs) { return Float4(lhs.X + rhs, lhs.Y + rhs, lhs.Z + rhs, lhs.W + rhs); }
        friend constexpr Float4 operator-(const Float4& lhs, float32 rhs) { return Float4(lhs.X - rhs, lhs.Y - rhs, lhs.Z - rhs, lhs.W - rhs); }
        friend constexpr Float4 operator*(const Float4& lhs, float32 rhs) { return Float4(lhs.X * rhs, lhs.Y * rhs, lhs.Z * rhs, lhs.W * rhs); }
        //-- Scalar | Vector
        friend constexpr Float4 operator+(float32 lhs, const Float4& rhs) { return Float4(lhs + rhs.X, lhs + rhs.Y, lhs + rhs.Z, lhs + rhs.W); }
        friend constexpr Float4 operator-(float32 lhs, const Float4& rhs) { return Float4(lhs - rhs.X, lhs - rhs.Y, lhs - rhs.Z, lhs - rhs.W); }
        friend constexpr Float4 operator*(float32 lhs, const Float4& rhs) { return Float4(lhs * rhs.X, lhs * rhs.Y, lhs * rhs.Z, lhs * rhs.W); }
        //-- Vector | Vector
        friend constexpr Float4 operator+(const Float4& lhs, const Float4& rhs) { return Float4(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z, lhs.W + rhs.W); }
        friend constexpr Float4 operator-(const Float4& lhs, const Float4& rhs) { return Float4(lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z, lhs.W - rhs.W); }
        friend constexpr Float4 operator*(const Float4& lhs, const Float4& rhs) { return Float4(lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z, lhs.W * rhs.W); }

        [[nodiscard]] static constexpr Float4 Zero() noexcept { return Float4(0.0f); }
        [[nodiscard]] static constexpr Float4 One() noexcept { return Float4(1.0f); }
    };

} // export namespace Copium
