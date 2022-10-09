// !!! GENERATED BY MathTool !!!
export module CopiumEngine.Math:Int2;

import CopiumEngine.Core.CoreTypes;


export namespace Copium
{

    struct Int2 final
    {
        int32 X;
        int32 Y;


        constexpr Int2() = default;
        constexpr Int2(const Int2& other) = default;

        explicit constexpr Int2(int32 scalar)
            : X(scalar)
            , Y(scalar)
        {}
        constexpr Int2(int32 x, int32 y)
            : X(x)
            , Y(y)
        {}

        //- Compound
        //-- Vector | Scalar
        constexpr Int2& operator+=(int32 rhs) { X += rhs; Y += rhs; return *this; }
        constexpr Int2& operator-=(int32 rhs) { X -= rhs; Y -= rhs; return *this; }
        constexpr Int2& operator*=(int32 rhs) { X *= rhs; Y *= rhs; return *this; }
        //-- Vector | Vector
        constexpr Int2& operator+=(Int2 rhs) { X += rhs.X; Y += rhs.Y; return *this; }
        constexpr Int2& operator-=(Int2 rhs) { X -= rhs.X; Y -= rhs.Y; return *this; }
        constexpr Int2& operator*=(Int2 rhs) { X *= rhs.X; Y *= rhs.Y; return *this; }

        //- Unary
        friend constexpr Int2 operator-(Int2 rhs) { return Int2(-rhs.X, -rhs.Y); }

        //- Binary
        //-- Vector | Scalar
        friend constexpr Int2 operator+(Int2 lhs, int32 rhs) { return Int2(lhs.X + rhs, lhs.Y + rhs); }
        friend constexpr Int2 operator-(Int2 lhs, int32 rhs) { return Int2(lhs.X - rhs, lhs.Y - rhs); }
        friend constexpr Int2 operator*(Int2 lhs, int32 rhs) { return Int2(lhs.X * rhs, lhs.Y * rhs); }
        //-- Scalar | Vector
        friend constexpr Int2 operator+(int32 lhs, Int2 rhs) { return Int2(lhs + rhs.X, lhs + rhs.Y); }
        friend constexpr Int2 operator-(int32 lhs, Int2 rhs) { return Int2(lhs - rhs.X, lhs - rhs.Y); }
        friend constexpr Int2 operator*(int32 lhs, Int2 rhs) { return Int2(lhs * rhs.X, lhs * rhs.Y); }
        //-- Vector | Vector
        friend constexpr Int2 operator+(Int2 lhs, Int2 rhs) { return Int2(lhs.X + rhs.X, lhs.Y + rhs.Y); }
        friend constexpr Int2 operator-(Int2 lhs, Int2 rhs) { return Int2(lhs.X - rhs.X, lhs.Y - rhs.Y); }
        friend constexpr Int2 operator*(Int2 lhs, Int2 rhs) { return Int2(lhs.X * rhs.X, lhs.Y * rhs.Y); }

        [[nodiscard]] static constexpr Int2 Zero() noexcept { return Int2(0); }
        [[nodiscard]] static constexpr Int2 One() noexcept { return Int2(1); }
    };

} // export namespace Copium